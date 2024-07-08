#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;

class Bank {
private:
    int pin;
    float balance;
    string id, password, firstName, lastName, address, phone;

public:
    void menu();
    void bankOperations();
    void atmOperations();
    void addUser();
    void existingUser();
    void depositMoney();
    void withdrawMoney();
    void transferFunds();
    void payBill();
    void searchUser();
    void editUser();
    void deleteUser();
    void showAllUsers();
    void showAllPayments();
    void checkBalance();
    void atmWithdraw();
    void viewAccountDetails();
};

void Bank::menu() {
    while (true) {
        int choice;
        cout << "\n\n\t\t\tMain Menu";
        cout << "\n1. Bank Operations";
        cout << "\n2. ATM Operations";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                bankOperations();
                break;
            case 2:
                atmOperations();
                break;
            case 3:
                exit(0);
            default:
                cout << "\nInvalid Choice! Please try again.";
                break;
        }
        getch();
    }
}

void Bank::bankOperations() {
    while (true) {
        int choice;
        cout << "\n\n\t\t\tBank Operations";
        cout << "\n1. Add New User";
        cout << "\n2. Existing User";
        cout << "\n3. Deposit";
        cout << "\n4. Withdraw";
        cout << "\n5. Transfer";
        cout << "\n6. Bill Payment";
        cout << "\n7. Search User";
        cout << "\n8. Edit User";
        cout << "\n9. Delete User";
        cout << "\n10. Show All Users";
        cout << "\n11. Show All Payments";
        cout << "\n12. Back to Main Menu";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                existingUser();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                transferFunds();
                break;
            case 6:
                payBill();
                break;
            case 7:
                searchUser();
                break;
            case 8:
                editUser();
                break;
            case 9:
                deleteUser();
                break;
            case 10:
                showAllUsers();
                break;
            case 11:
                showAllPayments();
                break;
            case 12:
                return;
            default:
                cout << "\nInvalid Choice! Please try again.";
                break;
        }
        getch();
    }
}

void Bank::atmOperations() {
    while (true) {
        int choice;
        cout << "\n\n\t\t\tATM Operations";
        cout << "\n1. Check Balance";
        cout << "\n2. Withdraw";
        cout << "\n3. Account Details";
        cout << "\n4. Back to Main Menu";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                atmWithdraw();
                break;
            case 3:
                viewAccountDetails();
                break;
            case 4:
                return;
            default:
                cout << "\nInvalid Choice! Please try again.";
                break;
        }
        getch();
    }
}

void Bank::addUser() {
    fstream file;
    cout << "\n\n\t\t\tAdd New User";
    cout << "\nEnter User ID: ";
    cin >> id;
    cout << "\nEnter First Name: ";
    cin >> firstName;
    cout << "\nEnter Last Name: ";
    cin >> lastName;
    cout << "\nEnter Pin Code (5 digits): ";
    cin >> pin;
    cout << "\nEnter Password (5 characters): ";
    cin >> password;
    cout << "\nEnter Phone Number: ";
    cin >> phone;
    cout << "\nEnter Address: ";
    cin >> address;
    cout << "\nEnter Initial Balance: ";
    cin >> balance;

    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance << endl;
        file.close();
    } else {
        string tempId;
        file >> tempId;
        while (file) {
            if (tempId == id) {
                cout << "\nUser ID already exists, please try another ID.";
                getch();
                return;
            }
            file >> tempId;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
        file.close();
    }
    cout << "\nNew user added successfully.";
}

void Bank::existingUser() {
    fstream file;
    string tempId;
    int tempPin;
    cout << "\n\n\t\t\tExisting User Information";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Pin Code: ";
    cin >> tempPin;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        string tempFirstName, tempLastName, tempPassword, tempPhone, tempAddress;
        float tempBalance;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (tempId == id && tempPin == pin) {
                cout << "\nUser ID: " << id;
                cout << "\nFirst Name: " << firstName;
                cout << "\nLast Name: " << lastName;
                cout << "\nPin Code: " << pin;
                cout << "\nPassword: " << password;
                cout << "\nPhone Number: " << phone;
                cout << "\nAddress: " << address;
                cout << "\nBalance: " << balance;
                return;
            }
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        cout << "\nNo such user exists.";
    }
    file.close();
}

