# cmake system name
#set(CMAKE_SYSTEM_NAME Win64)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# set paths as variable
set(toolchainpath C:/MinGW)

# configure compilers
set(CMAKE_C_COMPILER ${toolchainpath}/bin/gcc.exe)

# compiler flags
#set(CMAKE_SYSROOT ${toolchainpath})
set(CMAKE_<LANG>_STANDARD_INCLUDE_DIRECTORIES ${toolchainpath}/lib/gcc/mingw32/9.2.0/include ${toolchainpath}/lib/gcc/mingw32/9.2.0/include/c++ ${toolchainpath}/bin)
#set(CMAKE_<LANG>_FLAGS "-Wall -fmessage-length=0")
#set(CMAKE_<LANG>_FLAGS_DEBUG "-O0 -g3")
#set(CMAKE_<LANG>_FLAGS_RELEASE "-O3")

# specify search behaviour
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# project specific information
cmake_minimum_required(VERSION 3.17)
project(getDirContent)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)
add_library(getDirContent SHARED
#add_executable(getDirContent WIN32
../src/getDirContent.c
../src/getDirContent.h)
target_sources(getDirContent PRIVATE 
../src/getDirContent.c)