# Gradebook
Overview
Gradebook is a C++ console application that manages student records and their grades. It allows users to add students, assign grades, display individual student information, and list all students with their grades. The program uses a std::map to store student data, with student IDs as keys and Student objects as values. The application features a menu-driven interface for user interaction and includes name normalization for consistent formatting.
Features
•  Add Student: Add a new student with an ID, first name, and last name. Duplicate IDs are not allowed.
•  Add Grade: Assign a grade (0–100) to a student by ID. Invalid grades are rejected with an error message.
•  Show Student: Display a student’s full name and grades by ID.
•  Show All Students: List all students with their IDs, names, and grades.
•  Name Normalization: Capitalizes the first letter of first names and converts last names to uppercase (e.g., “john doe” becomes “John DOE”).
•  Grade Validation: Ensures grades are within the valid range (0–100).
•  Average Grade Calculation: Computes the average grade for a student (returns 0.0 if no grades exist).
Requirements
•  C++ Compiler: A C++ compiler supporting C++11 or later (e.g., g++, clang++, or MSVC).
•  Standard Library: The program uses standard C++ libraries (<iostream>, <string>, <vector>, <map>, <algorithm>, <numeric>, <cctype>).
•  Operating System: Compatible with any OS that supports a C++ compiler (Windows, Linux, macOS).
Installation
1.  Clone or Download: Obtain the source code (e.g., main.cpp).
2.  Compile: Use a C++ compiler to build the program. For example, with g++:
