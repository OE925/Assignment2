# CS 3503 Assignment 2 - Advanced Data Representation

## Author
Orye Eshed

## Description
My implementation of Owl Tech ’s number advanced data representation includes creating a program in C that can convert octal to binary, hexadecimal to binary, and octal to hexadecimal. Also, my program can convert a base 10 integer into its 32-bit binary positive or negative representation, flip bits to make a negative binary representation of a negative base 10 integer, and use the modern standard to make a negative binary bit representation of a base 10 integer. My program contains the following functions: oct_to_bin, hex_to_bin, oct_to_hex, to_sign_magnitude, to_ones_complement, to_twos_complement, and main.

oct_to_bin converts octal to binary

hex_to_bin converts hexadecimal to binary

oct_to_hex converts octal to binary and then converts binary to hexadecimal

to_sign_magnitude converts a base 10 integer into its negative or positive binary representation

to_ones_complement converts a base 10 integer into its positive binary represenation. if it's a negative integer, it then flips the bits to create it's negative binary represenation.

to_twos_complement replicates the standard way that modern computers store integers

main reads the test cases from a2_test_file.txt and parses both single and multi-line formats. For every test, it reports whether each test either passed or failed.

## Build Instructions

1. Install JetBrains CLion.
2. Open CLion.
3. Create a project named main.c.
4. Create another project named convert.c.
5. Create all convert functions and print_tables function in convert.c.
6. Create main function in main.c.
7. make sure file accesses a2_test_file.txt and parses it correctly.
8. Click the run tool on the top right and test for correct output.


## Test Results
All cases were processed and were successful.
Summary: 51/51 tests passed

## Notes
- In the beginning, I had difficulty figuring out how to convert octal to hex due to having to convert octal to binary first, then to hex
- switch statement in hex_to_bin wouldn't work at first, but I realized that I just needed to make the char lowercase in order to process the uppercase letters
- I had a problem where only the first 9 test cases were working; however, I found out that there was an infinite loop due to my forgetting to increment a variable
- Overall, this assignment was difficult but similar to some ways to the previous assignment, so I had a better time navigating it.



