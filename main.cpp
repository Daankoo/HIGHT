#include "header.h"

int main() {

    int choice;

    cout << "--- HIGHT ---\n";
    cout << "1. Encrypt file\n";
    cout << "2. Decrypt file\n";
    cout << "Select: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Error choice!\n";
        return -1;
    }

    if (choice == 1) {
        string InputName, OutputName, KeyName;
        
        cout << "\n--- Encrypt ---\n";
        cout << "Enter input file name: ";
        cin >> InputName;
        
        cout << "Enter file with key name: ";
        cin >> KeyName;

        cout << "Enter output file name (press Enter to skip): ";
        cin.ignore();
        getline(cin, OutputName);

        if (OutputName.empty()) {
            OutputName = "Output_Encrypt.txt";
            cout << "Output file: " << OutputName << "\n";
        }

        Encrypt(InputName, OutputName, KeyName);
    }

    else if (choice == 2) {
        string InputName, OutputName, KeyName;
        
        cout << "\n--- Decrypt ---\n";
        cout << "Enter input file name: ";
        cin >> InputName;

        cout << "Enter file with key name: ";
        cin >> KeyName;

        cout << "Enter output file name (press Enter to skip): ";
        cin.ignore();
        getline(cin, OutputName);

        if (OutputName.empty()) {
            OutputName = "Output_Decrypt.txt";
            cout << "Output file: " << OutputName << "\n";
        }

        Decrypt(InputName, OutputName, KeyName);
    }

    return 0;
}