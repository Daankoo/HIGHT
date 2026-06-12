#include "Class.h"

void Encrypt(const string& InputName, const string& OutputName) {
    ifstream InputFile(InputName, ios::binary);
    if (!InputFile) {
        cout << "Error: could not open file \"" << InputName << "\"\n";
        return;
    }

    ofstream OutputFile(OutputName);
    if (!OutputFile) {
        cout << "Error: could not create file \"" << OutputName << "\"\n";
        return;
    }

    cout << "Encoding complete. Result saved to \"" << OutputName << "\"\n";
}