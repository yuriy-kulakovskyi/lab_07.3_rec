cmake_minimum_required(VERSION 3.14)
project(PR7_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)

add_executable(PR7_3
        src/h.cpp
        src/main.cpp
)

add_executable(PR7_3_tests
        src/h.cpp
        tests/test_h.cpp
)

target_link_libraries(PR7_3_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR7_3_tests)