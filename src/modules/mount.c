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
    // Allocate a new filesystem table
    struct libmnt_table *table = mnt_new_table_from_file(MOD_MOUNT_FSTAB_FILEPATH);

    // Search for a UUID entries
    struct libmnt_fs *currentEntry;
    while ((currentEntry = mnt_table_find_source(table, "UUID", MNT_ITER_FORWARD)) != NULL)
    {
        // Log the filesystem type
        log_msg(mnt_fs_get_fstype(currentEntry));
    }
}
