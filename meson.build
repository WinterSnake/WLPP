## Project
project('WL', 'cpp', version: '0.0.1', default_options: ['cpp_std=c++17'])

## Platform
platform = host_machine.system()

## Sources
deps = []
sources = ['./src/window.cpp']

# -Windows
# -MacOS
# -Linux - X11
if platform == 'linux'
	deps += dependency('x11')
	sources += './src/platform/linux/x11_window.cpp'
endif

## Window Library
lib_wl = library('wl', sources: sources, include_directories: './include', dependencies: deps)

## Tests
executable('wl-window', './tests/window.cpp', include_directories: './include', link_with: lib_wl)
executable('wl-keyboard', './tests/keyboard.cpp', include_directories: './include', link_with: lib_wl)
executable('wl-mouse', './tests/mouse.cpp', include_directories: './include', link_with: lib_wl)

## Subproject Dependency
dep_wl = declare_dependency(include_directories: './include', link_with: lib_wl)
