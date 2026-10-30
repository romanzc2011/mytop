cmake_minimum_required(VERSION 3.23)

project(MyTop LANGUAGES C)

# Find required libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

find_package(Curses REQUIRED)

# Source files
add_executable(MyTop
    mytop.c
    procinfo.c
    proc_linked_list.c
)

# Header directories
target_include_directories(MyTop
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CURSES_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(MyTop
    PRIVATE
        PkgConfig::UUID
        ${CURSES_LIBRARIES}
)

# Debug compiler flags
target_compile_options(MyTop
    PRIVATE
        -g
        -O0
)