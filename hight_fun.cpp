#include "Class.h"

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