void Bank::depositMoney() {
    fstream file, tempFile;
    string tempId;
    float depositAmount;
    cout << "\n\n\t\t\tDeposit Amount";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Amount to Deposit: ";
    cin >> depositAmount;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (tempId == id) {
                balance += depositAmount;
                cout << "\nCurrent Updated Balance: " << balance;
            }
            tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        cout << "\nDeposit successful.";
    }
}

void Bank::withdrawMoney() {
    fstream file, tempFile;
    string tempId;
    float withdrawAmount;
    cout << "\n\n\t\t\tWithdraw Amount";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Amount to Withdraw: ";
    cin >> withdrawAmount;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (tempId == id) {
                if (withdrawAmount <= balance) {
                    balance -= withdrawAmount;
                    cout << "\nCurrent Updated Balance: " << balance;
                } else {
                    cout << "\nInsufficient Funds.";
                }
            }
            tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        cout << "\nWithdrawal successful.";
    }
}

void Bank::transferFunds() {
    fstream file, tempFile;
    string senderId, receiverId;
    float transferAmount;
    cout << "\n\n\t\t\tTransfer Funds";
    cout << "\nEnter Sender User ID: ";
    cin >> senderId;
    cout << "\nEnter Receiver User ID: ";
    cin >> receiverId;
    cout << "\nEnter Amount to Transfer: ";
    cin >> transferAmount;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == senderId && transferAmount <= balance) found++;
            if (id == receiverId) found++;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        if (found == 2) {
            tempFile.open("temp.txt", ios::app | ios::out);
            file.open("bank.txt", ios::in);
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
            while (file) {
                if (id == senderId) balance -= transferAmount;
                if (id == receiverId) balance += transferAmount;
                tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
                file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
            }
            file.close();
            tempFile.close();
            remove("bank.txt");
            rename("temp.txt", "bank.txt");
            cout << "\nTransfer successful.";
        } else {
            cout << "\nInvalid IDs or Amount.";
        }
    }
}

void Bank::payBill() {
    fstream file, tempFile, billFile;
    string tempId, billName;
    float billAmount;
    SYSTEMTIME time;
    GetLocalTime(&time);
    cout << "\n\n\t\t\tPay Bill";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Bill Name: ";
    cin >> billName;
    cout << "\nEnter Bill Amount: ";
    cin >> billAmount;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId && balance >= billAmount) {
                balance -= billAmount;
                found++;
            }
            tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        if (found == 1) {
            billFile.open("bill.txt", ios::app | ios::out);
            billFile << " " << tempId << " " << billName << " " << billAmount << " " << time.wDay << " " << time.wMonth << " " << time.wYear;
            billFile.close();
            cout << "\nBill paid successfully.";
        } else {
            cout << "\nInvalid ID or Amount.";
        }
    }
}

void Bank::searchUser() {
    fstream file;
    string tempId;
    cout << "\n\n\t\t\tSearch User";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId) {
                found++;
                cout << "\nUser ID: " << id;
                cout << "\nFirst Name: " << firstName;
                cout << "\nLast Name: " << lastName;
                cout << "\nPin Code: " << pin;
                cout << "\nPassword: " << password;
                cout << "\nPhone Number: " << phone;
                cout << "\nAddress: " << address;
                cout << "\nBalance: " << balance;
            }
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        if (!found) cout << "\nUser ID not found.";
    }
}

void Bank::editUser() {
    fstream file, tempFile;
    string tempId;
    cout << "\n\n\t\t\tEdit User";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId) {
                found++;
                cout << "\nEnter New First Name: ";
                cin >> firstName;
                cout << "\nEnter New Last Name: ";
                cin >> lastName;
                cout << "\nEnter New Pin Code: ";
                cin >> pin;
                cout << "\nEnter New Password: ";
                cin >> password;
                cout << "\nEnter New Phone Number: ";
                cin >> phone;
                cout << "\nEnter New Address: ";
                cin >> address;
                cout << "\nUser record updated successfully.";
            }
            tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        if (found == 0) cout << "\nUser ID not found.";
    }
}

