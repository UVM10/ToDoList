#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK_AMOUNT      200
#define TITLE_LENGTH     33
#define ID_LENGTH        5
#define FILE_LINE_LENGTH 300

typedef struct
{
    char title[TITLE_LENGTH];
    int status;
    char id[ID_LENGTH];
} task_new;

bool System_Task_Add(task_new *task, char task_information[][FILE_LINE_LENGTH]);
bool System_Task_Delete(
    task_new *task, char task_information[][FILE_LINE_LENGTH]);
void Task_Table(task_new *task);
void System_Task_Sort(
    task_new *tasks, int left, int right,
    char task_information[][FILE_LINE_LENGTH]);
bool Task_Edit(task_new *task);
void System_Task_Search(task_new *task);
void File_Information_Sort(int *data_type_sort);
bool File_Information_Break(
    char task_information[][FILE_LINE_LENGTH], int type_index, int task_index,
    char *task_write_file);
bool System_File_Read(
    FILE **data_csv, task_new *task, char task_information[][FILE_LINE_LENGTH]);
bool System_File_Write(
    FILE **data_csv, task_new *task, char task_information[][FILE_LINE_LENGTH]);
int main(void);

int index_current = 0;

/* Display menu, get user input and print notification
 */
int main()
{
    task_new tasks[TASK_AMOUNT];
    char task_information[TASK_AMOUNT][FILE_LINE_LENGTH];
    FILE *data_csv;

    while(1)
    {
        unsigned int option;

        printf("\n==============TODOLIST==============\n");
        printf("There are some requirement you need to know:\n");
        printf("1. Task's title: 32 characters or less than that.\n");
        printf("2. Task's ID format: WNN.\n");
        printf("W: F(From file) or A(From app), NNN: Number(001~200).\n");
        printf("====================================\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Sort all task by status and show\n");
        printf("4. Modify task\n");
        printf("5. Search task\n");
        printf("6. Write task list to file\n");
        printf("7. Read task list from file\n");
        printf("8. Exit\n");
        printf("====================================\n");

        printf("Enter your option: ");
        scanf("%u", &option);
        while(getchar() != '\n');

        switch(option)
        {
        case 1:
            bool check_1;
            check_1 = System_Task_Add(tasks, task_information);
            check_1 ? printf("Task has been successfully added!\n")
                    : printf("Task has not been added!\n");
            break;
        case 2:
            bool check_2;
            check_2 = System_Task_Delete(tasks, task_information);
            check_2 ? printf("Task has been successfully deleted!\n")
                    : printf("Task has not been deleted!\n");
            break;
        case 3:
            System_Task_Sort(tasks, 0, index_current - 1, task_information);
            Task_Table(tasks);
            break;
        case 4:

            bool check_3;
            check_3 = Task_Edit(tasks);
            check_3 ? printf("Task has been successfully modified!\n")
                    : printf("Task has not been modified!\n");
            break;
        case 5:
            System_Task_Search(tasks);
            break;
        case 6:
            bool check_4;
            check_4 = System_File_Write(&data_csv, tasks, task_information);
            check_4
                ? printf("Task list has been successfully written to file!\n")
                : printf("Task list has not been written to file!\n");
            break;
        case 7:
            bool check_5;
            check_5 = System_File_Read(&data_csv, tasks, task_information);
            check_5
                ? printf("Task list has been successfully read from file!\n")
                : printf("Task list has not been read from file!\n");
            break;
        case 8:
            printf("Exit!\n");
            return 0;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
}
/* Function to add a task
 */
bool System_Task_Add(task_new *task, char task_information[][FILE_LINE_LENGTH])
{
    // Use for checking id format
    int id_length = 0;
    if(index_current >= TASK_AMOUNT)
    {
        printf("Task list is full!\n");
        return false;
    }
    printf("Enter task's title: ");
    fgets(task[index_current].title, TITLE_LENGTH, stdin);
    task[index_current].title[strcspn(task[index_current].title, "\n")] = 0;
    printf("Enter task's status: ");
    scanf("%d", &task[index_current].status);
    while(getchar() != '\n');
    printf("Enter task's ID(WNNN): ");
    fgets(task[index_current].id, ID_LENGTH, stdin);
    task[index_current].id[strcspn(task[index_current].id, "\n")] = 0;
    id_length = strlen(task[index_current].id);
    // check if ID is in the form of WNNN
    while(id_length != ID_LENGTH - 1)
    {
        printf("Your ID must be in form. Please enter ID again: ");
        fgets(task[index_current].id, ID_LENGTH, stdin);
        task[index_current].id[strcspn(task[index_current].id, "\n")] = 0;
        id_length = strlen(task[index_current].id);
    }

    strcpy(task_information[index_current], task[index_current].id);

    printf("Task's title is: %s\n", task[index_current].title);
    printf("Task's status is: %d\n", task[index_current].status);
    printf("Task's ID is: %s\n", task[index_current].id);
    index_current++;
    return true;
}
/* Function to delete a task
 */
bool System_Task_Delete(
    task_new *task, char task_information[][FILE_LINE_LENGTH])
{
    int id_delete;
    if(index_current == 0)
    {
        printf("There is no task!\n");
        return false;
    }
    printf("Enter task's ID you want to delete (1 ~ %d): ", index_current);
    scanf("%d", &id_delete);
    while(getchar() != '\n');
    if(id_delete < 1 || id_delete > index_current)
    {
        printf("Invalid ID!\n");
        return false;
    }
    for(int i = id_delete - 1; i < index_current - 1; i++)
    {
        task[i] = task[i + 1];
        strcpy(task_information[i], task_information[i + 1]);
    }

    task_information[index_current - 1][0] = '\0';

    task[index_current - 1].title[0] = '\0';
    task[index_current - 1].status   = 0;
    task[index_current - 1].id[0]    = '\0';

    index_current--;
    return true;
}
/* Function to display all tasks in a table
 */
void Task_Table(task_new *task)
{
    printf("+------+----------------------------------+--------+\n");
    printf("| ID   | Title                            | Status |\n");
    printf("+------+----------------------------------+--------+\n");

    for(int i = 0; i < index_current; i++)
    {
        printf(
            "| %-4s | %-32s | %6d |\n", task[i].id, task[i].title,
            task[i].status);
        printf("+------+----------------------------------+--------+\n");
    }
}
/* Function to sort tasks by status
 */
void System_Task_Sort(
    task_new *tasks, int left, int right,
    char task_information[][FILE_LINE_LENGTH])
{
    int middle, left_temp, right_temp;
    char task_information_temp[FILE_LINE_LENGTH];
    task_new temp;

    if(left >= right) return;

    middle     = tasks[(left + right) / 2].status;
    left_temp  = left;
    right_temp = right;
    // Split into two parts and sort them
    while(left_temp <= right_temp)
    {
        while(tasks[left_temp].status < middle) left_temp++;
        while(tasks[right_temp].status > middle) right_temp--;
        if(left_temp <= right_temp)
        {
            temp              = tasks[left_temp];
            tasks[left_temp]  = tasks[right_temp];
            tasks[right_temp] = temp;

            strcpy(task_information_temp, task_information[left_temp]);
            strcpy(task_information[left_temp], task_information[right_temp]);
            strcpy(task_information[right_temp], task_information_temp);

            left_temp++;
            right_temp--;
        }
    }
    // Recursively sort the left and right parts
    System_Task_Sort(tasks, left, right_temp, task_information);
    System_Task_Sort(tasks, left_temp, right, task_information);
}
/* Function to edit an existing task
 */
bool Task_Edit(task_new *task)
{
    int index_modify;
    if(index_current == 0)
    {
        printf("There is no task!\n");
        return false;
    }
    printf("Enter task's ID you want to modify (1 ~ %d): ", index_current);
    scanf("%d", &index_modify);
    while(getchar() != '\n');
    if(index_modify < 1 || index_modify > index_current)
    {
        printf("Invalid ID!\n");
        return false;
    }
    printf("Enter task's title: ");
    fgets(task[index_modify - 1].title, TITLE_LENGTH, stdin);
    task[index_modify - 1].title[strcspn(task[index_modify - 1].title, "\n")] =
        0;
    printf("Enter task's status: ");
    scanf("%d", &task[index_modify - 1].status);
    while(getchar() != '\n');
    printf("Task's title is: %s\n", task[index_modify - 1].title);
    printf("Task's status is: %d\n", task[index_modify - 1].status);
    return true;
}
/* Function to search for a task by title
 */
void System_Task_Search(task_new *task)
{
    char title_search[TITLE_LENGTH];
    int count = 0;
    printf("Enter task's title you want to search: ");
    fgets(title_search, TITLE_LENGTH, stdin);
    title_search[strcspn(title_search, "\n")] = 0;
    // Check and print all tasks that titles contain the search string
    for(int i = 0; i < index_current; i++)
    {
        if(strstr(task[i].title, title_search) != NULL)
        {
            printf("%s. %s: %d\n", task[i].id, task[i].title, task[i].status);
            count++;
        }
    }
    if(count == 0)
    {
        printf("No task found.\n");
    }
    else
    {
        printf("%d task(s) found.\n", count);
    }
}
/* Function to find ID, Title, Status collumns in the CSV file
 * This function will be called in System_File_Write and System_File_Read
 */
void File_Information_Sort(int *data_type_sort)
{
    FILE *data_csv;
    char line_head[FILE_LINE_LENGTH];
    int i                 = 0;
    const int MAX_COLUMNS = 6;
    char *token;
    data_csv = fopen("docs/task.csv", "r");
    if(!data_csv)
    {
        return;
    }

    if(fgets(line_head, FILE_LINE_LENGTH, data_csv) != NULL)
    {
        // Loại bỏ ký tự xuống dòng ở cuối chuỗi
        line_head[strcspn(line_head, "\r\n")] = '\0';
        if(strlen(line_head) >= 3 && (unsigned char)line_head[0] == 0xEF &&
           (unsigned char)line_head[1] == 0xBB &&
           (unsigned char)line_head[2] == 0xBF)
        {
            memmove(line_head, line_head + 3, strlen(line_head) - 2);
        }
        token = strtok(line_head, ",");
        while(token != NULL && i < MAX_COLUMNS)
        {
            if(strcmp(token, "ID") == 0) data_type_sort[i] = 1;
            else if(strcmp(token, "Title") == 0)
                data_type_sort[i] = 2;
            else if(strcmp(token, "Status") == 0)
                data_type_sort[i] = 4;
            else if(strcmp(token, "Detail") == 0)
                data_type_sort[i] = 3;
            else if(strcmp(token, "Priority") == 0)
                data_type_sort[i] = 5;
            else
                data_type_sort[i] = 6;     // Các trường khác

            token = strtok(NULL, ",");
            i++;
        }
    }

    fclose(data_csv);
}
/* Function to write information which isn't edited
 * This function is used in System_File_Write
 */
bool File_Information_Break(
    char task_information[][FILE_LINE_LENGTH], int type_index, int task_index,
    char *task_write_file)
{
    char *token;
    int type_count = 1;
    char task_information_temp[FILE_LINE_LENGTH];
    strcpy(task_information_temp, task_information[task_index]);
    token = strtok(task_information_temp, ",");
    while(token != NULL)
    {
        if(type_count == type_index)
        {
            strcpy(task_write_file, token);
        }
        token = strtok(NULL, ",");
        type_count++;
    }
    return true;
}
/* Write task list to a CSV file with columns: ID,Title,Status
 */
bool System_File_Write(
    FILE **data_csv, task_new *task, char task_information[][FILE_LINE_LENGTH])
{
    int type_sort[6];
    bool check;
    char task_write_file[FILE_LINE_LENGTH];
    char line_header[2][FILE_LINE_LENGTH];
    FILE *data_csv_temp = fopen("docs/task.csv", "r");
    *data_csv           = fopen("docs/task_temp.csv", "w");
    if(!data_csv_temp)
    {
        return false;
    }
    if(!*data_csv)
    {
        return false;
    }
    fgets(line_header[0], FILE_LINE_LENGTH, data_csv_temp);
    fgets(line_header[1], FILE_LINE_LENGTH, data_csv_temp);
    fclose(data_csv_temp);
    fprintf(*data_csv, "%s", line_header[0]);
    fprintf(*data_csv, "%s", line_header[1]);

    File_Information_Sort(type_sort);

    for(int i = 0; i < index_current; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            switch(type_sort[j])
            {
            case 1:
                fprintf(*data_csv, "F%03d,", i + 1);
                break;
            case 2:
                fprintf(*data_csv, "%s,", task[i].title);
                break;
            case 4:
                fprintf(*data_csv, "%d,", task[i].status);
                break;
            case 3:
            case 5:
            case 6:
                if(task_information[i][0] == 'A')
                {
                    fprintf(*data_csv, "None,");
                }
                else if(task_information[i][0] == 'F')
                {
                    check = File_Information_Break(
                        task_information, type_sort[j], i, task_write_file);
                    if(!check)
                    {
                        return false;
                    }
                    fprintf(*data_csv, "%s,", task_write_file);
                }
                break;
            default:
                break;
            }
        }
        fseek(*data_csv, -1, SEEK_CUR);
        fputc('\n', *data_csv);
    }

    fclose(*data_csv);

    remove("docs/task.csv");
    rename("docs/task_temp.csv", "docs/task.csv");

    return true;
}
/* Function to read task list from a CSV file
 * This function only reads ID, Title, Status
 */
bool System_File_Read(
    FILE **data_csv, task_new *task, char task_information[][FILE_LINE_LENGTH])
{
    char line[FILE_LINE_LENGTH];
    int type_sort[6];
    char *token;
    int column_index;

    index_current = 0;

    *data_csv = fopen("docs/task.csv", "r");
    if(*data_csv == NULL)
    {
        return false;
    }

    fgets(line, FILE_LINE_LENGTH, *data_csv);
    fgets(line, FILE_LINE_LENGTH, *data_csv);

    File_Information_Sort(type_sort);

    while(fgets(line, FILE_LINE_LENGTH, *data_csv) != NULL)
    {
        line[strcspn(line, "\r\n")] = ',';
        line[strcspn(line, "\r\n")] = '\0';
        strncpy(task_information[index_current], line, FILE_LINE_LENGTH - 1);
        task_information[index_current][FILE_LINE_LENGTH - 1] = '\0';

        token        = strtok(line, ",");
        column_index = 0;

        while(token != NULL)
        {
            switch(type_sort[column_index])
            {
            case 1:
                strncpy(task[index_current].id, token, ID_LENGTH - 1);
                task[index_current].id[ID_LENGTH - 1] = '\0';
                break;
            case 2:
                strncpy(task[index_current].title, token, TITLE_LENGTH - 1);
                task[index_current].title[TITLE_LENGTH - 1] = '\0';
                break;
            case 4:
                task[index_current].status = atoi(token);
            default:
                break;
            }
            token = strtok(NULL, ",");
            column_index++;
        }
        index_current++;
    }

    fclose(*data_csv);
    return true;
}