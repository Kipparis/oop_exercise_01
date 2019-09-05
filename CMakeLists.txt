message("Entering CMake file\n")

cmake_minimum_required(VERSION 3.15.2)
project(oop_01)

# testing

include_directories(include)
include_directories(lib)

# find entry point
file(GLOB MAIN src/main.cpp)
# fond test file
file(GLOB TEST src/test*.cpp)
# find dec and def
file(GLOB SOURCES src/*.cpp)

add_executable(run ${SOURCES})
add_executable(test ${TEST_SOURCES})
