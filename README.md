**TODOLIST**
---

## 1. Overview

- To-do list is a CLI program for managing tasks.
- Functions:
    - Add task
    - Delete task
    - Edit task
    - Search tasks by names
    - Sort tasks list by completion rate
- This program provide users a simple and light-weight tool for checking and  managing tasks.

---

## 2. Features

- Add task: You can create new task by entering name and completion rate.
- Delete task: Delete exiting task by entering ID.
- Edit task: Edit task’s name and completion rate.
- Search task: Search task by name.
- Sort tasks: Sort tasks by completion rate and display table of tasks.

![Function_Diagram.drawio.png](docs/Function_Diagram.drawio.png)

---

## 3. Getting Started

### 3.1. Prerequisites

- OS: Ubuntu (Tested successfully on version 24.04.2 LTS)
- git (Tested successfully on version 2.43.0)
- GCC (Tested successfully on version 13.3.0)

You can check if your computer has git and GCC by using:

```bash
git --version
gcc --version
```

Install them by using:

```bash
sudo apt install git build-essential -y
```

### 3.2. Quick Start

- Move to folder where you want clone the repository and clone the repository:
    
    ```bash
    git clone https://github.com/UVM10/ToDoList.git
    ```
    
- Move to *utils/* folder and use these command:
    - Allow using scripts in order:
        
        ```bash
        chmod +x build.sh clean.sh run.sh
        ```
        
    - Build program:
        
        ```bash
        ./build.sh
        ```
        
    - Run program:
        
        ```bash
        ./run.sh
        ```
        
    - Clean up files generated when build and run program:
        
        ```bash
        ./clean.sh
        ```
