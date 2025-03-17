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

        switch (option)
        {
        case 1:
            printf("Enter task's title: ");
            scanf("%s", Temp_title);
            printf("Enter task's status: ");
            scanf("%d", &Temp_status);
            strcpy(Title[current_id], Temp_title);
            Task_Status[current_id] = Temp_status;
            printf("Task's title is: %s\n", Title[current_id]);
            printf("Task's status is: %d\n", Task_Status[current_id]);
            printf("New task successfully added!\n");
            current_id++;
            break;
        case 2:
            printf("Enter task's ID you want to delete (0 ~ %d): ", current_id);
            int delete_id;
            scanf("%d", &delete_id);
            if (delete_id < 0 || delete_id >= current_id)
            {
                printf("Invalid ID!\n");
                break;
            }
            for (int i = delete_id; i < current_id - 1; i++)
            {
                strcpy(Title[i], Title[i + 1]);
                Task_Status[i] = Task_Status[i + 1];
            }
            current_id--;
            printf("Task successfully deleted!\n");
            break;
        case 3:
            while (1)
            {
                printf("Do you want to save all tasks? (Enter Y/N): ");
                char save_option;
                scanf(" %c", &save_option);
                switch (save_option)
                {
                case 'Y':
                    printf("Your data has been saved!\n");
                    return 0;
                case 'N':
                    printf("Your data has been deleted!\n");
                    return 0;
                default:
                    printf("Invalid option!\n");
                    break;
                }
            }
            break;
        }
    }
}