void Bank::deleteUser() {
    fstream file, tempFile;
    string tempId;
    cout << "\n\n\t\t\tDelete User";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId) {
                found++;
                cout << "\nUser record deleted successfully.";
            } else {
                tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            }
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        if (found == 0) cout << "\nUser ID not found.";
    }
}

void Bank::showAllUsers() {
    fstream file;
    cout << "\n\n\t\t\tAll Users";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            cout << "\nUser ID: " << id;
            cout << "\nFirst Name: " << firstName;
            cout << "\nLast Name: " << lastName;
            cout << "\nPin Code: " << pin;
            cout << "\nPassword: " << password;
            cout << "\nPhone Number: " << phone;
            cout << "\nAddress: " << address;
            cout << "\nBalance: " << balance;
            cout << "\n----------------------------------------";
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
    }
}

void Bank::showAllPayments() {
    fstream file;
    cout << "\n\n\t\t\tAll Payments";
    file.open("bill.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        string tempId, billName;
        float billAmount;
        int day, month, year;
        file >> tempId >> billName >> billAmount >> day >> month >> year;
        while (file) {
            cout << "\nUser ID: " << tempId;
            cout << "\nBill Name: " << billName;
            cout << "\nAmount: " << billAmount;
            cout << "\nDate: " << day << "/" << month << "/" << year;
            cout << "\n----------------------------------------";
            file >> tempId >> billName >> billAmount >> day >> month >> year;
        }
        file.close();
    }
}

void Bank::checkBalance() {
    fstream file;
    string tempId, tempPassword;
    int tempPin;
    cout << "\n\n\t\t\tCheck Balance";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Pin Code: ";
    cin >> tempPin;
    cout << "\nEnter Password: ";
    cin >> tempPassword;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId && pin == tempPin && password == tempPassword) {
                cout << "\nCurrent Balance: " << balance;
                return;
            }
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        cout << "\nInvalid User ID, Pin, or Password.";
    }
    file.close();
}

void Bank::atmWithdraw() {
    fstream file, tempFile;
    string tempId, tempPassword;
    int tempPin;
    float withdrawAmount;
    cout << "\n\n\t\t\tWithdraw";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Pin Code: ";
    cin >> tempPin;
    cout << "\nEnter Password: ";
    cin >> tempPassword;
    cout << "\nEnter Amount to Withdraw: ";
    cin >> withdrawAmount;
    file.open("bank.txt", ios::in);
    tempFile.open("temp.txt", ios::app | ios::out);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        int found = 0;
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId && pin == tempPin && password == tempPassword) {
                if (withdrawAmount <= balance) {
                    balance -= withdrawAmount;
                    found++;
                    cout << "\nCurrent Balance: " << balance;
                } else {
                    cout << "\nInsufficient Funds.";
                }
            }
            tempFile << " " << id << " " << firstName << " " << lastName << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        tempFile.close();
        remove("bank.txt");
        rename("temp.txt", "bank.txt");
        if (!found) cout << "\nInvalid User ID, Pin, or Password.";
    }
}

void Bank::viewAccountDetails() {
    fstream file;
    string tempId, tempPassword;
    int tempPin;
    cout << "\n\n\t\t\tAccount Details";
    cout << "\nEnter User ID: ";
    cin >> tempId;
    cout << "\nEnter Pin Code: ";
    cin >> tempPin;
    cout << "\nEnter Password: ";
    cin >> tempPassword;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening Error.";
    } else {
        file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        while (file) {
            if (id == tempId && pin == tempPin && password == tempPassword) {
                cout << "\nUser ID: " << id;
                cout << "\nFirst Name: " << firstName;
                cout << "\nLast Name: " << lastName;
                cout << "\nPin Code: " << pin;
                cout << "\nPassword: " << password;
                cout << "\nPhone Number: " << phone;
                cout << "\nAddress: " << address;
                cout << "\nBalance: " << balance;
                return;
            }
            file >> id >> firstName >> lastName >> pin >> password >> phone >> address >> balance;
        }
        cout << "\nInvalid User ID, Pin, or Password.";
    }
    file.close();
}

int main() {
    Bank bank;
    bank.menu();
    return 0;
}