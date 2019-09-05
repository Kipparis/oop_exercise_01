project(srces)

add_library(money_lib STATIC money.cpp)
target_include_directories(money_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(prog main.cpp)
target_link_libraries(prog PRIVATE money_lib)
