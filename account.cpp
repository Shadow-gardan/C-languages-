#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> accountBalances;

void initializeAccounts() {
    accountBalances["Aman"] = 30000;
    accountBalances["Ram"] = 60000;
    accountBalances["Sam"] = 40000;
    accountBalances["Jack"] = 100000;
    accountBalances["Max"] = 45000;
}

void display(const string& name) {
    cout << "\n*----------- " << name << " -----------*\n";
    cout << "Current Balance: " << accountBalances[name] << "\n\n";
}

void Account_Holder() {
    string choice;
    int option, amount;

    while (true) {
        cout << "\nEnter your name: ";
        cin >> choice;

        // Capitalize first letter for consistency
        choice[0] = toupper(choice[0]);

        if (accountBalances.find(choice) == accountBalances.end()) {
            cout << "Invalid name. Please try again.\n";
            continue;
        }

        display(choice);

        cout << "1> Debit\n";
        cout << "2> Credit\n";
        cout << "0> Exit\n";
        cout << "What do you want to do? (1-Debit, 2-Credit, 0-Exit): ";
        cin >> option;

        if (option == 0) {
            cout << "Thank you for using our banking system!\n";
            break;
        }

        cout << "Enter amount: ";
        cin >> amount;

        if (option == 1) { // Debit
            if (accountBalances[choice] >= amount) {
                accountBalances[choice] -= amount;
                cout << "Amount debited successfully.\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        } else if (option == 2) { // Credit
            accountBalances[choice] += amount;
            cout << "Amount credited successfully.\n";
        } else {
            cout << "Invalid option.\n";
        }

        display(choice);
    }
}

int main() {
    initializeAccounts();  // Initialize balances first
    Account_Holder();      // Start the session
    return 0;
}

