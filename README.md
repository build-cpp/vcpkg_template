[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/mrexodia/vcpkg_template)

# vcpkg_template

This is a template showcasing [cmkr](https://github.com/MoAlyousef/cmkr) together with [vcpkg](https://github.com/microsoft/vcpkg) for frictionless cross platform dependency management with CMake.

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
[project]
name = "vcpkg_template"

# See https://github.com/microsoft/vcpkg#getting-started on how to use vcpkg
[vcpkg]
# Chose a tag from https://github.com/microsoft/vcpkg/releases
version = "2020.11"
# During CMake configuration you will be told how to find and link to the packages
packages = ["fmt", "sqlite3"]

[find-package]
fmt = { version = "*" }
unofficial-sqlite3 = { version = "*" }

[target.example]
type = "executable"
sources = ["src/example.cpp"]
link-libraries = ["fmt::fmt", "unofficial::sqlite3::sqlite3"]
```
