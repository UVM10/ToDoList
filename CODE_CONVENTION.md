#1. Variable's and function's name
- Functions' name are actions(what does this function do) and verb must be at first. Funtions' name must be UPPER_SNAKE_CASE excepted `main` function
- Variables' name are noun and must be lower_snake_case. 
- Constants must be Pascal_Snake_Case. 
- Names must be clear and describe purposes.
- e.g:

```sh
#define Title_Length 33
#define Task_Amount 100

typedef struct
{
    char title[Title_Length];
}

ADD_TASK(task *task);

int main()
{
    task tasks[Task_Amount];
    ADD_TASK(tasks);
}
```  
#2. File structure
- Struct of a C file: comment, header file, preprocessor macros, struct, functions decleration, global variables, functions
-e.g:

```sh
#include<stdio.h>

#define Title_Length 33
#define Task_Amount 100

typedef struct
{
    char title[Title_Length];
};

ADD_TASK(task *task);
int main();

int current_index = 0;

int main()
{}

ADD_TASK(){}
```
#3. Comment
- Each C file and its functions must has comment at the top. 
    - C file: Purpose of this file
    - Function: What does it do? Which variables does it take in? Return which(optional)?
- Use `//` for single line nad `/* */` for multiple lines
- e.g:

```sh
// This file is main file of To-do list
#include<stdio.h>
#include<string.h>

#define Title_Length 33
#define Task_Amount 100

typedef struct
{
    char title[Title_Length];
};

int current_index = 0;

ADD_TASK(task *task);
int main();

int main()
{}

/* This function add a new task in list of task: 
   it takes in pointer to list of tasks and return `true` or `false` */
ADD_TASK(task *task){}
```
#4. Code formatting
- Braces on the next line (Allman style):

```sh
if (condition)
{
    do_something();
}
```

- Add a space after each comma in parameter lists:

```sh
void func(int a, int b);
```

- Indentation must be consistent throughout the code.

- Separate each function definition, each function declaration, and each global-variable declaration by one blank line.

