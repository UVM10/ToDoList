#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Task_Amount 100
#define Task_Title_Length 33
#define ID_Length 9

typedef struct 
{
    char title[Task_Title_Length];
    int status;
    char id[ID_Length];
}task;

bool ADD_TASK(task *task);

bool DELETE_TASK(task *task);

void SHOW_TASK(task *task);

void SORT_TASK(task *task, int left, int right);

bool EDIT_TASK(task *task);

void SEARCH_TASK(task *task);

int main(void);

void READ_FILE();

void WRITE_FILE();

int current_index = 0;

int main()
{
    task tasks[Task_Amount];

    while (1)
    {
        unsigned int option;
        
        printf("==============TODOLIST==============\n");
        printf("There are some requirement you need to know:\n");
        printf("1. Task's title: 32 characters or less than that.\n");
        printf("2. Task's ID format: DDMMYYNN.\n   DD: Day, MM: Month, YY: Year, NN: Number(00~99).\n");
        printf("====================================\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Sort all task by status and show\n");
        printf("4. Modify task\n");
        printf("5. Search task\n");
        printf("6. Exit\n");
        printf("====================================\n");

        printf("Enter your option: ");
        scanf("%u", &option);
        while (getchar() != '\n');

        switch (option)
        {
        case 1:
            bool check_1;
            check_1 = ADD_TASK(tasks);
            check_1 ? printf("Task has been successfully added!\n") : printf("Task has not been added!\n");
            break;
        case 2:
            bool check_2; 
            check_2 = DELETE_TASK(tasks);
            check_2 ? printf("Task has been successfully deleted!\n") : printf("Task has not been deleted!\n");
            break;
        case 3:
            SORT_TASK(tasks, 0, current_index - 1);
            SHOW_TASK(tasks);
            break;
        case 4:

            bool check_3;
            check_3 = EDIT_TASK(tasks);
            check_3 ? printf("Task has been successfully modified!\n") : printf("Task has not been modified!\n");
            break;
        case 5:
            SEARCH_TASK(tasks);
            break;
        case 6:
            printf("Exit!\n");
            return 0;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
}

bool ADDT_ASK(task *task)
{
    int id_length = 0;
    if (current_index >= Task_Amount)
    {
        printf("Task list is full!\n");
        return false;
    }
    printf("Enter task's title: ");
    fgets(task[current_index].title, Task_Title_Length, stdin);
    task[current_index].title[strcspn(task[current_index].title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &task[current_index].status);
    while (getchar() != '\n');
    printf("Enter task's ID(DDMMYYNN): ");
    fgets(task[current_index].id, ID_Length, stdin);
    task[current_index].id[strcspn(task[current_index].id, "\n")] = 0;
    id_length = strlen(task[current_index].id);
    while(id_length != ID_Length - 1)
    {
        printf("Your ID must be in form. Please enter ID again: ");
        fgets(task[current_index].id, ID_Length, stdin);
        task[current_index].id[strcspn(task[current_index].id, "\n")] = 0;
        id_length = strlen(task[current_index].id);
    }
    printf("Task's title is: %s\n", task[current_index].title);
    printf("Task's status is: %d\n", task[current_index].status);
    printf("Task's ID is: %s\n", task[current_index].id);
    current_index++;
    return true;
}

bool DELETE_TASK(task *task)
{
    int delete_id;
    if (current_index == 0)
    {
        printf("There is no task!\n");
        return false;
    }
    printf("Enter task's ID you want to delete (1 ~ %d): ", current_index);
    scanf("%d", &delete_id);
    while(getchar() != '\n');
    if (delete_id < 1 || delete_id > current_index)
    {
        printf("Invalid ID!\n");
        return false;
    }
    for (int i = delete_id - 1; i < current_index - 1; i++)
    {
        task[i] = task[i + 1];
    }
    task[current_index - 1].title[0] = '\0'; // Clear the last task
    task[current_index - 1].status = 0;
    task[current_index - 1].id[0] = '\0'; // Clear the last task ID
    current_index--;
    return true;
}

void SHOW_TASK(task *task)
{
    printf("+----------+----------------------------------+--------+\n");
    printf("| ID       | Title                            | Status |\n");
    printf("+----------+----------------------------------+--------+\n");

    for (int i = 0; i < current_index; i++)
    {
        printf("| %-8s | %-32s | %6d |\n", task[i].id, task[i].title, task[i].status);
        printf("+----------+----------------------------------+--------+\n");
    }
}

void SORT_TASK(task *tasks, int left, int right)
{
    int sort, left_temp, right_temp;

    if (left >= right) return;

    sort = tasks[(left + right) / 2].status;
    left_temp = left;
    right_temp = right;

    while (left_temp <= right_temp)
    {
        while (tasks[left_temp].status < sort) i++;
        while (tasks[right_temp].status > sort) j--;
        if (left_temp <= right_temp)
        {
            task temp = tasks[left_temp];
            tasks[left_temp] = tasks[right_temp];
            tasks[right_temp] = temp;
            left_temp++; right_temp--;
        }
    }

    SORTING_SortTask(tasks, left, right_temp);
    SORTING_SortTask(tasks, left_temp, right);
}

bool EDIT_TASK(task *task)
{
    int modify_id;
    if (current_index == 0)
    {
        printf("There is no task!\n");
        return false;
    }
    printf("Enter task's ID you want to modify (1 ~ %d): ", current_index);
    scanf("%d", &modify_id);
    while(getchar() != '\n');
    if (modify_id < 1 || modify_id > current_index)
    {
        printf("Invalid ID!\n");
        return false;
    }
    printf("Enter task's title: ");
    fgets(task[modify_id - 1].title, Task_Title_Length, stdin);
    task[modify_id - 1].title[strcspn(task[modify_id - 1].title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &task[modify_id - 1].status);
    while (getchar() != '\n');
    printf("Task's title is: %s\n", task[modify_id - 1].title);
    printf("Task's status is: %d\n", task[modify_id - 1].status);
    return true;
}

void SEARCH_TASK(task *task)
{
    char search_title[Task_Title_Length];
    int count = 0;
    printf("Enter task's title you want to search: ");
    fgets(search_title, Task_Title_Length, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < current_index; i++)
    {
        if(strstr(task[i].title, search_title) != NULL)
        {
            printf("%s. %s: %d\n", task[i].id, task[i].title, task[i].status);
            count++;
        }
    }
    if (count == 0)
    {
        printf("No task found.\n");
    }
    else
    {
        printf("%d task(s) found.\n", count);
    }
}
