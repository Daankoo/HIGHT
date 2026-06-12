#include "HIGHT.h"

uint8_t F0(uint8_t x) {
    return ((x << 1) | (x >> 7)) ^ ((x << 2) | (x >> 6)) ^ ((x << 7) | (x >> 1));
}

uint8_t F1(uint8_t x) {
    return ((x << 3) | (x >> 5)) ^ ((x << 4) | (x >> 4)) ^ ((x << 6) | (x >> 2));
}

string Hex_convert(const vector<uint8_t>& data) {
    string Res = "";
    string Symbol = "0123456789ABCDEF";

    for (int i = 0; i < data.size(); i++) {
        Res += Symbol[data[i] / 16];
        Res += Symbol[data[i] % 16];
        Res += " ";
    }

    return Res;
}

void GenerateRoundKeys(const uint8_t key[16], HIGHT& hight) {

    hight.WK[0] = key[12];
    hight.WK[1] = key[13];
    hight.WK[2] = key[14];
    hight.WK[3] = key[15];

    hight.WK[4] = key[0];
    hight.WK[5] = key[1];
    hight.WK[6] = key[2];
    hight.WK[7] = key[3];

    uint8_t s[134] = { 0, 1, 0, 1, 1, 0, 1 };

    for (int i = 1; i <= 127; i++) {
        s[i + 6] = s[i + 2] ^ s[i - 1];
    }

    uint8_t delta[128] = {};  

    for (int i = 0; i < 128; i++) {
        delta[i] = (s[i + 6] << 6) | (s[i + 5] << 5) | (s[i + 4] << 4) | (s[i + 3] << 3) | (s[i + 2] << 2) | (s[i + 1] << 1) | s[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            hight.SK[16 * i + j] = key[(j - i + 8) % 8] + delta[16 * i + j];
            hight.SK[16 * i + j + 8] = key[(j - i + 8) % 8 + 8] + delta[16 * i + j + 8];
        }
    }
}