#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPassword(const char password[]) {
    int hasUpper = 0;   
    int hasDigit = 0;   
    int hasSpecial = 0; 
    int length;
    int i; 

    length = (int)strlen(password);

    if (length < 8) {
        return 0;
    }

    for (i = 0; i < length; i++) {
        char ch = password[i]; 

        if (isupper(ch)) {
            hasUpper = 1;
        }
        else if (isdigit(ch)) {
            hasDigit = 1;
        }
        else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%') {
            hasSpecial = 1;
        }
    }
    
    return hasUpper && hasDigit && hasSpecial;
}

int main() {
    char password[128]; 
    int length;

    printf("Enter a password to validate (max 127 chars): ");
    
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    length = (int)strlen(password);
    if (length > 0 && password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    printf("---------------------------\n");
    printf("Validating password: %s\n", password);
    printf("---------------------------\n");

    if (checkPassword(password)) {
        printf("FINAL STATUS: PASS - The password meets all requirements.\n");
    } else {
        printf("FINAL STATUS: FAIL - The password is weak (Check rules: min 8 chars, 1 uppercase, 1 digit, 1 special char).\n");
    }

    return 0;
}
