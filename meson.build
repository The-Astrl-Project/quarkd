# quarkd || meson.build
# --------------------------------
# Meson build configuration.
#
# Authors: @MaxineToTheStars <https://github.com/MaxineToTheStars>
# ----------------------------------------------------------------

# Project Declaration
project(
    'quarkd',
    'c',
    license: 'GPLv3',
    license_files: 'LICENSE',
    version: '0.1.0',
)

# Run the grabber.sh script to prase through /src and echo
# out all the *.c files found.
# NOTE: This is not recommended:
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
globber = run_command('bash', './scripts/grabber.sh', check: true)
source_files = globber.stdout().strip().replace('./', '').split('\n')

# Include the full include directory
include_directory = include_directories('include')

# Get a reference to the C compiler
clang = meson.get_compiler('c')

# Search for specific libraries
libmount = clang.find_library('libmount')

# Project Executable
executable('quarkd', source_files, include_directories: include_directory, dependencies: [libmount])
