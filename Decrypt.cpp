#include "header.h"

// Оберненна до EncryptBlock
void DecryptBlock(uint8_t P[8], uint8_t C[8], const HIGHT& hight) { 

    //  4)
    uint8_t X[8];
    X[0] = C[0] - hight.WK[4];
    X[1] = C[1];
    X[2] = C[2] ^ hight.WK[5];
    X[3] = C[3];
    X[4] = C[4] - hight.WK[6];
    X[5] = C[5];
    X[6] = C[6] ^ hight.WK[7];
    X[7] = C[7];

    // i = 31
    uint8_t temp[8];

    temp[0] = X[0];
    temp[1] = X[1] - (F1(X[0]) ^ hight.SK[124]);
    temp[2] = X[2];
    temp[3] = X[3] ^ (uint8_t)(F0(X[2]) + hight.SK[125]);
    temp[4] = X[4];
    temp[5] = X[5] - (F1(X[4]) ^ hight.SK[126]);
    temp[6] = X[6];
    temp[7] = X[7] ^ (uint8_t)(F0(X[6]) + hight.SK[127]);

    for (int j = 0; j < 8; j++) {
        X[j] = temp[j];
    }

    //  3) i = 0 to 30
    for (int i = 30; i >= 0; i--) {
        uint8_t temp[8];

        temp[0] = X[1];
        temp[1] = X[2] - (F1(X[1]) ^ hight.SK[4 * i]);
        temp[2] = X[3];
        temp[3] = X[4] ^ (uint8_t)(F0(X[3]) + hight.SK[4 * i + 1]);
        temp[4] = X[5];
        temp[5] = X[6] - (F1(X[5]) ^ hight.SK[4 * i + 2]);
        temp[6] = X[7];
        temp[7] = X[0] ^ (uint8_t)(F0(X[7]) + hight.SK[4 * i + 3]);

        for (int j = 0; j < 8; j++) {
            X[j] = temp[j];
        }
    }

    // 2)
    P[0] = X[0] - hight.WK[0];
    P[1] = X[1];
    P[2] = X[2] ^ hight.WK[1];
    P[3] = X[3];
    P[4] = X[4] - hight.WK[2];
    P[5] = X[5];
    P[6] = X[6] ^ hight.WK[3];
    P[7] = X[7];
}

void Decrypt(const string& InputName, const string& OutputName, const string& KeyName) {
    ifstream InputFile(InputName, ios::binary);
    if (!InputFile) {
        cout << "Error: could not open file \"" << InputName << "\"\n";
        return;
    }

    ifstream KeyFile(KeyName, ios::binary);
    if (!KeyFile) {
        cout << "Error: could not open file \"" << KeyName << "\"\n";
        return;
    }

    ofstream OutputFile(OutputName, ios::binary);
    if (!OutputFile) {
        cout << "Error: could not create file \"" << OutputName << "\"\n";
        return;
    }

    cout << "Decoding complete. Result saved to \"" << OutputName << "\"\n";
}