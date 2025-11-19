#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countCharacters(const char text[]) {
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int i;
    int length;
    char ch;

    length = (int)strlen(text);
    
    for (i = 0; i < length; i++) {
        ch = text[i];
        
        ch = tolower(ch); 

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } 
        else if ((ch >= 'a' && ch <= 'z')) {
            consonants++;
        }
        else if (ch >= '0' && ch <= '9') {
            digits++;
        }
        else if (ch == ' ') {
            spaces++;
        }
    }

    printf("Statistics:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Total counted characters: %d\n", vowels + consonants + digits + spaces);
}

int main() {
    char text[256];
    int length;

    printf("Enter a string (max 255 characters):\n");
    
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    length = (int)strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }

    printf("--------------------------------------\n");
    printf("Text: \"%s\"\n", text);
    printf("--------------------------------------\n");
    
    countCharacters(text);

    return 0;
}
