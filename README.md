[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/from-referrer/)

# vcpkg_template

This is a template showcasing [cmkr](https://github.com/build-cpp/cmkr) together with [vcpkg](https://github.com/microsoft/vcpkg) for frictionless cross platform dependency management with CMake.

## Building (IDE)

Clone this repository and open it in your favorite IDE with CMake support (Visual Studio, CLion, Qt Creator). Everything should work out of the box.

## Building (command line)

```
cmake -Bbuild
```

Then open the `.sln` (Windows) or run `make` (Unix) from the `build` directory.

## cmake.toml

Under the hood cmkr generates the `CMakeLists.txt` required to build this project from the `cmake.toml` file:

```toml
[cmake]
version = "3.15"
cmkr-include = "cmake/cmkr.cmake"

[project]
name = "vcpkg_template"

# See https://vcpkg.io/en/packages.html for available packages
# Chose a version from https://github.com/microsoft/vcpkg/releases
[vcpkg]
version = "2021.05.12"
packages = ["fmt", "sqlite3"]

[find-package]
fmt = { version = "*" }
unofficial-sqlite3 = { version = "*" }

[target.example]
type = "executable"
sources = ["src/main.cpp"]
link-libraries = ["fmt::fmt", "unofficial::sqlite3::sqlite3"]
```
