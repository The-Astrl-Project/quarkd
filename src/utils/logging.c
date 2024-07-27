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
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
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
clock_t _internalLogClock;
int _consoleFileDescriptor;

// Main

// Methods
void logging_initialize()
{
    // Attempt to open /dev/console
    _consoleFileDescriptor = open(LOG_CONSOLE_PATH, O_WRONLY | O_NONBLOCK);

    // Capture the error value
    int err = errno;

    // Start internal clock
    _internalLogClock = clock();

    // Rudimentary error handling
    if (_consoleFileDescriptor < 0)
    {
        // Allocate a new message
        char message[64];

        // Format the new message
        sprintf(message, "Access to /dev/console was denied || Reason: %i", err);

        // Log the new message
        log_wrn(message);
    }
}

void log_msg(const char *message)
{
    // Get CPU timestamp
    double timestamp = (((double)(clock() - _internalLogClock)) / CLOCKS_PER_SEC);

    // Allocate a log message
    char log[LOG_MAX_LOG_SIZE];

    // Modify log message
    sprintf(log, "[ %s LOG %s @ %s %lf %s ] %s\n", LOG_MSG_COLOR, LOG_COLOR_RESET, LOG_TIME_COLOR, timestamp, LOG_COLOR_RESET, message);

    // Check we have a valid file descriptor
    if (_consoleFileDescriptor < 0)
    {
        // Print to stdout
        printf(log);

        // Return
        return;
    }

    // Write
    write(_consoleFileDescriptor, log, strlen(log));
}

void log_wrn(const char *message)
{
    // Get CPU timestamp
    double timestamp = (((double)(clock() - _internalLogClock)) / CLOCKS_PER_SEC);

    // Allocate a log message
    char log[LOG_MAX_LOG_SIZE];

    // Modify log message
    sprintf(log, "[ %s WRN %s @ %s %lf %s ] %s\n", LOG_WRN_COLOR, LOG_COLOR_RESET, LOG_TIME_COLOR, timestamp, LOG_COLOR_RESET, message);

    // Check we have a valid file descriptor
    if (_consoleFileDescriptor < 0)
    {
        // Print to stdout
        printf(log);

        // Return
        return;
    }

    // Write
    write(_consoleFileDescriptor, log, strlen(log));
}

void log_err(const char *message)
{
    // Get CPU timestamp
    double timestamp = (((double)(clock() - _internalLogClock)) / CLOCKS_PER_SEC);

    // Allocate a log message
    char log[LOG_MAX_LOG_SIZE];

    // Modify log message
    sprintf(log, "[ %s ERR %s @ %s %lf %s ] %s\n", LOG_ERR_COLOR, LOG_COLOR_RESET, LOG_TIME_COLOR, timestamp, LOG_COLOR_RESET, message);

    // Check we have a valid file descriptor
    if (_consoleFileDescriptor < 0)
    {
        // Print to stdout
        printf(log);

        // Return
        return;
    }

    // Write
    write(_consoleFileDescriptor, log, strlen(log));
}
