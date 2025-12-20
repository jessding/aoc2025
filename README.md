# AoC 2025 - Task Repository

---

## Folder Structure
```
├── common/ # Shared headers, e.g., Input wrapper
├── 1_1/
│ ├── 1_1.cpp 
│ ├── input.txt
│ └── CMakeLists.txt 
├── build.sh
├── run.sh 
├── setup.sh 
└── README.md
```


### `common/` folder
Contains shared utilities and headers. All task folders include headers from `../common` in their CMakeLists.txt

---

## Scripts

### `setup.sh <task_name>`

Creates a new task folder with the following structure:

- `task_name/`
  - `task_name.cpp` → stub solution 
  - `input.txt` → empty placeholder for input
  - `CMakeLists.txt` → ready to build executable

**Usage:**
```bash
./setup.sh 1_2
```

### `build.sh <task_name>`

**Usage:**
```bash
./build.sh 1_2
```
Compiles 1_2.cpp into 1_2/build/1_2.tsk

### `run.sh <task_name> [input_file]`

**Usage:**
```bash
# Use default input
./run.sh 1_2

# Use a test input
./run.sh 1_2 1_2/test_input.txt
```

