#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class HIGHT {
public:
    uint8_t WK[8];
    uint8_t SK[128];
};    

// hight_fun.cpp

uint8_t F0(uint8_t x);
uint8_t F1(uint8_t x);
string Hex_convert(const vector<uint8_t>& data);
void GenerateRoundKeys(const uint8_t key[16], HIGHT& hight);

// Encrypt.cpp

void Encrypt(const string& InputName, const string& OutputName, const string& KeyName);


// Decrypt.cpp

void Decrypt(const string& InputName, const string& OutputName, const string& KeyName);