cmake_minimum_required(VERSION 3.26)
project(str C)

set(CMAKE_C_STANDARD 11)

add_executable(str main.c
        string/string_library.c
        string/string_library.h)
