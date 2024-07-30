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
#include <string.h>
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
    // Function scope errno placeholder
    int errno;

    // Instance a new filesystem table
    struct libmnt_table *table = mnt_new_table();

    // Instance a new mount context
    struct libmnt_context *context = mnt_new_context();

    // Instance a new iterator
    struct libmnt_iter *iterator = mnt_new_iter(MNT_ITER_FORWARD);

    // Parse the filesystem table and append new lines to the table pointer
    errno = mnt_table_parse_fstab(table, MOD_MOUNT_FSTAB_FILEPATH);

    // Check for parsing errors
    if (errno < 0)
    {
        // Log
        log_err("Failed to parse /etc/fstab!");

        // Panic
        PANIC(-1);
    }

    // Reset and set the internal fstab struct in the mount context
    if (mnt_context_set_fstab(context, NULL) < 0 || mnt_context_set_fstab(context, table) < 0)
    {
        // Log
        log_err("Failed to set mount context!");

        // Panic
        PANIC(-1);
    }

    // Mount all found filesystems
    int *mountReturnCode = NULL;
    struct libmnt_fs *entry = NULL;
    while (mnt_context_next_mount(context, iterator, &entry, mountReturnCode, NULL) == 0)
    {
        // Allocate a message buffer for logging
        char buf[256];

        // Retrieve drive name
        const char *driveName = mnt_fs_get_source(entry);

        // Check for mounting error
        if (mountReturnCode > 0)
        {
            // Format
            sprintf(buf, "Drive failed to mount (mount error) || %s", driveName);

            // Log
            log_err(buf);

            // Next entry
            continue;
        }

        // Check for miscellaneous errors
        if (mountReturnCode < 0)
        {
            // Format
            sprintf(buf, "Drive possibly failed to mount (other error) || %s", driveName);

            // Log
            log_wrn(buf);

            // Next entry
            continue;
        }

        // Format
        sprintf(buf, "Drive successfully mounted || %s", driveName);

        // Log
        log_msg(buf);
    }

    // Clean up
    mnt_unref_table(table);
    mnt_free_context(context);
    mnt_free_iter(iterator);
}
