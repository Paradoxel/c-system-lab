#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int age;
    float score;
} Student;

typedef struct
{
    Student *students;
    size_t size;
    size_t capacity;
} StudentManager;


/* ---------- Manager Lifecycle ---------- */

int init_manager(StudentManager *manager)
{
    manager->size = 0;
    manager->capacity = 2;

    manager->students = malloc(
        manager->capacity * sizeof *manager->students
    );

    if (manager->students == NULL)
    {
        return 0;
    }

    return 1;
}

void destroy_manager(StudentManager *manager)
{
    free(manager->students);

    manager->students = NULL;
    manager->size = 0;
    manager->capacity = 0;
}


/* ---------- Student Operations ---------- */

int add_student(StudentManager *manager)
{
    if (manager->size >= manager->capacity)
    {
        size_t new_capacity = manager->capacity * 2;

        Student *tmp = realloc(
            manager->students,
            new_capacity * sizeof *manager->students
        );

        if (tmp == NULL)
        {
            printf("Failed to expand student capacity.\n");
            return 0;
        }

        manager->students = tmp;
        manager->capacity = new_capacity;

        printf("Student capacity expanded to %zu.\n",
               manager->capacity);
    }

    Student *student = &manager->students[manager->size];

    printf("Enter student ID: ");
    scanf("%d", &student->id);

    printf("Enter student age: ");
    scanf("%d", &student->age);

    printf("Enter student score: ");
    scanf("%f", &student->score);

    manager->size++;

    printf("Student added successfully.\n");

    return 1;
}


void list_students(const StudentManager *manager)
{
    if (manager->size == 0)
    {
        printf("No students available.\n");
        return;
    }

    printf("\n===== Students =====\n");

    for (size_t i = 0; i < manager->size; i++)
    {
        printf(
            "ID: %d | Age: %d | Score: %.2f\n",
            manager->students[i].id,
            manager->students[i].age,
            manager->students[i].score
        );
    }
}


void find_student(const StudentManager *manager)
{
    int target_id;

    printf("Enter student ID: ");
    scanf("%d", &target_id);

    for (size_t i = 0; i < manager->size; i++)
    {
        if (manager->students[i].id == target_id)
        {
            printf(
                "Student found!\n"
                "ID: %d | Age: %d | Score: %.2f\n",
                manager->students[i].id,
                manager->students[i].age,
                manager->students[i].score
            );

            return;
        }
    }

    printf("Student not found.\n");
}


void remove_student(StudentManager *manager)
{
    int target_id;

    printf("Enter student ID: ");
    scanf("%d", &target_id);

    size_t index = 0;

    for (; index < manager->size; index++)
    {
        if (manager->students[index].id == target_id)
        {
            break;
        }
    }

    if (index == manager->size)
    {
        printf("Student not found.\n");
        return;
    }

    for (size_t i = index + 1; i < manager->size; i++)
    {
        manager->students[i - 1] = manager->students[i];
    }

    manager->size--;

    printf("Student removed successfully.\n");
}


/* ---------- User Interface ---------- */

void show_menu(void)
{
    printf("\n===== Student Manager =====\n");
    printf("1. Add student\n");
    printf("2. List students\n");
    printf("3. Find student\n");
    printf("4. Remove student\n");
    printf("5. Exit\n");
}


int main(void)
{
    StudentManager manager;

    if (!init_manager(&manager))
    {
        printf("Failed to initialize student manager.\n");
        return 1;
    }

    int choice;

    while (1)
    {
        show_menu();

        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_student(&manager);
                break;

            case 2:
                list_students(&manager);
                break;

            case 3:
                find_student(&manager);
                break;

            case 4:
                remove_student(&manager);
                break;

            case 5:
                printf("Goodbye!\n");
                destroy_manager(&manager);
                return 0;

            default:
                printf("Invalid option.\n");
                break;
        }
    }
}