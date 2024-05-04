#include <iostream>
#include <ctime>
#include <limits>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string timestamp;

    Transaction(string t, double a) : type(t), amount(a) {
        time_t now = time(0);
        timestamp = ctime(&now);
    }
};

class BankAccount {
private:
    int pin;
    double balance;
    vector<Transaction> transactionHistory;

public:
    BankAccount() : pin(0), balance(0.0) {
        createPin();
    }

    void createPin() {
        cout << "Create a four-digit PIN for your account: ";
        cin >> pin;

        if (pin < 1000 || pin > 9999 || cin.fail()) {
            cout << "Invalid PIN. Please enter a four-digit number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            createPin();
        }
    }

    void depositMoney() {
        double amount;
        cout << "Enter the amount to deposit: $";
        cin >> amount;

        if (cin.fail() || amount < 0) {
            cout << "Invalid amount. Please enter a valid amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        balance += amount;
        transactionHistory.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful. Your balance is now: $" << balance << endl;
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter the amount to withdraw: $";
        cin >> amount;

        if (cin.fail() || amount < 0 || amount > balance) {
            cout << "Invalid amount or insufficient balance. Please enter a valid amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        balance -= amount;
        transactionHistory.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal successful. Your balance is now: $" << balance << endl;
    }

    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    void sendMoney() {
        int userPIN;
        cout << "Enter your PIN to confirm the transaction: ";
        cin >> userPIN;

        if (userPIN != pin) {
            cout << "Invalid PIN. Transaction unsuccessful." << endl;
            return;
        }

        double amount;
        cout << "Enter the amount to send: $";
        cin >> amount;

        if (cin.fail() || amount < 0 || amount > balance) {
            cout << "Invalid amount or insufficient balance. Transaction unsuccessful." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        string recipientNumber;
        cout << "Enter the recipient's 10-digit mobile number: ";
        cin >> recipientNumber;

        if (recipientNumber.length() != 10 || !isdigit(recipientNumber[0]) ||
            (recipientNumber[0] != '6' && recipientNumber[0] != '7' &&
             recipientNumber[0] != '8' && recipientNumber[0] != '9')) {
            cout << "Invalid mobile number. Transaction unsuccessful." << endl;
            return;
        }

        balance -= amount;
        transactionHistory.push_back(Transaction("Send Money", amount));
        cout << "Transaction successful. Your balance is now: $" << balance << endl;
    }

    const vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }
};

int main() {
srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    BankAccount userAccount;

    int choice;
    do {
        cout << "\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Send Money\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                userAccount.depositMoney();
                break;
            case 2:
                userAccount.withdrawMoney();
                break;
            case 3:
                userAccount.checkBalance();
                break;
            case 4:
                userAccount.sendMoney();
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    cout << "\nTransaction History:\n";
    for (const auto& transaction : userAccount.getTransactionHistory()) {
        cout << transaction.type << " - Amount: $" << transaction.amount << " - Timestamp: " << transaction.timestamp;
        cout << endl;
    }

    return 0;
}
