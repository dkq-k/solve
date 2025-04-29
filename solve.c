#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char binaryToChar(const char* binary) {
    int decimal = 0;
    int power = 0;
    int len = strlen(binary);
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return (char)decimal;
}

int main() {
    const char* binary_message = "01001110 01010100 01111011 00110001 00110110 00110011 01100001 01100010 01100011 01100100 01100101 01100110 01111101";
    char binary_part[9];
    char decoded_message[20] = "";
    int index = 0;

    for (int i = 0; i <= strlen(binary_message); i++) {
        if (binary_message[i] != ' ' && binary_message[i] != '\0') {
            binary_part[index++] = binary_message[i];
        } else {
            if (index == 8) {
                binary_part[index] = '\0';
                strncat(decoded_message, &binaryToChar(binary_part), 1);
            }
            index = 0;
        }
    }

    printf("Flag: %s\n", decoded_message);

    return 0;
}