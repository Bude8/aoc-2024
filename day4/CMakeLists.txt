cmake_minimum_required(VERSION 3.31)
project(AoC2024)

enable_testing()

include(GoogleTest)

# Part 1
add_executable(d4p1.out d4p1.cpp)
add_executable(d4p1_tests.out d4p1_tests.cpp)
target_compile_definitions(d4p1_tests.out PRIVATE RUNNING_TESTS)
target_link_libraries(d4p1_tests.out gtest gtest_main pthread)
add_test(NAME d4p1_tests.out COMMAND d4p1_tests)

# # Part 2
# add_executable(d4p2.out d4p2.cpp)
# add_executable(d4p2_tests.out d4p2_tests.cpp)
# target_compile_definitions(d4p2_tests.out PRIVATE RUNNING_TESTS)
# target_link_libraries(d4p2_tests.out gtest gtest_main pthread)
# add_test(NAME d4p2_tests.out COMMAND d4p2_tests)
