#include <iostream>
#include "sudoku.h"

using namespace std;

int main() {
    int grid[9][9];

    inputGrid(grid);

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists for this Sudoku.\n";
    }

    return 0;
}
