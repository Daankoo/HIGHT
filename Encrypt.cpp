#include "HIGHT.h"

void Encrypt(const string& InputName, const string& OutputName, const string& KeyName) {
    ifstream InputFile(InputName, ios::binary);
    if (!InputFile) {
        cout << "Error: could not open file \"" << InputName << "\"\n";
        return;
    }

    ifstream KeyFile(KeyName);
    if (!KeyFile) {
        cout << "Error: could not open file \"" << KeyName << "\"\n";
        return;
    }

    ofstream OutputFile(OutputName);
    if (!OutputFile) {
        cout << "Error: could not create file \"" << OutputName << "\"\n";
        return;
    }

    cout << "Encoding complete. Result saved to \"" << OutputName << "\"\n";
}