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

# Project Source

# NOTE: This is not recommended:
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
globber = run_command('bash', './scripts/grabber.sh', check: true)
source_files = globber.stdout().strip().replace('./', '').split('\n')

include_directory = include_directories('include')

# Project Executable
executable('quarkd', source_files, include_directories: include_directory)
