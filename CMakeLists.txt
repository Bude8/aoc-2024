cmake_minimum_required(VERSION 3.31)
project(AoC2024)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)

# Include GoogleTest
add_subdirectory(googletest)

# Add dayN directories
add_subdirectory(day1)
add_subdirectory(day2)

