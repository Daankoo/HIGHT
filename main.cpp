#include "HIGHT.h"

int main() {

    int choice;
    string key;

    key = "0F1E2D3C4B5A69780F1E2D3C4B5A6978"; // 128 á³ò

    uint8_t K[16] = {};
    
    for (int i = 0; i < 16; i++) {
        K[i] = (uint8_t)stoul(key.substr(i * 2, 2), nullptr, 16);
    }

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