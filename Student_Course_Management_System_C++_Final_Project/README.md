# Student Course Management System
> A C++ console application for managing student records and course enrollments.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Compilation & Running](#compilation--running)
- [Menu Reference](#menu-reference)
- [Class Design (OOP)](#class-design-oop)
- [Constraints & Validation](#constraints--validation)
- [STL Usage](#stl-usage)
- [Known Limitations](#known-limitations)

---

## Overview

The **Student Course Management System** is a menu-driven C++ console application developed as a final project for an Object-Oriented Programming course. It allows users to manage student records (add, remove, search, display) and handle course enrollments per student.

---

## Features

| # | Feature |
|---|---------|
| 1 | Add a new student with unique ID, name, and GPA |
| 2 | Remove a student by ID |
| 3 | Search for a student by ID and view their courses |
| 4 | Display all registered students and their enrollments |
| 5 | Enroll a student in a course (with ID, name, credits, grade) |
| 6 | View all courses of a specific student |
| 7 | Sort all students by GPA (descending) |
| 8 | Exit the application |

---

## Project Structure

```
project/
├── Person.h                                      # Base class header
├── Person.cpp                                    # Base class implementation
├── Course.h                                      # Course class header
├── Course.cpp                                    # Course class implementation
├── Student.h                                     # Student class header (inherits Person)
├── Student.cpp                                   # Student class implementation
├── Student_Course_Management_System_C++_Final_Project.cpp  # Main file (menu + logic)
├── UML_Class_Diagram.svg                         # UML class diagram
├── Project_Report.docx                           # Full project report
└── README.md                                     # This file
```

---

## Prerequisites

- A C++11-compatible compiler (GCC, Clang, MSVC)
- Standard library support for `<vector>`, `<algorithm>`, `<iostream>`, `<string>`

---

## Compilation & Running

### Linux / macOS
```bash
g++ -std=c++11 Person.cpp Course.cpp Student.cpp \
    "Student_Course_Management_System_C++_Final_Project.cpp" \
    -o scms
./scms
```

### Windows (MinGW)
```cmd
g++ -std=c++11 Person.cpp Course.cpp Student.cpp Student_Course_Management_System_C++_Final_Project.cpp -o scms.exe
scms.exe
```

### Windows (MSVC)
```cmd
cl /EHsc /std:c++17 Person.cpp Course.cpp Student.cpp Student_Course_Management_System_C++_Final_Project.cpp /Fe:scms.exe
scms.exe
```

---

## Menu Reference

```
|===============================================================|
|   Welcome to the Student Course Management System!           |
|===============================================================|

Student Course Management System
1. Add Student.
2. Remove Student.
3. Search Student.
4. Display All Students.
5. Enroll Student in Course.
6. Show Student Courses.
7. Sort Students by GPA.
8. Exit
```

### Option Details

**1. Add Student**
- Prompts: Student ID (int), Name (string), GPA (double)
- Rejects duplicate IDs
- Clamps GPA to [0.0, 4.0] automatically

**2. Remove Student**
- Prompts: Student ID
- Prints success or "not found" message

**3. Search Student**
- Prompts: Student ID
- Displays full record including all enrolled courses

**4. Display All Students**
- Lists all students with their enrolled courses

**5. Enroll Student in Course**
- Prompts: Student ID, then Course ID, Course Name, Credits, Grade
- Silently ignores duplicate course enrollment (same course ID)

**6. Show Student Courses**
- Prompts: Student ID
- Displays all courses for that student

**7. Sort Students by GPA**
- Sorts and displays all students in descending GPA order

**8. Exit**
- Terminates the program

---

## Class Design (OOP)

```
Person (base class)
├── Attributes: ID (int), name (string)        [protected]
└── Methods:    constructors, getters, setters

    ▲  inherits
    │

Student (derived from Person)
├── Attributes: GPA (double), courses (vector<Course>)   [protected]
└── Methods:    constructors, getGPA/setGPA,
                enrollInCourse, getCourses

Course (independent class)
├── Attributes: ID, name, credits, grade       [protected]
└── Methods:    constructors, getters, setters
```

### Relationships
- **Inheritance**: `Student` inherits from `Person` (IS-A relationship)
- **Composition**: `Student` owns a `vector<Course>` (HAS-A relationship)

---

## Constraints & Validation

| Constraint | Enforcement |
|------------|-------------|
| Unique Student ID | Checked before insertion; error message on duplicate |
| GPA in [0.0, 4.0] | Clamped in constructor and setter |
| No duplicate courses per student | ID check in `enrollInCourse()` |
| Empty list guard | Operations check for empty list before proceeding |

---

## STL Usage

| Container / Algorithm | Where Used | Purpose |
|-----------------------|-----------|---------|
| `std::vector<Student>` | `main.cpp` (global) | Stores all students |
| `std::vector<Course>` | `Student` class | Stores enrolled courses |
| `std::sort()` | `sortStudentsByGPA()` | Sorts by GPA descending |
| Iterator + `erase()` | `removeStudent()` | Safe deletion by ID |

---

## Known Limitations

- **No persistence** — all data is stored in memory and lost on exit
- **No file I/O** — data cannot be saved or loaded from disk
- **Linear search** — O(n) lookups; suitable for small datasets
- **Single-user** — no concurrent access or authentication

---

## Future Enhancements

- File persistence (save/load student data to `.csv` or `.txt`)
- Automatic GPA calculation from course grades and credit hours
- Support for multiple semesters / terms
- Search by student name (string matching)
- Input validation for non-numeric menu entries (currently causes undefined behavior)
