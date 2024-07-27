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

// ---

// ---

// ----------------------------------------------------------------

// Macro Definitions
#define MDL_MOUNT_FSTAB_FILEPATH "/etc/fstab"
#define MDL_MOUNT_MAX_FSTAB_ENTRIES 16

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
/**
 * Mounts the root filesystem as defined in /etc/fstab.
 *
 * @return void
 */
void mount_rootfs();

/**
 * Reads the fstab file and stores the
 * found entries.
 *
 * @return void
 */
void _read_fstab();
