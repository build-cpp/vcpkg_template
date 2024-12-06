cmake_minimum_required(VERSION 3.15)
project(mylib)

include(GNUInstallDirs)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.hpp
)

add_library(mylib STATIC ${SOURCES})
target_include_directories(mylib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(WIN32)
    target_compile_definitions(mylib PRIVATE
        _CRT_SECURE_NO_WARNINGS
    )
endif()

install(
    TARGETS mylib
    EXPORT unofficial-mylib
)

install(
    EXPORT unofficial-mylib
    FILE unofficial-mylib-config.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/unofficial-mylib
    NAMESPACE unofficial::mylib::
)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/mylib
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
