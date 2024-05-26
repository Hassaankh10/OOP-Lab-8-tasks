#include <iostream>
using namespace std;

class Account
{
private:
    double balance;

public:
    Account(double);
    void credit(double);
    bool debit(double);
    double getBalance() const;
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double, double);
    double calculateInterest() const;
};

class CheckingAccount : public Account
{
private:
    double feeCharged;

public:
    CheckingAccount(double, double);
    void credit(double);
    bool debit(double);
};

Account::Account(double initialBalance)
{
    balance = (initialBalance < 0.0) ? 0.0 : initialBalance;
}

void Account::credit(double amount)
{
    balance += amount;
}

bool Account::debit(double amount)
{
    if (balance < amount)
    {
        cout << "Debit amount exceeded account balance" << endl;
        return false;
    }
    balance -= amount;
    return true;
}

double Account::getBalance() const
{
    return balance;
}

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance)
{
    interestRate = (rate < 0.0) ? 0.0 : rate;
}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}

CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance)
{
    feeCharged = (fee < 0.0) ? 0.0 : fee;
}

void CheckingAccount::credit(double amount)
{
    Account::credit(amount - feeCharged);
}

bool CheckingAccount::debit(double amount)
{
    if (Account::debit(amount))
    {
        Account::debit(feeCharged);
        return true;
    }
    return false;
}

int main()
{
    Account acc(100.0);
    SavingsAccount savingsAcc(500.0, 0.05);
    CheckingAccount checkingAcc(200.0, 2.0);

    cout << "Initial account balance: " << acc.getBalance() << endl;
    acc.credit(50.0);
    cout << "After crediting: " << acc.getBalance() << endl;
    acc.debit(30.0);
    cout << "After debiting: " << acc.getBalance() << endl;

    cout << "Initial savings account balance: " << savingsAcc.getBalance() << endl;
    double interest = savingsAcc.calculateInterest();
    savingsAcc.credit(interest);
    cout << "After adding interest: " << savingsAcc.getBalance() << endl;

    cout << "Initial checking account balance: " << checkingAcc.getBalance() << endl;
    checkingAcc.credit(100.0);
    cout << "After crediting to checking account: " << checkingAcc.getBalance() << endl;
    checkingAcc.debit(50.0);
    cout << "After debiting from checking account: " << checkingAcc.getBalance() << endl;

    return 0;
}
