message("Entering CMake file\n")

cmake_minimum_required(VERSION 3.15.2)

# testing
add_subdirectory(lib/Catch2)
target_link_libraries(tests Catch2::Catch2)



project(oop_01)

add_executable(run main.cpp)
