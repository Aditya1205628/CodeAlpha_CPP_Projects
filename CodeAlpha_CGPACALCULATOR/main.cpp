#include <iostream>
#include "cgpa.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n=========================\n";
        cout << "      C++Project Menu\n";
        cout << "=========================\n";
        cout << "1. CGPA Calculator\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cgpaCalculator();
                break;

            case 0:
                cout << "\nExiting program. Thank you!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
