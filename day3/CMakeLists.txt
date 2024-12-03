cmake_minimum_required(VERSION 3.31)
project(AoC2024)

# Enable testing
enable_testing()

include(GoogleTest)

# Add executables for solutions
add_executable(d3p1.out d3p1.cpp)
add_executable(d3p2.out d3p2.cpp)

# Add test executables
add_executable(d3p1_tests.out d3p1_tests.cpp)
add_executable(d3p2_tests.out d3p2_tests.cpp)

# Link GoogleTest to the test executables
target_compile_definitions(d3p1_tests.out PRIVATE RUNNING_TESTS)
target_compile_definitions(d3p2_tests.out PRIVATE RUNNING_TESTS)
target_link_libraries(d3p1_tests.out gtest gtest_main pthread)
target_link_libraries(d3p2_tests.out gtest gtest_main pthread)

# Register tests with CTest
add_test(NAME d3p1_tests.out COMMAND d3p1_tests)
add_test(NAME d3p2_tests.out COMMAND d3p2_tests)
