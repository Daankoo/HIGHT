#include "class.h"

uint8_t F0(uint8_t x) {
    return ((x << 1) | (x >> 7)) ^ ((x << 2) | (x >> 6)) ^ ((x << 7) | (x >> 1));
}

uint8_t F1(uint8_t x) {
    return ((x << 3) | (x >> 5)) ^ ((x << 4) | (x >> 4)) ^ ((x << 6) | (x >> 2));
}