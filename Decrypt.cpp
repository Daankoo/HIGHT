#include "Ñlass.h"

void Decrypt(const string& InputName, const string& OutputName) {
    ifstream InputFile(InputName);
    if (!InputFile) {
        cout << "Error: could not open file \"" << InputName << "\"\n";
        return;
    }

    ofstream OutputFile(OutputName, ios::binary);
    if (!OutputFile) {
        cout << "Error: could not create file \"" << OutputName << "\"\n";
        return;
    }

    cout << "Decoding complete. Result saved to \"" << OutputName << "\"\n";
}