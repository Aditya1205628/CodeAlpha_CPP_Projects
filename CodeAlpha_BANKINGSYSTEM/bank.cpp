#include <iostream>
#include <fstream>
#include "bank.h"

using namespace std;

// Account constructor
Account::Account(int accNo, string name, double bal) {
    accountNumber = accNo;
    customerName = name;
    balance = bal;
}

// Deposit
void Account::deposit(double amount) {
    balance += amount;
}

// Withdraw
bool Account::withdraw(double amount) {
    if (amount > balance)
        return false;
    balance -= amount;
    return true;
}

// Create account
void createAccount() {
    int accNo;
    string name;
    double balance;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> balance;

    ofstream file("accounts.txt", ios::app);
    file << accNo << " " << name << " " << balance << endl;
    file.close();

    cout << "Account created successfully!\n";
}

// Deposit money
void depositMoney() {
    int accNo;
    double amount;
    int a;
    string name;
    double balance;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    ifstream inFile("accounts.txt");
    ofstream outFile("temp.txt");

    while (inFile >> a >> name >> balance) {
        if (a == accNo) {
            balance += amount;
            found = true;

            ofstream trans("transactions.txt", ios::app);
            trans << accNo << " Deposit " << amount << endl;
            trans.close();
        }
        outFile << a << " " << name << " " << balance << endl;
    }

    inFile.close();
    outFile.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Deposit successful!\n";
    else
        cout << "Account not found!\n";
}

// Withdraw money
void withdrawMoney() {
    int accNo;
    double amount;
    int a;
    string name;
    double balance;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    ifstream inFile("accounts.txt");
    ofstream outFile("temp.txt");

    while (inFile >> a >> name >> balance) {
        if (a == accNo && balance >= amount) {
            balance -= amount;
            found = true;

            ofstream trans("transactions.txt", ios::app);
            trans << accNo << " Withdraw " << amount << endl;
            trans.close();
        }
        outFile << a << " " << name << " " << balance << endl;
    }

    inFile.close();
    outFile.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Withdrawal successful!\n";
    else
        cout << "Insufficient balance or account not found!\n";
}

// Transfer money
void transferMoney() {
    cout << "Feature coming soon (optional enhancement).\n";
}

// View account details
void viewAccount() {
    int accNo;
    int a;
    string name;
    double balance;

    cout << "Enter Account Number: ";
    cin >> accNo;

    ifstream file("accounts.txt");
    bool found = false;

    while (file >> a >> name >> balance) {
        if (a == accNo) {
            cout << "\nAccount Number: " << a;
            cout << "\nCustomer Name: " << name;
            cout << "\nBalance: " << balance << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "Account not found!\n";
}

// Menu
void bankingMenu() {
    int choice;
    do {
        cout << "\n============================\n";
        cout << "       Banking System\n";
        cout << "============================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: viewAccount(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
