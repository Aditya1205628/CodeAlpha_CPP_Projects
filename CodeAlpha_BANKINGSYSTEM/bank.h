#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string customerName;
    double balance;

    Account(int accNo, string name, double bal);
    void deposit(double amount);
    bool withdraw(double amount);
};

void createAccount();
void depositMoney();
void withdrawMoney();
void transferMoney();
void viewAccount();
void bankingMenu();

#endif
