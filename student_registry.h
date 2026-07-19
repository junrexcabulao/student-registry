#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#define MAX_STUDENTS 100
#define DATA_FILE "students.dat"

typedef struct {
    int id;
    char name[100];
    char major[50];
    float gpa;
    int credits;
} Student;


int  loadStudentsFromFile(Student list[], int max);
void saveStudentsToFile(Student list[], int count);


void addStudent(Student list[], int *count, int max);
void displayAllStudents(Student list[], int count);
void searchById(Student list[], int count);
void findByGPA(Student list[], int count);
void findByMajor(Student list[], int count);

#endif
