# 1. Variable's and function's name
- Rules apply for all names: 
    + Using `snake_case` and variation. 
    + Names must be meaningful, not abbreviated
    + Maximum length of 20 characters. 
    + Main noun of name must come first.
 
- Function's name:
    + Using `Pascal_Snake_Case`.
    + Funtion's name must describe what it does.
    + Functions that do the main feature(s)(which is displayed on menu) must have `System` at first.
    + All rules for function's name don't apply on `main` function
- e.g:
```c
System_Task_Add();
System_Task_Show();
// this below function makea a table for display task, what is called in `System_Task_Show` function -> No `System`
Table_Make(); 
```

- Variable's name: 
    + Using `lower_snake_case`.
    + Variable's name must be noun or noun phrase and meaningful at least in its scope.
- e.g:
```c
int id_current = 0;

int main()
{
    int option; 
}
```
- Constant's name:
    + Using `UPPER_SNAKE_CASE`.
- e.g: 
```c
#define ID_LENGTH 8
#define TASK_AMOUNT 100
```

# 2. File structure
- Every `.c` file in workspace must follow this structure:
    1. Comment: Brief description about this file
    2. Standard system libraries 
    3. Header files
    4. Macros and constants
    5. User-defined data type: `struct`, `enum`, `union`
    6. Private function prototypes: prototypes of functions created in this file
    7. Global variables
    8. Public function definitions: definitions of function exported from header files
    9. Private function definition: definitions of function created in this file
- e.g:
```c
/* Brief description about this file
 * What does it do?
 */

// Standard system libraries
#include<stdio.h>
#include<stdlib.h>

// Header files
#include "library.h"
#include "task.h"

// Macros and constants
#define ID_LENGTH 8
#define TITLE_LENGTH 33

// User-defined data type
typedef struct
{
    char title[Title_Length];
    char id[Id_Length];
}task;

// Private function prototypes
System_Task_Add(task *task);
System_Task_Delete(task *task);

// Global variables
int index_current = 0;

// Public function definitions
System_Task_Sort() //This function is exported from header files
{}

// Private function definition
System_Task_Add(task *task)
{}
System_Task_Delete(task *task)
{}
```

# 3. Comment
There are some rules you must follow when using comments:
- Comments must be clear and not redundant.
- e.g:
```c
// count how many times each task appear. -> clear
int count = 0;  

// Set index_curent to 0 -> redundant
int index_curent = 0; 

// do somthing -> unclear
Process_Data();
```
- Using `// ...` to clarify complex logic non-obvious code inside function:
    + Comments must be direct above code. 
    + Comment of a block of code must be summarized directly above block. 
    + Explain what is functions' purpose directly above function definition.
- e.g:
```c
// Explain what is functions' purpose
// Function to add a task
bool System_Task_Add()
{
    // function body
}
// matrix multiplication -> summary
for (int i = 0; i < rows; i++) 
{
    for (int j = 0; j < collumns; j++) 
    {
        matrix_multiplication[i][j] = 0;
        for (int k = 0; k < collumns; k++) 
        {
            // multiply the k-th element of row i with k-th of column j -> comments must be above code
            matrix_multiplication[i][j] += matrix_first[i][k] * matrix_second[k][j];
        }
    }
}
```
- Using `/* ... */`(You must use a "*" at the beginning of every line of comment) to describe brief desciption of every single `.c` file.
- e.g:
```c
/* This file C is the main source file of To-do list.
 * Menu can be edited here.
 */
#include<stdio.h>
//main function shows menu, gets user's options, and prints notifications.
int main()
{
    //function body 
}
```

# 4. Code formatting
## 4.1 Indentation
- Using 4 spaces for indentation.
- Don't use tab.
- Using 4 spaces for continued line. 
- e.g:
```c
// Using 4 spaces for continued line.
printf("verylongggggggggggggggggggggggg \
    gggggggggggggggglineeeeeeeeeeeeeeeeee"); 
```

