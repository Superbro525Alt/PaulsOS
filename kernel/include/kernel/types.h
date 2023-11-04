#pragma once

typedef unsigned char byte;
typedef unsigned char hex;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long long qword;

char **hex_to_string(hex b) {
    char *str = "";
    // if the byte is 0x12 then the string should be "0x12"
    // if the byte is 0x0A then the string should be "0x0A"
    // do it
    for (int i = 0; i < 8; i++) {
        if (b & (1 << i)) {
            str[7 - i] = '1';
        }
    }
    return str;
}