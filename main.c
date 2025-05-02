#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Task_Amount 100
#define Task_Title_Length 33
#define ID_Length 9

typedef struct 
{
    char Title[Task_Title_Length];
    int Status;
    char ID[ID_Length];
}Task;

bool ADDTASK(Task *task);

bool DELETETASK(Task *tasks);

void SORTING_Table(Task *tasks);

void SORTING_SortTask(Task *tasks, int left, int right);

bool EDITTASK(Task *tasks);

void SEARCHTASK_Search(Task *tasks);

int main(void);

int current_index = 0;

int main()
{
    Task tasks[Task_Amount];

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
            check_1 = ADDTASK(tasks);
            check_1 ? printf("Task has been successfully added!\n") : printf("Task has not been added!\n");
            break;
        case 2:
            bool check_2; 
            check_2 = DELETETASK(tasks);
            check_2 ? printf("Task has been successfully deleted!\n") : printf("Task has not been deleted!\n");
            break;
        case 3:
            SORTING_SortTask(tasks, 0, current_index - 1);
            SORTING_Table(tasks);
            break;
        case 4:

            bool check_3;
            check_3 = EDITTASK(tasks);
            check_3 ? printf("Task has been successfully modified!\n") : printf("Task has not been modified!\n");
            break;
        case 5:
            SEARCHTASK_Search(tasks);
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

bool ADDTASK(Task *task)
{
    int id_length = 0;
    if (current_index >= Task_Amount)
    {
        printf("Task list is full!\n");
        return false;
    }
    printf("Enter task's title: ");
    fgets(task[current_index].Title, Task_Title_Length, stdin);
    task[current_index].Title[strcspn(task[current_index].Title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &task[current_index].Status);
    while (getchar() != '\n');
    printf("Enter task's ID(DDMMYYNN): ");
    fgets(task[current_index].ID, ID_Length, stdin);
    task[current_index].ID[strcspn(task[current_index].ID, "\n")] = 0;
    id_length = strlen(task[current_index].ID);
    while(id_length != ID_Length - 1)
    {
        printf("Your ID must be in form. Please enter ID again: ");
        fgets(task[current_index].ID, ID_Length, stdin);
        task[current_index].ID[strcspn(task[current_index].ID, "\n")] = 0;
        id_length = strlen(task[current_index].ID);
    }
    printf("Task's title is: %s\n", task[current_index].Title);
    printf("Task's status is: %d\n", task[current_index].Status);
    printf("Task's ID is: %s\n", task[current_index].ID);
    current_index++;
    return true;
}

bool DELETETASK(Task *task)
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
    task[current_index - 1].Title[0] = '\0'; // Clear the last task
    task[current_index - 1].Status = 0;
    task[current_index - 1].ID[0] = '\0'; // Clear the last task ID
    current_index--;
    return true;
}

void SORTING_Table(Task *task)
{
    printf("+----------+----------------------------------+--------+\n");
    printf("| ID       | Title                            | Status |\n");
    printf("+----------+----------------------------------+--------+\n");

    for (int i = 0; i < current_index; i++)
    {
        printf("| %-8s | %-32s | %6d |\n", task[i].ID, task[i].Title, task[i].Status);
        printf("+----------+----------------------------------+--------+\n");
    }
}

void SORTING_SortTask(Task *tasks, int left, int right)
{
    int sort, i, j;

    if (left >= right) return;

    sort = tasks[(left + right) / 2].Status;
    i = left;
    j = right;

    while (i <= j)
    {
        while (tasks[i].Status < sort) i++;
        while (tasks[j].Status > sort) j--;
        if (i <= j)
        {
            Task temp = tasks[i];
            tasks[i] = tasks[j];
            tasks[j] = temp;
            i++; j--;
        }
    }

    SORTING_SortTask(tasks, left, j);
    SORTING_SortTask(tasks, i, right);
}

bool EDITTASK(Task *task)
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
    fgets(task[modify_id - 1].Title, Task_Title_Length, stdin);
    task[modify_id - 1].Title[strcspn(task[modify_id - 1].Title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &task[modify_id - 1].Status);
    while (getchar() != '\n');
    printf("Task's title is: %s\n", task[modify_id - 1].Title);
    printf("Task's status is: %d\n", task[modify_id - 1].Status);
    return true;
}

void SEARCHTASK_Search(Task *task)
{
    char search_title[Task_Title_Length];
    int count = 0;
    printf("Enter task's title you want to search: ");
    fgets(search_title, Task_Title_Length, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < current_index; i++)
    {
        if(strstr(task[i].Title, search_title) != NULL)
        {
            printf("%s. %s: %d\n", task[i].ID, task[i].Title, task[i].Status);
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

