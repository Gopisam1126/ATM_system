#include <iostream>
using namespace std;

class Account {
    private:
        double balance;
        int secret_pin;

    public:
        string name;
        long int acc_no;

        friend double get_balance(const Account &acc);
        friend int get_secret_key(const Account &acc);

        Account(string n, long int a_no, double bal, int s_p) :
            name(n), acc_no(a_no), balance(bal), secret_pin(s_p) {}
};

double get_balance(const Account &acc) {
    return acc.balance;
}

int get_secret_key(const Account &acc) {
    return acc.secret_pin;
}

class Transaction {
    private:
        double balance;
        int secret_pin;
        
    public:
        bool authorized;

        Transaction(const Account &acc, int entered_pin) :
            balance(get_balance(acc)),
            secret_pin(get_secret_key(acc))
        {
            authorized = (entered_pin == secret_pin);
        }

        void display_balance() {
            cout << "Your Account balance is: " << balance << endl;
        }

        void withdraw(double amount) {
            if (authorized) {
                if (amount > balance) {
                    cout << "Low balance... Exiting!" << endl;
                } else if (amount <= 0) {
                    cout << "Entered amount must be greater than zero... Exiting!" << endl;
                } else {
                    balance -= amount;
                    cout << "Transaction Successful. Please collect your money!" << endl;
                    cout << "Withdrew amount: " << amount << endl;
                    display_balance();
                }
            } else {
                cout << "Unauthorized transaction. Cannot proceed with withdrawal." << endl;
            }
        }
};

int main() {
    string name;
    long int acc_no;

    cout << "Enter your Name: ";
    getline(cin, name);

    cout << "Enter your Account Number: ";
    cin >> acc_no;

    Account myAcc(name, acc_no, 81200.0, 2254);

    int entered_pin;
    cout << "Enter your secret pin for account verification: ";
    cin >> entered_pin;

    Transaction trans(myAcc, entered_pin);

    if (!trans.authorized) {
        cout << "Account verification failed. Exiting ATM." << endl;
        return 0;
    }

    int choice;
    do {
        cout << "\nATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                trans.display_balance();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                trans.withdraw(amount);
                break;
            }
            case 3:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 3);

    return 0;
}
