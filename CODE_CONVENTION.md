# 1. Variable's and function's name
Rules apply for all names: 
    - Using `sanke_case` and its variants.
    - Names must be meaningful, not abbreviated
    - Maximum length of 20 characters. 
    - Main noun of name must come first.
    - Do not use number in name. 
 
- Function's name:
    + Using `UPPER_SNAKE_CASE`.
    + Funtion's name must describe what it does.
    + Functions that do the main feature(s) must have `SYSTEM` at first.
    + All rules for function's name don't apply on `main` function
e.g:
```sh
SYSTEM_TASK_ADD();
SYSTEM_TASK_SHOW();
// this function makea a table for display task in `SYSTEM_TASK_SHOW` function
TABLE_MAKE(); 
```

- Variable's name: 
    + Using `lower_snake_case`.
    + Variable's name must be noun or noun prase and meaningful at least in its scope.
    + Do not use the same name for 2 or more variables even if they aren't in the same scope. 
e.g:
```sh
int id_current = 0;

int main()
{
    int option; 
}

SYSTEM_TASK_ADD()
{
    int selection;
}
```
- Constant's name:
    + Using `Pascal_snake_case`.
e.g: 
```sh
#define Id_Length 8
#define Task_Amount 100
```

# 2. File structure
Every `.c` file in workspace must follow this structure:
    1. Comment: Brief description about this file
    2. Standard system libraries 
    3. Header files
    4. Macros and constants
    5. User-defined data type: `struct`, `enum`, `union`
    6. Private function prototypes: prototypes of functions created in this file
    7. Global variables
    8. Public function definitions: definitions of function exported from header files
    9. Private function definition: definitions of function created in this file
e.g:
```sh
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
#define Id_Length 8
#define Title_Length 33

// User-defined data type
typedef struct
{
    char title[Title_Length];
    char id[Id_Length];
}task;

// Private function prototypes
SYSTEM_TASK_ADD(task *task);
SYSTEM_TASK_DELETE(task *task);

// Global variables
int index_current = 0;

// Public function definitions
SYSTEM_TASK_SORT() //This function is exported from header files
{}

// Private function definition
SYSTEM_TASK_ADD(task *task)
{}
SYSTEM_TASK_DELETE(task *task)
{}
```

# 3. Comment
There are some rules you must follow when using comments:
- Comments must be clear, professional, and not redundant.
e.g:
```sh
// count how many times each task appear. -> True
int count = 0;  

// Set index_curent to 0 -> False
int index_curent = 0; 

// do somthing -> False
process_data();
```
- Using `// ...` to clarify complex logic non-obvius code inside function:
    + Comments must be direct above code. 
    + Comment of a block of code must be group and direct above block. 
- Using `/* ... */`(You must use a "*" at the beginning of every line of comment) to:
    + Describe brief desciption of every single `.c` file.
    + Explain what is functions' purpose directly above function definition.

# 4. Code formatting
## 4.1 Identation
- Using 4 spaces for indentation.
- Don't use tab.
- Using 4 spaces for continued line. 
- Indent if a function definition, declaration, or prototype is wrapped after the return type. 
e.g:
```sh
// Using 4 spaces for continued line.
printf("verylongggggggggggggggggggggggg
    gggggggggggggggglineeeeeeeeeeeeeeeeee"); 

// Indent if a function definition or declaration is wrapped after the return type.
bool 
    TASK_ADD(task *task);

int 
    TASK_COUNT(int x, int y)
    {
        // function body
    }
```

## 4.2 Alignment
- Alway align parameters after the open bracket if the parameters don't fit on a single line.
- Align consecutive preprocessor macros.
- Align consecutive assignments.
- Align escaped newlines on the left.
- Don't align consecutive declarations.
- Align long expression in operations.
- Align trailing comments.
e.g:
```sh
// Align parameters after the open bracket
someLongFunction(
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
int aaaa; \
int b;    \

// Don't align consecutive declarations
int         aaaa = 12; //these two are example for align consecutive declarations
float       b = 23;

// Align long expression in operations
int aaa = bbbbbbbbbbbbbbb +
          ccccccccccccccc;

// Align trailing comments
int a;     // My comment a       
int b = 2; // comment  b
```

## 4.3 Braces
- Braces must be on their own lines.
- `else` must not be in same line with previous `}`.   
- Don't break `{}` of empty functions, structs, unions, enums. 
e.g:
```sh
// Braces must be on their own lines
int EXAMPLE()
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
- One space before trailing line comments.
e.g:
```sh
// Space before and after assignment operators
task_count += 2

// No space after logical `not` operator and style casts.
if !(count&1)

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

// One space before trailing line comments
int count = 0; //it count amount of tasks 
```

## 4.5 Line
- Maximum characters in 1 line is 80.
- Always allow short conditional statement and short loop on a single line.
- Don't break before muti-line string literals. 
- Don't keep empty line at the start of block.
e.g:
```sh
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
    if (foo)                            if (foo) 
    {                                   {  
                                            bar();
        bar();                          }
    }
```

## 4.6 Argument and Parameter
- If a function call or braced initializer list doesn't fit on a line, allow putting all arguments onto the next line.
- If the function declaration doesn't fit on a line, allow putting all parameters of a function declaration onto the next line.
e.g:
```sh
// Putting all arguments onto the next line
COUNT(
    int number_first, int number_second);

// putting all parameters of a function declaration onto the next line
int COUNT(
    int number_first, int number_second)
    {}
```

## 4.7 Comment
- Using `CommentPragment` for special comments to avoid break lines.
- Allow break and re-flow comment lines if exceed line limit.
e.g:
```sh
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
- Other rules set to default if aren't mentioned.
e.g:
```sh
// Don't use macros to define statements
#define HELLO printf("Hello World!")
```