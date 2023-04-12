#include <iostream>
#include <string>

using namespace std;

int main() {
    // Default pin and balance
    const int DEFAULT_PIN = 0000;
    int pin = DEFAULT_PIN;
    const int DEFAULT_BALANCE = 1000;
    int balance = DEFAULT_BALANCE;
    
    // Authentication
    int attempts = 0;
    int input_pin;
    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> input_pin;
        if (input_pin == pin) {
            break;
        }
        else {
            attempts++;
            cout << "Incorrect PIN. Please try again." << endl;
        }
    }
    if (attempts == 3) {
        cout << "Too many incorrect attempts. Exiting program." << endl;
        return 0;
    }
    
    // Main Menu 
    int choice;
    do {
        cout << "Please select an option:" << endl;
        cout << "1. Reset PIN" << endl;
        cout << "2. Check balance" << endl;
        cout << "3. Send money" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        
        switch (choice) {
            // Resetting/changing Pin
            case 1: {
                cout << "Enter new PIN: ";
                cin >> pin;
                cout << "PIN changed successfully." << endl;
                break;
            }
            // Checking balance
            case 2: {
                cout << "Your balance is $" << balance << endl;
                break;
            }
            // Sending money
            case 3: {
                string receiver;
                string reference;
                int amount;
                cout << "Enter receiver's number: ";
                cin >> receiver;
                cout <<"Enter reference: ";
                cin >> reference;
                cout << "Enter amount to send: $";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient funds. Please try again." << endl;
                }
                else {
                    balance -= amount;
                    cout << "$" << amount << " sent to " << receiver << "." << endl;
                    cout << "Thank for chossing moble momey. Transfer successful. Your new balance is $" << balance << endl;
                }
                break;
            }
            // Exiting program
            case 4: {
                cout << "Exiting program. Thank you for using our service!" << endl;
                break;
            }
            // Invalid input
            default: {
                cout << "Invalid input. Please try again." << endl;
                break;
            }
        }
    } while (choice != 4);
    
    return 0;
}

