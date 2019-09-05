project(hello_tests)

# test program
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE money_lib catch)
