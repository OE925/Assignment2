#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    //opens test file
    FILE *file = fopen("C:\\Users\\oryee\\Downloads\\a2_test (1).txt", "r");

    // creates a buffer to hold a line from the test file, creates an int to hold the number of tests run, and creates an int to count how many tests are passed
    char line[256];
    int test_num = 0;
    int passed_count = 0;

    // reads the file line by line
    while (fgets(line, sizeof(line), file)) {

        // this skips lines that are comments or are empty
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') {
            continue;
        }
        // creates buffers to store parts of test lines that are parsed
        char func_name[50], input[100], expected[100];
        // checks to see if there are 3 lines of strings that are separated by whitespace
        int items = sscanf(line, "%49s %99s %99s", func_name, input, expected);
        // if it doesn't, it skips the line
        if (items != 3) {
            continue;
        }

        // increments the test counter, creates a buffer for results and gives a generous amount of space, and creates a buffer for the results of 32-bit functions
        test_num++;
        char actual[100];
        char actual_fixed[33];

        // compares strings to check which function to call based on the function name
        if (strcmp(func_name, "oct_to_bin") == 0) {
            oct_to_bin(input, actual);
        } else if (strcmp(func_name, "oct_to_hex") == 0) {
            oct_to_hex(input, actual);
        } else if (strcmp(func_name, "hex_to_bin") == 0) {
            hex_to_bin(input, actual);
        } else if (strcmp(func_name, "to_sign_magnitude") == 0) {
            int32_t n = atoi(input);
            to_sign_magnitude(n, actual_fixed);
            strcpy(actual, actual_fixed);
        } else if (strcmp(func_name, "to_ones_complement") == 0) {
            int32_t n = atoi(input);
            to_ones_complement(n, actual_fixed);
            strcpy(actual, actual_fixed);
        } else if (strcmp(func_name, "to_twos_complement") == 0) {
            // uses strol for to_twos_complement because it can handle a full ranged of 32-bit integers, which atoi cant
            int32_t n = strtol(input, NULL, 10);
            to_twos_complement(n, actual_fixed);
            strcpy(actual, actual_fixed);
        } else {
            // prints if function name is not recognized and skips the line
            printf("Test %d: Unknown function name '%s'. [SKIPPING]\n", test_num, func_name);
            continue;
        }

        // checks to see if the test is a fail or a pass
        const char *result_str = "FAIL";
        if (strcmp(actual, expected) == 0) {
            result_str = "PASS";
            passed_count++;
        }

        // prints the test results
        printf("Test %d: %s(\"%s\") -> Expected: \"%s\", Got: \"%s\" [%s]\n",
               test_num, func_name, input, expected, actual, result_str);
    }
    // prints the summary and closes the file
    printf("\nSummary: %d/%d tests passed\n", passed_count, test_num);
    fclose(file);
    return 0;
}