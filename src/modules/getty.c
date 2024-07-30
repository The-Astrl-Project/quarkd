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
#include <unistd.h>
#include <sys/types.h>
// ---
#include "include/utils/panic.h"
#include "include/utils/logging.h"
#include "include/modules/getty.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// QuarkD || modules/getty.c <-> include/modules/getty.h
//
// Simple module responsible for launching a TTY. This
// *could* be a util but this is more of a QuarkD module
// then a generic utility.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
void launch_getty()
{
    // Fork the process
    pid_t pid = fork();

    // Check if child
    switch (pid)
    {
    case -1:
        // Log
        log_err("Unable to start GETTY process!");

        // Panic
        PANIC(-1);

        // Break
        break;
    case 0:
        // Log
        log_msg("Starting getty...");

        // Start a getty
        execlp("agetty", "agetty", "tty1", (char *)NULL);

        // Break
        break;
    default:
        // Log
        log_msg("Getty process forked");

        // Break
        break;
    }
}
