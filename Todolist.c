#include <stdio.h>
#include <string.h>

#define Task_Amount 100
#define Task_Length 32

char Temp_title[Task_Length], Title[Task_Amount][Task_Length] = {};
int Temp_status, Task_Status[Task_Amount] = {};
int current_id = 0;

int main(int argc[], char *argv[])
{
    while (1)
    {
        printf("==============TODOLIST==============\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Show all tasks\n");
        printf("4. Modify task\n");
        printf("5. Exit\n");
        printf("====================================\n");

        unsigned int option;
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: 
                printf("Enter task's title: ");
                scanf("%s", Temp_title);
                printf("Enter task's status: ");
                scanf("%d", Temp_status);
                while(getchar() != '/n');
                strcpy(Title[current_id], Temp_title);
                Task_Status[current_id] = Temp_status;
                current_id++;
                printf("Task's title is: %s\n", Title[current_id]);
                printf("Task's status is: %d\n", Task_Status[current_id]);
                printf("New task successfully added!\n");
                break;
        }
    }
}