## 4.2 Alignment
- Alway align parameters after the open bracket if the parameters don't fit on a single line.
- Align consecutive preprocessor macros.
- Align consecutive assignments.
- Align escaped newlines on the left.
- Don't align consecutive declarations.
- Align long expression in operations.
- e.g:
```c
// Align parameters after the open bracket
Function_Long(
    argument1, argument2);

// Align consecutive preprocessor macros.
#define SHORT_NAME       42
#define LONGER_NAME      0x007f
#define EVEN_LONGER_NAME (2)

// Align consecutive assignments
int aaaa = 12;
int b    = 23;
int ccc  = 23;

// Align escaped newlines on the left
#define Add(int a, int b, int c)\
                 a + b      
                     
#define Add(int a, int b, int c) a + b // the same way

// Don't align consecutive declarations
int         aaaa = 12; //these two are example for align consecutive declarations
float       b = 23;

// Align long expression in operations
int aaa = bbbbbbbbbbbbbbb +
          ccccccccccccccc;
```

## 4.3 Braces
- Braces must be on their own lines.
- `else` must not be in same line with previous `}`.   
- Don't break `{}` of empty functions, structs, unions, enums. 
- e.g:
```c

int Example()
{}

int main()
{
    int x = 0;
    while(true)
    {};
    if(x > 0)
    {
        // body
    }
    else
    {
        // body
    }
}
```

## 4.4 Space
- Space before and after assignment operators.
- No space after logical `not` operator and style casts.
- No space before opening parentheses.
- No space after open bracket and before close bracket even it's empty.
- e.g:
```c
// Space before and after assignment operators
task_count += 2

// No space after logical `not` operator and style casts.
if (!(count&1))

// No space before opening parentheses
while(true)

// No space after open bracket and before close bracket even it's empty
void f() 
{                    
    int x[] = {foo(), bar()};          
    if (true) 
    {                          
    f();                                
    }                                    
}
```

## 4.5 Line
- Maximum characters in 1 line is 80.
- Always allow short conditional statement and short loop on a single line.
- Don't break before muti-line string literals. 
- Don't keep empty line at the start of block.
- e.g:
```c
// Maximum characters in 1 line is 80
printf("========================================This is maximum characters in one
    lines========================================")

// Allow short conditional statement and short loop on a single line
if(a&1) count++;
while(true) count--;

// Don't break before muti-line string literals
true:                                  false:
    aaaa =                                 aaaa = "bbbb"
        "bbbb"                                    "cccc";
        "cccc";

// Don't keep empty line at the start of block
 true:                                  false:
    if(foo)                             if(foo) 
    {                                   {  
                                            bar();
        bar();                          }
    }
```

## 4.6 Argument and Parameter
- If a function call or braced initializer list doesn't fit on a line, allow putting all arguments onto the next line.
- If the function declaration doesn't fit on a line, allow putting all parameters of a function declaration onto the next line.
- e.g:
```c
// Putting all arguments onto the next line
Count(
    number_first, number_second);

// putting all parameters of a function declaration onto the next line
int Count(
    int number_first, int number_second);
```

## 4.7 Comment
- Using `CommentPragment` for special comments to avoid break lines.
- Allow break and re-flow comment lines if exceed line limit.
- e.g:
```c
//Using `CommentPragment`
    // CommentPragmas: '^ FOOBAR pragma:'
    // Will leave the following line unaffected
    #include <stdio.h> // FOOBAR pragma: veryyyyyyyyyyyyyyyylonngggggggggggggcommmmmment -> isn't broken

// Allow break and re-flow comment lines if exceed line limit.
    // veryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryLongComment with plenty of
    // information
    /* second veryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryLongComment with plenty of
    * information */
```

## 4.8 Other rules
- Don't use macros to define statements.
- Don't disable clang-format.
- Set language to Cpp for both C and C++.
- Other rules based on `LLVM` style if aren't mentioned.
- e.g:
```c
// Don't use macros to define statements
#define HELLO printf("Hello World!")
```