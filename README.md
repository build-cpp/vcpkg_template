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
[cmake]
version = "3.15"
cmkr-include = "cmake/cmkr.cmake"

[project]
name = "vcpkg_template"
include-after = ["cmake/vcpkg.cmake"]

[find-package]
fmt = { version = "*" }
unofficial-sqlite3 = { version = "*" }

[target.example]
type = "executable"
sources = ["src/example.cpp"]
link-libraries = ["fmt::fmt", "unofficial::sqlite3::sqlite3"]
```

In `vcpkg.json` you declare which packages you need:

```json
{
  "name": "vcpkg_template",
  "version": "0.0.1",
  "dependencies": ["fmt", "sqlite3"]
}
```

