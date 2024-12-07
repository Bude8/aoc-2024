cmake_minimum_required(VERSION 3.31)
project(AoC2024)

enable_testing()

include(GoogleTest)

# Part 1
add_executable(d5p1.out d5p1.cpp)
add_executable(d5p1_tests.out d5p1_tests.cpp)
target_compile_definitions(d5p1_tests.out PRIVATE RUNNING_TESTS)
target_link_libraries(d5p1_tests.out gtest gtest_main pthread)
add_test(NAME d5p1_tests.out COMMAND d5p1_tests)

# # Part 2
# add_executable(d5p2.out d5p2.cpp)
# add_executable(d5p2_tests.out d5p2_tests.cpp)
# target_compile_definitions(d5p2_tests.out PRIVATE RUNNING_TESTS)
# target_link_libraries(d5p2_tests.out gtest gtest_main pthread)
# add_test(NAME d5p2_tests.out COMMAND d5p2_tests)
