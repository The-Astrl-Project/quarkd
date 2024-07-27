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
// ---
#include "include/init.h"
#include "include/utils/logging.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// QuarkD || init.c <-> include/init.h
//
// Entrypoint of QuarkD. All QuarkD subsystems are initialized here.
// This file simply works as an over-engineered "int main".
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main
int main(int argc, char **argv)
{
    // Instance the logging module
    logging_initialize();

    // Log some messages
    log_msg("Hello");
    log_msg("World");
    log_wrn("Sample Warning Message");
    log_err("Sample Error Message");

    // Stop from killing PID 1
    while (1)
    {
        // Sleep
        sleep(1);

        // Log
        log_wrn("Kernel Panic Imminent");
    }
}

// Methods
