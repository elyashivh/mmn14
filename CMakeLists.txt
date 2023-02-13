cmake_minimum_required(VERSION 3.23)
project(mmn14 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(mmn14
        assembler.c
        data.h
        firs_pass.h
        first_pass.c
        globals.h
        pre_assmbler.c
        sec_pass.c
        textProccesing.c)
