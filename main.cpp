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
        string InputName, OutputName;
        cout << "\n--- Encrypt ---\n";
        cout << "Enter input file name: ";

        cout << "Enter output file name (press Enter to skip): ";

        if (OutputName.empty()) {
            OutputName = "Output_Encrypt.txt";
            cout << "Output file: " << OutputName << "\n";
        }

        Encrypt(InputName, OutputName);
    }

    else if (choice == 2) {
        string InputName, OutputName;
        cout << "\n--- Decrypt ---\n";
        cout << "Enter input file name: ";

        cout << "Enter output file name (press Enter to skip): ";

        if (OutputName.empty()) {
            OutputName = "Output_Decrypt.txt";
            cout << "Output file: " << OutputName << "\n";
        }

        Decrypt(InputName, OutputName);
    }

    return 0;
}