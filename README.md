# vcpkg_template

This is a template showcasing [cmkr](https://github.com/build-cpp/cmkr) together with [vcpkg](https://github.com/microsoft/vcpkg) for frictionless cross platform dependency management with CMake.

## Building (Visual Studio Code)

1. Open this directory
2. Install the suggested extensions
3. Ctrl+Shift+P => CMake: Configure

## Building (Visual Studio Code WSL)

1. Open this directory in WSL
2. Run `code .`
3. Install the suggested extensions
4. Ctrl+Shift+P => CMake: Configure

## cmake.toml

Under the hood cmkr generates the `CMakeLists.txt` required to build this project from the `cmake.toml` file:

```toml
[project]
name = "vcpkg_template"

# See https://github.com/microsoft/vcpkg#getting-started on how to use vcpkg
# Chose a version from https://github.com/microsoft/vcpkg/releases
# During CMake configuration you will be told how to find and link to the packages
[vcpkg]
version = "2020.11"
packages = ["fmt", "sqlite3"]

[find-package]
fmt = { version = "*" }
unofficial-sqlite3 = { version = "*" }

[target.example]
type = "executable"
sources = ["src/example.cpp"]
link-libraries = ["fmt::fmt", "unofficial::sqlite3::sqlite3"]
```
