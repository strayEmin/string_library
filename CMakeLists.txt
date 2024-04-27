cmake_minimum_required(VERSION 3.26)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c)


add_library(string string/string_library.h string/string_library.c
        string/tasks/tasks.h string/tasks/tasks.c)

target_link_libraries(project string)