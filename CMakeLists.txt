cmake_minimum_required(VERSION 3.23)

project(MyTop LANGUAGE C)
find_package(PkgConfig REQUIRED) 
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

find_package(Curses REQUIRED)

add_executable(MyTop)

target_sources(MyTop
    PRIVATE
    main.c
    mytop.c

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES include/procinfo.h
)

target_link_libraries(MyTop
    PRIVATE
        PkgConfig::UUID
        ${CURSES_LIBRARIES}
)

target_include_directories(MyTop PRIVATE ${CURSES_INCLUDE_DIR})
target_compile_options(MyTop PRIVATE -g -O0)