#!/usr/bin/env bash

# Exit on any error
set -e

# Check argument count
if [ $# -ne 1 ]; then
  echo "Usage: $0 <name>"
  exit 1
fi

NAME="$1"
DIR="./$NAME"

# Fail if directory already exists
if [ -e "$DIR" ]; then
  echo "Error: '$DIR' already exists."
  exit 1
fi

# Create directory
mkdir "$DIR"

# Create empty input.txt
touch "$DIR/input.txt"

# Create cpp file with main stub
cat > "$DIR/$NAME.cpp" <<EOF
#include <input.h>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Input in; // wraps std::cin

    std::string line;
    while (std::getline(in.in, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
EOF

# Create CMakeLists file
cat > "$DIR/CMakeLists.txt" <<EOF
cmake_minimum_required(VERSION 3.10)
project($NAME LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable($NAME.tsk $NAME.cpp)

target_include_directories($NAME.tsk PRIVATE
    \${CMAKE_SOURCE_DIR}/../common
)
EOF

echo "Created directory '$NAME' with input.txt, $NAME.cpp, CMakeLists.txt"
