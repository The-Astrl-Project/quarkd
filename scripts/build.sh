# Copyright (c) 2024 Astrl.
#
# This file is part of QuarkD. It is subject to the license terms in
# the LICENSE file found in the top-level directory of this project and at
# https://github.com/The-Astrl-Project/quarkd/blob/HEAD/LICENSE.
#
# This file may not be copied, modified, propagated, or distributed
# except according to the terms contained in the LICENSE file.

# Shebang
#!/usr/bin/env bash

# Constants
declare -r POSSIBLE_OPTIONS=":ghcb"

# Main
function main()
{
    # Parse arguments
    while getopts ${POSSIBLE_OPTIONS} opt; do
        case ${opt} in
            g)
                # Show the license blurb
                blurb
            ;;
            h)
                # Show the help message
                help
            ;;
            c)
                # Clean build
                clean
            ;;
            b)
                # Build
                build
            ;;
            ?)
                # Invalid
                echo "Invalid argument!"
                echo

                # Show the help message
                help
            ;;
        esac
    done
}

# Functions
function blurb()
{
    echo
    echo "Copyright (c) 2024 Astrl."
    echo
    echo "This file is part of QuarkD. It is subject to the license terms in"
    echo "the LICENSE file found in the top-level directory of this project and at"
    echo "https://github.com/The-Astrl-Project/quarkd/blob/HEAD/LICENSE."
    echo
    echo "This file may not be copied, modified, propagated, or distributed"
    echo "except according to the terms contained in the LICENSE file."
    echo
}

function help()
{
    echo "Astrl: QuarkD Build Script - Provide utility functions for building QuarkD"
    echo
    echo "Syntax: build.sh [-g|h|c|b]"
    echo "options:"
    echo "g     Print the GPL license"
    echo "h     Print this help message"
    echo "c     Clean the build directory"
    echo "b     Build the project"
    echo
}

function clean()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Nuke
        rm -rf ./build > /dev/null 2>&1
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Build directory cleaned!"
}

function build()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Switch to ./build
        cd ./build

        # Compile
        meson compile

        # Exit
        exit
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Created build directory"

    # Re-run
    build
}

# Execute
main ${@}
