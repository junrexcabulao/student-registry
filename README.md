# Enhanced Student Registry

A C program that stores student records (ID, name, major, GPA, credits) and saves them to a file so the data isn't lost when the program closes.

## How to Compile and Run

    make
    ./student_registry

## Files

- `student_registry.h` — declares the Student struct and function list
- `student_registry.c` — the actual code for each function
- `main.c` — the menu that runs the program
- `Makefile` — builds the program with one command

## What It Does

1. Add Student — enter a new student's info
2. Display All Students — show every student in a table
3. Search by Student ID — find one student
4. Find by GPA Threshold — list students above a GPA
5. Find by Major — list students in a major
6. Save & Exit — saves everything to `students.dat` and closes

## Data Structure

    typedef struct {
        int id;
        char name[100];
        char major[50];
        float gpa;
        int credits;
    } Student;

## File Format

Students are saved one per line in `students.dat`, separated by `|`:

    1001|Alice Johnson|Computer Science|3.85|90

## Testing

- Ran with no file — got "Starting fresh" message
- Added students, saved, closed
- Reopened — data loaded back correctly
- Search by ID, GPA, and Major all worked
