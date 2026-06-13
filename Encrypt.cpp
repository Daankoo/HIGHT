#include "header.h"

void EncryptBlock(uint8_t P[8], uint8_t C[8], const HIGHT& hight) {

//  2)
    uint8_t X[8];
    X[0] = P[0] + hight.WK[0];
    X[1] = P[1];
    X[2] = P[2] ^ hight.WK[1];
    X[3] = P[3];
    X[4] = P[4] + hight.WK[2];
    X[5] = P[5];
    X[6] = P[6] ^ hight.WK[3];
    X[7] = P[7];

//  3) i = 0 to 30
    for (int i = 0; i <= 30; i++) {
        uint8_t temp[8];

        temp[0] = X[7] ^ (uint8_t)(F0(X[6]) + hight.SK[4 * i + 3]);
        temp[1] = X[0];
        temp[2] = X[1] + (F1(X[0]) ^ hight.SK[4 * i]);
        temp[3] = X[2];
        temp[4] = X[3] ^ (uint8_t)(F0(X[2]) + hight.SK[4 * i + 1]);
        temp[5] = X[4];
        temp[6] = X[5] + (F1(X[4]) ^ hight.SK[4 * i + 2]);
        temp[7] = X[6];

        for (int j = 0; j < 8; j++) {
            X[j] = temp[j];
        }
    }

// i = 31
    uint8_t temp[8];

    temp[0] = X[0];
    temp[1] = X[1] + (F1(X[0]) ^ hight.SK[124]);
    temp[2] = X[2];
    temp[3] = X[3] ^ (uint8_t)(F0(X[2]) + hight.SK[125]);
    temp[4] = X[4];
    temp[5] = X[5] + (F1(X[4]) ^ hight.SK[126]);
    temp[6] = X[6];
    temp[7] = X[7] ^ (uint8_t)(F0(X[6]) + hight.SK[127]);

    for (int j = 0; j < 8; j++) {
        X[j] = temp[j];
    }

// 4)
    C[0] = X[0] + hight.WK[4];
    C[1] = X[1];
    C[2] = X[2] ^ hight.WK[5];
    C[3] = X[3];
    C[4] = X[4] + hight.WK[6];
    C[5] = X[5];
    C[6] = X[6] ^ hight.WK[7];
    C[7] = X[7];
}

void Encrypt(const string& InputName, const string& OutputName, const string& KeyName) {
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

    uint8_t key[16] = { 0 };
    KeyFile.read((char*)key, 16);

    if (KeyFile.gcount() < 16) {
        cout << "Error: Key file < 16!\n";
        return;
    }

    HIGHT hight;
    GenerateRoundKeys(key, hight);

    uint8_t InputBlock[8] = { 0 };
    uint8_t OutputBlock[8] = { 0 };

    while (InputFile.read((char*)InputBlock, 8)) {
        EncryptBlock(InputBlock, OutputBlock, hight);
        OutputFile.write((char*)OutputBlock, 8);
    }

    int CountBite = InputFile.gcount();
    if (CountBite > 0) {

        uint8_t PadSize = 8 - CountBite;

        for (int i = CountBite; i < 8; i++) {
            InputBlock[i] = 0x00;
        }

        EncryptBlock(InputBlock, OutputBlock, hight);

        OutputBlock = OutpuBlock << PadSize;

        OutputFile.write((char*)OutputBlock, 8);
    }

    cout << "Encoding complete. Result saved to \"" << OutputName << "\"\n";
}