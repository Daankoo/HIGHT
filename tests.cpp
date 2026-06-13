#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include "header.h"

using namespace std;

vector<uint8_t> HexToBytes(const string& hex) {
    vector<uint8_t> bytes;
    for (size_t i = 0; i < hex.size(); i += 2) {
        bytes.push_back((uint8_t)stoul(hex.substr(i, 2), nullptr, 16));
    }
    return bytes;
}

void RunTests() {
    struct TestVector { string key, pt, ct; };

    vector<TestVector> vectors = {
        {"00112233445566778899aabbccddeeff", "0000000000000000", "00f418aed94f03f2"},
        {"ffeeddccbbaa99887766554433221100", "0011223344556677", "23ce9f72e543e6d8"},
        {"000102030405060708090a0b0c0d0e0f", "0123456789abcdef", "7a6fb2a28d23f466"},
        {"28dbc3bc49ffd87dcfa509b11d422be7", "b41e6be2eba84a14", "cc047a75209c1fc6"}
    };

    bool allPassed = true;

    for (size_t i = 0; i < vectors.size(); i++) {
        vector<uint8_t> key_vec = HexToBytes(vectors[i].key);
        vector<uint8_t> pt_vec  = HexToBytes(vectors[i].pt);
        vector<uint8_t> ct_vec  = HexToBytes(vectors[i].ct);

        uint8_t key[16];
        for (int j = 0; j < 16; j++) key[j] = key_vec[j];

        bool encPass = (EncryptData(pt_vec, key) == ct_vec);
        bool decPass = (DecryptData(ct_vec, key) == pt_vec);

        if (encPass && decPass) {
            cout << "Test " << i + 1 << " PASSED\n";
        } else {
            cout << "Test " << i + 1 << " FAILED\n";
            allPassed = false;
        }
    }

    if (allPassed) cout << "All tests passed.\n";
}

int main() {
    RunTests();
    return 0;
}