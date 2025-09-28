#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>


// using direct 3-bit mapping, the function will convert octal to binary.
void oct_to_bin (const char *oct, char *out) {
    // pos of the output buffer
    int pos = 0;
    // loops through string until the null terminator is found
    for (int i = 0; oct[i] != '\0'; i++) {
        // checks each case and then copies the binary equivalent into the buffer
        switch (oct[i]) {
            case '0':
                strcpy(&out[pos], "000");
                break;
            case '1':
                strcpy(&out[pos], "001");
                break;
            case '2':
                strcpy(&out[pos], "010");
                break;
            case '3':
                strcpy(&out[pos], "011");
                break;
            case '4':
                strcpy(&out[pos], "100");
                break;
            case '5':
                strcpy(&out[pos], "101");
                break;
            case '6':
                strcpy(&out[pos], "110");
                break;
            case '7':
                strcpy(&out[pos], "111");
                break;
        }
        // increments the position by 3
        pos += 3;

    }
    out[pos] = '\0';
}

// Converts hexadecimal to binary using 4-bit mapping.
void hex_to_bin (const char *hex, char *out) {
    // position for output buffer
    int pos = 0;
    // loop goes through each character in the hex string
    for (int i = 0; hex[i] != '\0'; i++) {
        // changes the character to lowercase in order to handle 'A'
        char lower = tolower(hex[i]);
        // switch statement used to change hex character to its 4-bit binary equivalent
        switch (lower) {
            case '0':
                strcpy(&out[pos], "0000");
                break;
            case '1':
                strcpy(&out[pos], "0001");
                break;
            case '2':
                strcpy(&out[pos], "0010");
                break;
            case '3':
                strcpy(&out[pos], "0011");
                break;
            case '4':
                strcpy(&out[pos], "0100");
                break;
            case '5':
                strcpy(&out[pos], "0101");
                break;
            case '6':
                strcpy(&out[pos], "0110");
                break;
            case '7':
                strcpy(&out[pos], "0111");
                break;
            case '8':
                strcpy(&out[pos], "1000");
                break;
            case '9':
                strcpy(&out[pos], "1001");
                break;
            case 'a':
                strcpy(&out[pos], "1010");
                break;
            case 'b':
                strcpy(&out[pos], "1011");
                break;
            case 'c':
                strcpy(&out[pos], "1100");
                break;
            case 'd':
                strcpy(&out[pos], "1101");
                break;
            case 'e':
                strcpy(&out[pos], "1110");
                break;
            case 'f':
                strcpy(&out[pos], "1111");
                break;

        }
        //increment position by 4
        pos += 4;
    }
    out[pos] = '\0';
}

