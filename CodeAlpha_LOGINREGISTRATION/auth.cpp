#include <iostream>
#include <fstream>
#include <string>
#include "auth.h"

using namespace std;

// Check if username already exists
bool userExists(const string& username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    file.close();
    return false;
}

// Registration function
void registerUser() {
    string username, password;

    cout << "\n=== User Registration ===\n";
    cout << "Enter username: ";
    cin >> username;

    // Input validation
    if (username.length() < 3) {
        cout << "Error: Username must be at least 3 characters long.\n";
        return;
    }

    // Duplicate username check
    if (userExists(username)) {
        cout << "Error: Username already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (password.length() < 4) {
        cout << "Error: Password must be at least 4 characters long.\n";
        return;
    }

    // Store credentials in file (database file)
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    string user, pass;
    bool authenticated = false;

    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            authenticated = true;
            break;
        }
    }
    file.close();

    if (authenticated) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

// Authentication menu
void authMenu() {
    int choice;

    do {
        cout << "\n============================\n";
        cout << " Login & Registration System\n";
        cout << "============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);
}
