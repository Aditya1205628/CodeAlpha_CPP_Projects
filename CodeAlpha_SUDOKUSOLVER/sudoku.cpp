#include <iostream>
#include "sudoku.h"

using namespace std;

// Check if number can be placed
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check row & column
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(int grid[9][9]) {
    int row, col;
    bool emptyFound = false;

    // Find empty cell
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound)
            break;
    }

    // If no empty cell, puzzle solved
    if (!emptyFound)
        return true;

    // Try numbers 1–9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // Backtrack
        }
    }

    return false;
}

// Input Sudoku grid
void inputGrid(int grid[9][9]) {
    cout << "Enter Sudoku Grid (use 0 for empty cells):\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
}

// Print Sudoku grid
void printGrid(int grid[9][9]) {
    cout << "\nSolved Sudoku Grid:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
