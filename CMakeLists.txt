cmake_minimum_required(VERSION 3.14)

project(maze)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -Wextra -Wpedantic")

set(SOURCE_LIST
    src/main.cpp 
    src/maze_solving.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCE_LIST}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

target_include_directories(${PROJECT_NAME} PRIVATE inc)
add_executable(maze-tests src/tests.cpp src/maze_solving.cpp)
target_link_libraries(maze-tests gtest_main)
target_include_directories(maze-tests PRIVATE inc)

