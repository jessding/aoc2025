cmake_minimum_required(VERSION 3.10)

project(task_1_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1_1.tsk 1_1.cpp)

target_include_directories(1_1.tsk PRIVATE
    ${CMAKE_SOURCE_DIR}/../common
)