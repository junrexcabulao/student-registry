# Enhanced Student Registry

A C program that manages student records (add, search, filter) and
persists them to disk using file I/O, so data survives between runs.

## Description

This project extends a basic in-memory student registry by adding:
- **File persistence** — records are saved to `students.dat` and reloaded
  automatically the next time the program runs.
- **Abstraction via header files** — `student_registry.h` declares the
  interface (what the functions do), while `student_registry.c` contains
  the implementation (how they work). `main.c` only needs to know the
  interface to use the registry.

## How to Compile

Using the Makefile (recommended):
