#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Ammount " << amount << " RS " << " SuccessFully in your AC";
    }

    void withdraw(double amount)
    {
        balance -= amount;
        cout << "Ammount " << amount << " RS " << " Withdraw from your AC";
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Ammount " << amount << " RS " << " SuccessFully in your AC";
    }

    void withdraw(double amount)
    {
        balance -= amount;
        cout << "Ammount " << amount << " RS " << " Withdraw from your AC";
    }
};

class FixTermAccount : public Account
{
private:
    double balance;

public:
    FixTermAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts)
    {
        this->accounts = accounts;
    }

    void processTransactions()
    {
        for (Account *acc : accounts)
        {
            acc->deposit(1000);

            try
            {
                acc->withdraw(500);
            }
            catch (const logic_error &e)
            {
                cout << "Exception: " << e.what() << endl;
            };
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixTermAccount());

    BankClient *client = new BankClient(accounts);
    client->processTransactions(); //  Throws exception when withdrawing from FixedTermAccount

    return 0;
}