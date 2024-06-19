#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};
 int IP_inverse[] = {4, 1, 3, 5, 7, 2, 8, 6};
 // Function to apply initial permutation
 int initial_permutation(int plaintext) {
 int result = 0;
 for (int i = 0; i < 8; i++) {
 result |= ((plaintext >> (8- IP[i])) & 1) << (7- i);
 }
 return result;
 }
 // Function to apply inverse initial permutation
 int inverse_initial_permutation(int ciphertext) {
 int result = 0;
 for (int i = 0; i < 8; i++) {
 result |= ((ciphertext >> (8- IP_inverse[i])) & 1) << (7- i);
 }
 return result;
 }
 // Function to perform S-box substitution
 int s_box_substitution(int value, int s_box[4][4]) {
 int row = ((value & 0b1000) >> 2) | (value & 0b0001);
 int col = (value & 0b0110) >> 1;
 return s_box[row][col];
 }
 // Function to print a binary number
 void print_binary(int num, int bits) {
 for (int i = bits- 1; i >= 0; i--) {
 printf("%d", (num >> i) & 1);
 }
 }
 int main() {
 int S0[4][4];
 int S1[4][4];
 int plaintext;
 // User inputs the plaintext
printf("Enter the plaintext (8-bit binary): ");
 char input[9];
 scanf("%8s", input);
 plaintext = strtol(input, NULL, 2);
 // User inputs the S-box values
 printf("Enter the S0 S-box values (4x4 matrix):\n");
 for (int i = 0; i < 4; i++) {
 for (int j = 0; j < 4; j++) {
 scanf("%d", &S0[i][j]);
 }
 }
 printf("Enter the S1 S-box values (4x4 matrix):\n");
 for (int i = 0; i < 4; i++) {
 for (int j = 0; j < 4; j++) {
 scanf("%d", &S1[i][j]);
 }
 }
 printf("Plain Text: ");
 print_binary(plaintext, 8);
 printf("\n");
 // Apply initial permutation
 int cipher_text = initial_permutation(plaintext);
 printf("Cipher Text after initial permutation: ");
 print_binary(cipher_text, 8);
 printf("\n");
 // Example of S-box substitution
 int s_box_value = 0b1101; // Example value
 int s_box_result = s_box_substitution(s_box_value, S0);
 printf("S-box result for value ");
 print_binary(s_box_value, 4);
 printf(": ");
 print_binary(s_box_result, 2);
 printf("\n");
 // Apply inverse initial permutation
 int decrypted_text = inverse_initial_permutation(cipher_text);
 printf("Decrypted Text: ");
 print_binary(decrypted_text, 8);
 printf("\n");
 return 0;
 }
