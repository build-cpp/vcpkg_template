# vcpkg_template

This is a template showcasing [cmkr](https://github.com/build-cpp/cmkr) together with [vcpkg](https://github.com/microsoft/vcpkg) for frictionless cross platform dependency management with CMake.

## Building

Use the following commands to build the project:

```
cmake -B build
cmake --build build
```

## cmake.toml

Under the hood cmkr generates the `CMakeLists.txt` required to build this project from the `cmake.toml` file:

```toml
[project]
name = "vcpkg_template"

# See https://vcpkg.link for available packages
# Chose a version from https://github.com/microsoft/vcpkg/releases
[vcpkg]
version = "2024.11.16"
packages = [
    "fmt",
    "sqlite3",
    "mylib",
]
overlay = "vcpkg-overlay"

# Make the packages available to CMake
[find-package.fmt]
[find-package.unofficial-sqlite3]
[find-package.unofficial-mylib]

[target.example]
type = "executable"
sources = ["src/main.cpp"]
link-libraries = [
    "fmt::fmt",
    "unofficial::sqlite3::sqlite3",
    "unofficial::mylib::mylib",
]
```

## Vcpkg overlay

The `[vcpkg].overlay` key points to a local folder used as an overlay for vcpkg ports and triplets:

```sh
vcpkg-overlay
├── mylib              # custom port
│   ├── CMakeLists.txt
│   ├── portfile.cmake
│   ├── usage
│   └── vcpkg.json
└── x64-windows.cmake  # custom triplet
```

The `vcpkg-overlay/mylib` [overlay port](https://learn.microsoft.com/en-us/vcpkg/concepts/overlay-ports) is used to make the example [mylib](https://gitlab.com/mrexodia/mylib) available without having to fork the vcpkg repository or create a custom registry.

The `vcpkg-overlay/x64-windows.cmake` [overlay triplet](https://learn.microsoft.com/en-us/vcpkg/users/examples/overlay-triplets-linux-dynamic) is used to always build static libraries for Windows (instead of shared libraries, which is normally the default).
