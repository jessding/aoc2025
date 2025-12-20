cmake_minimum_required(VERSION 3.10)
project(1_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1_2.tsk 1_2.cpp)

target_include_directories(1_2.tsk PRIVATE
    ${CMAKE_SOURCE_DIR}/../common
)
