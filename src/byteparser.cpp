#include "byteparser.hpp"

unsigned short int us_fromByteArray(BYTE* bytearray, int offset)
{
    unsigned short number = 0;

    for (int i = 0, j = offset; i < SHORT_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

short int s_fromByteArray(BYTE* bytearray, int offset)
{
    short number = 0;

    for (int i = 0, j = offset; i < SHORT_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

unsigned int ui_fromByteArray(BYTE* bytearray, int offset)
{
    unsigned int number = 0;

    for (int i = 0, j = offset; i < INT_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

int i_fromByteArray(BYTE* bytearray, int offset)
{
    int number = 0;

    for (int i = 0, j = offset; i < INT_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

unsigned long int ul_fromByteArray(BYTE* bytearray, int offset)
{
    unsigned long number = 0;

    for (int i = 0, j = offset; i < LONG_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

long int l_fromByteArray(BYTE* bytearray, int offset)
{
    long number = 0;

    for (int i = 0, j = offset; i < LONG_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

void byte_fromShort(short number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

void byte_fromUnsignedShort(unsigned short number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

void byte_fromInt(int number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

void byte_fromUnsignedInt(unsigned int number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

void byte_fromLong(long number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

void byte_fromUnsignedLong(unsigned long number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}