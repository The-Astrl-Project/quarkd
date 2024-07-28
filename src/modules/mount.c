/**
 * Copyright (c) 2024 Astrl.
 *
 * This file is part of QuarkD. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this project and at
 * https://github.com/The-Astrl-Project/quarkd/blob/HEAD/LICENSE.
 *
 * This file may not be copied, modified, propagated, or distributed
 * except according to the terms contained in the LICENSE file.
 */

// Header Declarations
// ----------------------------------------------------------------
#include <libmount/libmount.h>
// ---
#include "include/utils/panic.h"
#include "include/utils/logging.h"
#include "include/modules/mount.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// QuarkD || modules/mount.c <-> include/modules/mount.h
//
// Handles the mounting of the root filesystem and other
// mounting related tasks.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
void mount_rootfs()
{
    // Parse the fstab file
    _parse_fstab();

    // Map UUIDs to device blocks

    // Mount devices
}

void _parse_fstab()
{
    // Function scope error placeholder
    int err;

    // Allocate a new filesystem table struct
    struct libmnt_table *table = mnt_new_table();

    // Allocate a new cache
    struct libmnt_cache *tableCache = mnt_new_cache();

    // Allocate a new iterator
    struct libmnt_iter *tableIterator = mnt_new_iter(MNT_ITER_FORWARD);

    // Set the cache reference
    err = mnt_table_set_cache(table, tableCache);

    // Check for any allocation errors
    if (err < 0 || tableCache == NULL)
    {
        // Log
        log_err("Error while setting fstab cache || Possible limited RAM situation?");

        // Panic
        PANIC(-1);
    }

    // Parse the fstab file and load it into memory
    err = mnt_table_parse_fstab(table, MOD_MOUNT_FSTAB_FILEPATH);

    // Check for any parsing errors
    if (err < 0)
    {
        // Log
        log_err("Error while parsing /etc/fstab || Possible malformed /etc/fstab?");

        // Exit
        PANIC(-1);
    }

    // Print it out all found UUIDs
    struct libmnt_fs *entry;
    while (mnt_table_next_fs(table, tableIterator, &entry) == 0)
    {
        // Allocate NAME and VALUE placeholders
        const char *tag, *value;

        // Get the tag and value
        if (mnt_fs_get_tag(entry, &tag, &value) == 0)
        {
            // Next entry
            continue;
        }

        // Log
        log_msg(tag);
        log_msg(value);
    }

    // Clean up
    mnt_unref_table(table);
    mnt_unref_cache(tableCache);
    mnt_free_iter(tableIterator);

    // Log
    log_msg("End");
}
