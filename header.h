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
void GenerateRoundKeys(const uint8_t key[16], HIGHT& hight);

// Encrypt.cpp
void EncryptBlock(uint8_t P[8], uint8_t C[8], const HIGHT& hight);
void Encrypt(const string& InputName, const string& OutputName, const string& KeyName);

// Decrypt.cpp
void DecryptBlock(uint8_t Ñ[8], uint8_t P[8], const HIGHT& hight);
void Decrypt(const string& InputName, const string& OutputName, const string& KeyName);