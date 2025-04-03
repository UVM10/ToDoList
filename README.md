TO-DO LIST PROGRAM
---

## 1. Overview

- To-do list is a CLI program for managing tasks.
- Functions:
    - Add task
    - Delete task
    - Edit task
    - Search tasks by names
    - Sort tasks list by completion rate
- This program provide users a simple and light-weight tool for checking and  tasks.

---

## 2. Features

- Add task: You can create new task by entering name and completion rate.
- Delete task: Delete exiting task by entering ID.
- Edit task: Edit task’s name and completion rate.
- Search task: Search task by name.
- Sort tasks: Sort tasks by completion rate and display table of tasks.

![task_flow_diagram](docs/BFD.drawio.png)

---

## 3. Getting Started

### 3.1. Prerequisites

- Your computer must be running version Windows 11.
- Requirements:
    - Ubuntu: An operating system bases on Linux’s kernel, you’ll need its terminal for program’s interface.
    - WSL (or WSL 2 if you want better performance): It allow you to run Ubuntu on Windows.
    - Git: It helps you clone the repository.
    - GCC: A popular compiler for running C program.
- If you don’t have any of them on your computer, follow this guide:
    - Ubuntu: Download from Microsoft Store
    
    - WSL:
        - Step 1:  Open PowerShell (available on Windows 7 or later) and use command:
            
            ```bash
            wsl --install
            ```
            
            Then, restart your computer. 
            
        - Step 2: Check your WSL version:
            
            ```bash
            wsl -l -v
            ```
            
    
    - Git: Install and check your Git’s version:
    
    ```bash
    sudo apt install git -y
    git --version
    ```
    
    You’re success if output is <git version x.x.x>.
    
    - GCC:
        
        ```bash
        sudo apt install gcc
        gcc --version
        ```
        
        You’re success if output include <gcc x.x.x>.
        

### 3.2. Quick Start

- Step 1: Move to folder where you want clone the repository and clone the repository:
    
    ```bash
    git clone https://github.com/UVM10/ToDoList.git
    ```
    
- Move to utils folder and use these command:
    - Compile program:
        
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
