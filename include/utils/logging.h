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
#define LOG_COLOR_RESET "\033[0m"   // Clear/Reset
#define LOG_MSG_COLOR "\033[0;32m"  // Green
#define LOG_WRN_COLOR "\033[0;33m"  // Yellow
#define LOG_ERR_COLOR "\033[0;31m"  // Red
#define LOG_TIME_COLOR "\033[0;35m" // Magenta

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

// Main

// Methods
/**
 * Initializes the logging module.
 *
 * @return void
 */
void logging_initialize();

/**
 * Logs a formatted message.
 *
 * @param message The message to log
 * @return void
 */
void log_msg(const char *message);

/**
 * Logs a formatted warning message.
 *
 * @param message The message to log
 * @return void
 */
void log_wrn(const char *message);

/**
 * Logs a formatted error message.
 *
 * @param message The message to log
 * @return void
 */
void log_err(const char *message);