// function will convert oct to hex. First converts oct to bin and then converts bin to hex.
void oct_to_hex (const char *oct, char *out) {

    // handles edge case where the input equals 0
    if (strcmp(oct, "0") == 0) {
        strcpy(out, "0");
        return;
    }

    // create a buffer to hold the binary string
    char bin_to_hex[100];
    // calling oct_to_bin to change the oct to binary
    oct_to_bin(oct, bin_to_hex);

    // gets the length of the binary string, then finds how many zeros are needed to add to the left to make the length a multiple of 4. Lastly, create a buffer to hold the binary string
    int length = strlen(bin_to_hex);
    int zeros = (4 - (length % 4)) % 4;
    char zeros_bin[104];

    // Adds the zeros to the binary buffer
    for (int i = 0; i < zeros; i++) {
        zeros_bin[i] = '0';
    }

    // copies the original binary string to the binary buffer
    strcpy(&zeros_bin[zeros], bin_to_hex);
    zeros_bin[length + zeros] = '\0';

    // holds position of output buffer
    int pos = 0;

    // Loop goes through the binary buffer and takes 4 (binary) characters (holder) and converts it to its hex equivalent
    for (int i = 0; i < strlen(zeros_bin); i += 4) {
        // creates buffer to hold the 4 binary characters then copies the 4 characters from zeros_bin to holder
        char holder[5];
        strncpy(holder, &zeros_bin[i], 4);
        holder[4] = '\0';

        // if and else statements are used to convert binary to its hex equivalent
        if (strcmp(holder, "0000") == 0) {
            out[pos] = '0';
        }
        else if (strcmp(holder, "0001") == 0) {
            out[pos] = '1';
        }
        else if (strcmp(holder, "0010") == 0) {
            out[pos] = '2';
        }
        else if (strcmp(holder, "0011") == 0) {
            out[pos] = '3';
        }
        else if (strcmp(holder, "0100") == 0) {
            out[pos] = '4';
        }
        else if (strcmp(holder, "0101") == 0) {
            out[pos] = '5';
        }
        else if (strcmp(holder, "0110") == 0) {
            out[pos] = '6';
        }
        else if (strcmp(holder, "0111") == 0) {
            out[pos] = '7';
        }
        else if (strcmp(holder, "1000") == 0) {
            out[pos] = '8';
        }
        else if (strcmp(holder, "1001") == 0) {
            out[pos] = '9';
        }
        else if (strcmp(holder, "1010") == 0) {
            out[pos] = 'A';
        }
        else if (strcmp(holder, "1011") == 0) {
            out[pos] = 'B';
        }
        else if (strcmp(holder, "1100") == 0) {
            out[pos] = 'C';
        }
        else if (strcmp(holder, "1101") == 0) {
            out[pos] = 'D';
        }
        else if (strcmp(holder, "1110") == 0) {
            out[pos] = 'E';
        }
        else if (strcmp(holder, "1111") == 0) {
            out[pos] = 'F';
        }
        // increment position of output buffer
        pos++;
    }
    out[pos] = '\0';

    // this removes any leading zeros from the result
    int lead = 0;
    while(out[lead] == '0' && out[lead+1] != '\0') {
        lead++;
    }
    // moves the string content to the beginning to overwrite the zeros
    if(lead > 0) {
        memmove(out, out + lead, strlen(out) - lead + 1);
    }
}

// The first bit represents the sign and the other 31 represent the magnitude.
void to_sign_magnitude(int32_t n, char *out) {
    // calculates the absolute value
    uint32_t sign;
    if (n < 0) {
        sign = -n;
    }
    else {
        sign = n;
    }
    // loops to shift the bits representing the magnitude to the right and checks the last bit
    for (int i = 0; i < 32; i++) {
        out[i] = ((sign >> (31 - i)) & 1) ? '1' : '0';
    }
    out[32] = '\0';

    // checks to see if the original number was negative, then changes the first bit to '1'
    if (n < 0) {
        out[0] = '1';
    }
}

// For the negative numbers, flips positive binary representation to get negative binary represenation.
void to_ones_complement(int32_t n, char *out) {
    // same as to_sign_magnitude if it's a positive number
    if (n >= 0) {
        uint32_t value = (uint32_t)n;
        for (int i = 0; i < 32; i++) {
            out[i] = ((value >> (31 - i)) & 1) ? '1' : '0';
        }
    }
    // if it's a negative number, it gets the positive version of the binary representation and then loops through the binary string and flips every bit
    else {
        uint32_t sign = -n;
        for (int i = 0; i < 32; i++) {
            out[i] = ((sign >> (31 - i)) & 1) ? '1' : '0';
        }

        for (int i = 0; i < 32; i++) {
            out[i] = (out[i] == '0') ? '1' : '0';
        }

    }
    out[32] = '\0';
}


// Replicates the standard way that computers store signed integers.
void to_twos_complement(int32_t n, char *out) {
    // loops through the bit pattern to create the binary string
    uint32_t bit_patt = (uint32_t)n;
    for (int i = 0; i < 32; i++) {
        out[i] = ((bit_patt >> (31 - i)) & 1) ? '1' : '0';
    }
    out[32] = '\0';
}