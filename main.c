#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Task_Amount 100
#define Task_Length 32

char Temp_title[Task_Length], Title[Task_Amount][Task_Length] = {'\0'};
int Temp_status, Task_Status[Task_Amount] = {0};
int current_id = 0;

bool ADDTASK()
{
    printf("There are %d tasks now.", current_id);
    printf("\nEnter task's title: ");
    fgets(Temp_title, Task_Length, stdin);
    Temp_title[strcspn(Temp_title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &Temp_status);
    while (getchar() != '\n');
    strcpy(Title[current_id], Temp_title);
    Task_Status[current_id] = Temp_status;
    printf("Task's title is: %s\n", Title[current_id]);
    printf("Task's status is: %d\n", Task_Status[current_id]);
    current_id++;
    if ((strcmp(Title[current_id - 1], Temp_title) == 0) && (Task_Status[current_id - 1] == Temp_status))
        return true;
    else
        return false;
}

bool DELETETASK()
{
    if (current_id == 0)
    {
        printf("There is no task!\n");
        return 0;
    }
    int delete_id;
    printf("Enter task's ID you want to delete (1 ~ %d): ", current_id);
    scanf("%d", &delete_id);
    while (getchar() != '\n');
    if (delete_id < 1 || delete_id >= current_id)
    {
        printf("Invalid ID!\n");
        return 0;
    }
    for (int i = delete_id - 1; i < current_id - 1; i++)
    {
        strcpy(Title[i], Title[i + 1]);
        Task_Status[i] = Task_Status[i + 1];
    }
    current_id--;
    return 1;
}

bool EDITTASK()
{
    if (current_id == 0)
    {
        printf("There is no task!\n");
        return 0;
    }
    printf("Enter task's ID you want to modify (1 ~ %d): ", current_id);
    int modify_id;
    scanf("%d", &modify_id);
    while(getchar() != '\n');
    if (modify_id < 1 || modify_id > current_id)
    {
        printf("Invalid ID!\n");
        return 0;
    }
    printf("Enter task's title: ");
    fgets(Temp_title, Task_Length, stdin);
    Temp_title[strcspn(Temp_title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &Temp_status);
    while (getchar() != '\n');
    strcpy(Title[modify_id - 1], Temp_title);
    Task_Status[modify_id - 1] = Temp_status;
    printf("Task's title is: %s\n", Title[modify_id - 1]);
    printf("Task's status is: %d\n", Task_Status[modify_id - 1]);
    return 1;
}

void SORTING_Table()
{
    printf("+-----+----------------------------------+--------+\n");
    printf("| ID  | Title                            | Status |\n");
    printf("+-----+----------------------------------+--------+\n");

    for (int i = 0; i < current_id; i++)
    {
        printf("| %3d | %-32s | %6d |\n", i + 1, Title[i], Task_Status[i]);
        printf("+-----+----------------------------------+--------+\n");
    }
}

void SEARCHTASK_Search()
{
    unsigned count = 0;
    printf("Enter task's title you want to search: ");
    fgets(Temp_title, Task_Length, stdin);
    Temp_title[strcspn(Temp_title, "\n")] = 0;
    for (int i = 0; i < current_id; i++)
    {
        if (strstr(Title[i], Temp_title) != NULL)
        {
            printf("%d. %s : %d\n", i + 1, Title[i], Task_Status[i]);
            count++;
        }
    }
    if (count == 0)
    {
        printf("No task found!\n");
    }
}

void SORTING_SortTask()
{
    for (int i = 0; i < current_id; i++)
    {
        int status_min_index = i;
        for (int j = i + 1; j < current_id; j++)
        {
            if (Task_Status[j] <= Task_Status[status_min_index])
            {
                status_min_index = j;
            }
        }
        if (status_min_index != i)
        {
            int status_min = Task_Status[i];
            Task_Status[i] = Task_Status[status_min_index];
            Task_Status[status_min_index] = status_min;

            char status_min_title[Task_Length];
            strcpy(status_min_title, Title[i]);
            strcpy(Title[i], Title[status_min_index]);
            strcpy(Title[status_min_index], status_min_title);
        }
    }
}

int main(int argc, char *argv[])
{
    while (1)
    {
        printf("==============TODOLIST==============\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Sort all task by status and show\n");
        printf("4. Modify task\n");
        printf("5. Search task\n");
        printf("6. Exit\n");
        printf("====================================\n");

        unsigned int option;
        printf("Enter your option: ");
        scanf("%d", &option);
        while (getchar() != '\n');

        switch (option)
        {
        case 1:
            bool check_1 = ADDTASK();
            check_1 ? printf("Task has been successfully added!\n") : printf("Task has not been added!\n");
            break;
        case 2:
            bool check_2 = DELETETASK();
            check_2 ? printf("Task has been successfully deleted!\n") : printf("Task has not been deleted!\n");
            break;
        case 3:
            SORTING_SortTask();
            break;
        case 4:

            bool check_3 = EDITTASK();
            check_3 ? printf("Task has been successfully modified!\n") : printf("Task has not been modified!\n");
            break;
        case 5:
            SEARCHTASK_Search();
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
