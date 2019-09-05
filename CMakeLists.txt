message("Entering CMake file\n")

cmake_minimum_required(VERSION 3.15.2)
project(oop_01)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# testing

include_directories(include)

add_subdirectory(lib/catch2)
add_subdirectory(src)
add_subdirectory(test)






# include_directories(include)
# include_directories(lib/catch2)
#
# set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/catch2)
# add_library(Catch INTERFACE)
# target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# find entry point
# file(GLOB MAIN src/main.cpp)
# fond test file
# file(GLOB TEST test*.cpp)
# find dec and def
# file(GLOB SOURCES src/*.cpp)

# add_executable(run ${MAIN} ${SOURCES})
#
# add_executable(test_money ${SOURCES})
# target_link_libraries(test_money Catch)
#
# enable_testing()
# add_test(NAME MyAwecomeTest COMMAND test_money)

# add_executable(tests test.cpp ${SOURCES})
# target_link_libraries(tests PRIVATE catch)
