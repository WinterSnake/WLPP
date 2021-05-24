## Project
project('WL', 'cpp', version: '0.0.1', default_options: ['cpp_std=c++17'])

## Window Library
lib_wl = library('wl', include_directories: './include')

## Tests
executable('wl-window', './tests/window.cpp', include_directories: './include')

## Subproject Dependency
dep_wl = declare_dependency(include_directories: './include', link_with: lib_wl)
