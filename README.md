# CodeAlpha C++ Projects

This repository contains four C++ projects that I developed as part of the CodeAlpha internship tasks.
Each project is kept in a separate folder for clarity and easy execution.

## Projects

### 1. CodeAlpha_CGPACALCULATOR
A console-based CGPA calculator that supports multiple semesters and calculates GPA using grades and credit hours.

### 2. CodeAlpha_LOGINREGISTRATION
A simple login and registration system using file handling.
It allows user registration, prevents duplicate usernames, and verifies login credentials.

### 3. CodeAlpha_SUDOKUSOLVER
A 9×9 Sudoku solver implemented using the backtracking algorithm.
Empty cells are filled by recursively checking Sudoku rules.

### 4. CodeAlpha_BANKINGSYSTEM
A basic banking system that allows account creation, deposit, withdrawal, and viewing account details.
The project uses object-oriented programming and file handling.

## How to Run the Projects

Each project can be compiled and run separately using g++.

Example commands are provided inside each project folder.

## Tools Used
- C++
- g++ (MinGW)
- Visual Studio Code

## Author
Aditya Dilip Pal

This repository is created for learning, academic submission, and internship evaluation.

▶️ HOW TO EXECUTE (RUN) EACH PROJECT

🔹 1. Run CGPA Calculator
cd CodeAlpha_CGPACALCULATOR
g++ main.cpp cgpa.cpp -o cgpa
./cgpa

🔹 2. Run Login & Registration System
cd CodeAlpha_LOGINREGISTRATION
g++ main.cpp auth.cpp -o auth
./auth

🔹 3. Run Sudoku Solver
cd CodeAlpha_SUDOKUSOLVER
g++ main.cpp sudoku.cpp -o sudoku
./sudoku


Then enter the Sudoku grid using 0 for empty cells.

🔹 4. Run Banking System
cd CodeAlpha_BANKINGSYSTEM
g++ main.cpp bank.cpp -o bank
./bank
