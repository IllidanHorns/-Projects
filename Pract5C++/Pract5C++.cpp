#include <Windows.h>
#include <iostream>
#include <fcntl.h>

class BankAccount {
    friend bool transfer(BankAccount& account1, BankAccount& account2, double sum_of_transfer);
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    void deposit(double count) {
        if (count > 0) {
            this->balance += count;
        }
    }

    void withdraw(double count) {
        if (count > 0) {
            this->balance -= count;
        }
    }

    double getBalance() {
        return this->balance;
    }

    double getInterest() {
        if (interestRate > 0)
        {
            return balance * interestRate * (1.00 / 12.00);
        }
        else 
        {
            return 0;
        }
    }

    void setInterestRate(double _interestRate) {
        interestRate = _interestRate;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    BankAccount(int accountNumber, double balance) {
        if (accountNumber > 0 && balance > 0) {
            this->accountNumber = accountNumber;
            this->balance = balance;
        }
        else {
            std::cout << "Невозможно создать аккунт с данными параметрами!\n";
            this->accountNumber = NULL;
            this->balance = NULL;
        }
    }
};

bool transfer(BankAccount& account1, BankAccount& account2, double sum_of_transfer) {
    if (sum_of_transfer > 0) {
        if (account1.getBalance() >= sum_of_transfer) {
            account1.withdraw(sum_of_transfer);
            account2.deposit(sum_of_transfer);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    double balance_of_account;
    double deposit;

    std::cout << "Добро пожаловть в банк Денькофф!" << "\n";
    std::cout << "Введите баланс первого аккаунта: " << "\n";
    std::cin >> balance_of_account;
    BankAccount account1 = BankAccount(13, balance_of_account);
    std::cout << "Введите баланс второго аккаунта: " << "\n";
    std::cin >> balance_of_account;
    BankAccount account2 = BankAccount(14, balance_of_account);

    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Баланс - " << account1.getBalance() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Баланс - " << account2.getBalance() << "\n";

    std::cout << "Сумма пополнения 1 аккаунта: ";
    std::cin >> deposit;
    account1.deposit(deposit);
    std::cout << "Сумма пополнения 2 аккаунта: ";
    std::cin >> deposit;
    account2.deposit(deposit);

    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Баланс - " << account1.getBalance() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Баланс - " << account2.getBalance() << "\n";

    std::cout << "Сумма снятия 1 аккаунта: ";
    std::cin >> deposit;
    account1.withdraw(deposit);
    std::cout << "Сумма снятия 2 аккаунта: ";
    std::cin >> deposit;
    account2.withdraw(deposit);

    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Баланс - " << account1.getBalance() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Баланс - " << account2.getBalance() << "\n";

    std::cout << "Процентная ставка 1 акканта: ";
    std::cin >> deposit;
    account1.setInterestRate(deposit);
    std::cout << "Процентная ставка 2 аккаунта: ";
    std::cin >> deposit;
    account2.setInterestRate(deposit);

    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Процентный заработок - " << account1.getInterest() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Процентный заработок - " << account2.getInterest() << "\n";

    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Баланс - " << account1.getBalance() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Баланс - " << account2.getBalance() << "\n";

    std::cout << "Сумма перевода с 1 аккаунта на 2 - ";
    std::cin >> deposit;
    if (transfer(account1, account2, deposit) == true) {
        std::cout << "Перевод прошел успешно\n";
    }
    else {
        std::cout << "Перевод не прошел\n";
    }
    
    std::cout << "Номер первого аккканта - " << account1.getAccountNumber() << " Баланс - " << account1.getBalance() << "\n";
    std::cout << "Номер второго аккканта - " << account2.getAccountNumber() << " Баланс - " << account2.getBalance() << "\n";
}

