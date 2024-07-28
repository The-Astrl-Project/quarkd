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
    // Allocate a new filesystem table struct
    struct libmnt_table *table = mnt_new_table();

    // Parse the fstab file and load it into memory
    int err = mnt_table_parse_fstab(table, NULL);

    // Check for any parsing errors
    if (err < 0)
    {
        // Log
        log_wrn("Error while parsing /etc/fstab");

        // Exit
        PANIC(-1);
    }

    // Print out all found UUIDs
    struct libmnt_fs *entry;
    while ((entry = mnt_table_find_srcpath(table, "UUID", MNT_ITER_FORWARD)) != NULL)
    {
        // Print
        log_msg(mnt_fs_get_fstype(entry));
    }

    // Log
    log_msg("Done?");
}
