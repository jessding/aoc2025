cmake_minimum_required(VERSION 3.10)
project(3_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(3_2.tsk 3_2.cpp)

target_include_directories(3_2.tsk PRIVATE
    ${CMAKE_SOURCE_DIR}/../common
)
