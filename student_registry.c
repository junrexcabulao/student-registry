#include <stdio.h>
#include <string.h>
#include <strings.h>   
#include "student_registry.h"



int loadStudentsFromFile(Student list[], int max) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        return 0;
    }

    int count = 0;
    fread(&count, sizeof(int), 1, fp);

    if (count > max) {
        count = max;
    }

    fread(list, sizeof(Student), count, fp);
    fclose(fp);

    printf("Loaded %d students.\n", count);
    return count;
}

void saveStudentsToFile(Student list[], int count) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("Error: could not save data to file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(list, sizeof(Student), count, fp);
    fclose(fp);

    printf("Saved %d students to %s.\n", count, DATA_FILE);
}



void addStudent(Student list[], int *count, int max) {
    if (*count >= max) {
        printf("Registry is full. Cannot add more students.\n");
        return;
    }

    Student s;

    printf("ID: ");
    scanf("%d", &s.id);

    printf("Name: ");
    scanf(" %99[^\n]", s.name);

    printf("Major: ");
    scanf(" %49[^\n]", s.major);

    printf("GPA: ");
    scanf("%f", &s.gpa);

    printf("Credits: ");
    scanf("%d", &s.credits);

    list[*count] = s;
    (*count)++;

    printf("Student added successfully.\n");
}

void displayAllStudents(Student list[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n%-6s %-20s %-15s %-6s %-8s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-15s %-6.2f %-8d\n",
               list[i].id, list[i].name, list[i].major,
               list[i].gpa, list[i].credits);
    }
}

void searchById(Student list[], int count) {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            printf("\nStudent found:\n");
            printf("ID: %d\nName: %s\nMajor: %s\nGPA: %.2f\nCredits: %d\n",
                   list[i].id, list[i].name, list[i].major,
                   list[i].gpa, list[i].credits);
            return;
        }
    }
    printf("No student found with ID %d.\n", id);
}

void findByGPA(Student list[], int count) {
    float minGpa;
    printf("Enter minimum GPA: ");
    scanf("%f", &minGpa);

    int found = 0;
    printf("\nStudents with GPA >= %.2f:\n", minGpa);
    for (int i = 0; i < count; i++) {
        if (list[i].gpa >= minGpa) {
            printf("ID: %d | Name: %s | GPA: %.2f\n",
                   list[i].id, list[i].name, list[i].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("No students match that GPA threshold.\n");
    }
}

void findByMajor(Student list[], int count) {
    char major[50];
    printf("Enter major to search: ");
    scanf(" %49[^\n]", major);

    int found = 0;
    printf("\nStudents in %s:\n", major);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].major, major) == 0) {
            printf("ID: %d | Name: %s | GPA: %.2f\n",
                   list[i].id, list[i].name, list[i].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found in that major.\n");
    }
}
