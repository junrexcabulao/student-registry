#include <stdio.h>
#include "student_registry.h"

int main(void) {
    Student list[MAX_STUDENTS];
    int count = 0;
    int choice = 0;

    count = loadStudentsFromFile(list, MAX_STUDENTS);

    while (choice != 6) {
        printf("\n1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search by ID\n");
        printf("4. Find by GPA\n");
        printf("5. Find by Major\n");
        printf("6. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(list, &count, MAX_STUDENTS);
                break;

            case 2:
                displayAllStudents(list, count);
                break;

            case 3:
                searchById(list, count);
                break;

            case 4:
                findByGPA(list, count);
                break;

            case 5:
                findByMajor(list, count);
                break;

            case 6:
                saveStudentsToFile(list, count);
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
