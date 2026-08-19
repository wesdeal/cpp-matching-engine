cmake_minimum_required(VERSION 3.23)

project(matching_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# must live in the top-level file so `ctest` works from the build root
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
