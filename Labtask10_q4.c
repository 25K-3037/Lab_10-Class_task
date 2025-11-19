#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptMessage(char message[], int shift) {
    int i;
    int length;
    char ch;

    length = (int)strlen(message);

    for (i = 0; i < length; i++) {
        ch = message[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + shift;
            message[i] = ch;
        } 
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + shift;
            message[i] = ch;
        }
    }
}

int main() {
    char message[256];
    int length;
    int shift = 3;

    printf("Enter a message to encrypt (max 255 chars):\n");
    
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    length = (int)strlen(message);
    if (length > 0 && message[length - 1] == '\n') {
        message[length - 1] = '\0';
    }

    printf("----------------------------------------\n");
    printf("Original message: %s\n", message);
    
    encryptMessage(message, shift);

    printf("Encrypted message (Shift %d): %s\n", shift, message);
    printf("----------------------------------------\n");

    return 0;
}
