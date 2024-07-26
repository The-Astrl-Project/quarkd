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
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
// ---
#include "include/utils/logging.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// QuarkD || logging.c <-> include/utils/logging.h
//
// Logs messages to /dev/console.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions
int _consoleFileDescriptor;

// Main

// Methods
void logging_initialize()
{
    // Attempt to open /dev/console
    _consoleFileDescriptor = open("/dev/console", O_WRONLY | O_NONBLOCK);

    // TODO: Maybe error handling?
    return;
}

void log_msg(const char *message)
{
    // Check we have a valid file descriptor
    if (_consoleFileDescriptor < 0)
    {
        // Early return
        return;
    }

    // Write
    write(_consoleFileDescriptor, message, strlen(message));
}
