cmake_minimum_required(VERSION 3.20)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c solve-function.h solve-function.c tests.h tests.c handle_human_input.h handle_human_input.c output.h output.c constants.h)
