#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

void encrypt(char* text, int shift, char* encrypted_text) 
{
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isupper(ch)) {
            encrypted_text[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        else if (islower(ch)) {
            encrypted_text[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
        else if (isdigit(ch)) {
            encrypted_text[i] = ((ch - '0' + shift) % 10) + '0';
        }
        else {
            encrypted_text[i] = ch;
        }
    }
    encrypted_text[i] = '\0';
}



void decrypt(char* text, int shift, char* decrypted_text) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isupper(ch)) {
            decrypted_text[i] = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        else if (islower(ch)) {
            decrypted_text[i] = ((ch - 'a' - shift + 26) % 26) + 'a';
        }
        else if (isdigit(ch)) {
            decrypted_text[i] = ((ch - '0' - shift + 10) % 10) + '0';
        }
        else {
            decrypted_text[i] = ch;
        }
    }
    decrypted_text[i] = '\0';
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter your text: ");
    scanf("%s", text);
    int shift = 4;
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];
    encrypt(text, shift, encrypted_text);
    printf("Original Text: %s\n", text);
    printf("Encrypted Text: %s\n", encrypted_text);
    decrypt(encrypted_text, shift, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);
    return 0;
}
