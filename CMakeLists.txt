# This file was generated automatically by cmkr.

cmake_minimum_required(VERSION 3.15)

# Regenerate CMakeLists.txt automatically in the root project
set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr
	include("cmake/cmkr.cmake" OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# Create a configure-time dependency on cmake.toml to improve IDE support
if(CMKR_ROOT_PROJECT)
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

project(vcpkg_template)

include(FetchContent)

message(STATUS "Fetching pmm...")
FetchContent_Declare(
	pmm
	SOURCE_SUBDIR
		pmm
	URL
		https://github.com/vector-of-bool/pmm/archive/refs/tags/1.5.1.tar.gz
)
FetchContent_MakeAvailable(pmm)

# Bootstrap vcpkg
include("${pmm_SOURCE_DIR}/pmm.cmake")
pmm(
	VCPKG
		REVISION
			2020.11
		REQUIRES
			fmt
			sqlite3
)

# Packages
find_package(fmt REQUIRED CONFIG)

find_package(unofficial-sqlite3 REQUIRED CONFIG)

# Target example
set(example_SOURCES
	"src/example.cpp"
	cmake.toml
)

add_executable(example ${example_SOURCES})

get_directory_property(CMKR_VS_STARTUP_PROJECT DIRECTORY ${PROJECT_SOURCE_DIR} DEFINITION VS_STARTUP_PROJECT)
if(NOT CMKR_VS_STARTUP_PROJECT)
	set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT example)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${example_SOURCES})

target_link_libraries(example PRIVATE
	fmt::fmt
	unofficial::sqlite3::sqlite3
)

