#!/usr/bin/env bash
set -e

TASK="$1"
TASK_DIR="./$TASK"
BUILD_DIR="$TASK_DIR/build"
BIN="$BUILD_DIR/$TASK.tsk"
INPUT="${2:-$TASK/input.txt}"   # use second arg or default input.txt

# Build if missing
if [ ! -x "$BIN" ]; then
  echo "Building $TASK..."
  ./build.sh "$TASK"
fi

"$BIN" < "$INPUT"
