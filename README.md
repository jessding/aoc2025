# AoC 2025 - Task Repository

---

## Folder Structure
```
├── common/ # Shared headers, e.g., Input wrapper
├── 1_1/ # Example task folder
│ ├── 1_1.cpp # Solution source file
│ ├── input.txt # Input file for the task
│ └── CMakeLists.txt # CMake build file
├── build.sh # Build script for any task
├── run.sh # Run script for any task with its input
├── setup.sh # Creates a new task folder skeleton
└── README.md
```


### `common/` folder

- Contains shared utilities and headers
- Currently includes `input.h` for fast, convenient input reading
- All task folders include headers from `../common` in their CMakeLists.txt

---

## Scripts

### `setup.sh <task_name>`

Creates a new task folder with the given name:

- `task_name/`
  - `task_name.cpp` → stub solution 
  - `input.txt` → empty placeholder for input
  - `CMakeLists.txt` → ready to build executable

**Usage:**
```bash
./setup.sh 1_2
```

### `build.sh <task_name>`

Builds the executable for a given task folder using CMake.

**Usage:**
```bash
./build.sh 1_2
```

Compiles 1_2.cpp into 1_2/build/1_2.tsk

### `run.sh <task_name> [input_file]`

Runs the compiled executable with its input file.

Default: uses task_name/input.txt
Optional: provide a different input file

**Usage:**
```bash
# Use default input
./run.sh 1_2

# Use a test input
./run.sh 1_2 1_2/test_input.txt
```

