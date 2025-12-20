#!/usr/bin/env bash
set -e

if [ $# -ne 1 ]; then
  echo "Usage: $0 <task_name>"
  exit 1
fi

TASK="$1"
TASK_DIR="./$TASK"
BUILD_DIR="$TASK_DIR/build"

if [ ! -d "$TASK_DIR" ]; then
  echo "Error: directory '$TASK_DIR' does not exist."
  exit 1
fi

# Create build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Configure and build
cmake -S "$TASK_DIR" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR"
