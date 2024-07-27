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
#include <stdio.h>
#include <mntent.h>
#include <string.h>
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
struct mntent _foundEntires[MDL_MOUNT_MAX_FSTAB_ENTRIES];

// Main

// Methods
void mount_rootfs()
{
    // Read fstab
    _read_fstab();

    // Lookup UUIDs

    // Mount
}

void _read_fstab()
{
    // Open /etc/fstab
    FILE *fstabStream = setmntent(MDL_MOUNT_FSTAB_FILEPATH, "r");

    // Set buffer index
    int currentIndex = 0;

    // Iterate through the fstab
    struct mntent *entry;
    while (((entry = getmntent(fstabStream)) != NULL) && (currentIndex != MDL_MOUNT_MAX_FSTAB_ENTRIES))
    {
        // Add the entry
        _foundEntires[currentIndex] = *entry;

        // Increment
        currentIndex++;
    }

    // Log
    for (int i = 0; i < (sizeof(_foundEntires) / sizeof(struct mntent)); i++)
    {
        // Allocate message
        char msg[256];

        // Format message
        sprintf(msg, "Name: %s || Dir: %s", _foundEntires[i].mnt_fsname, _foundEntires[i].mnt_dir);

        // Log
        log_msg(msg);
    }
}
