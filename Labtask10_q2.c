#include <stdio.h>
#include <string.h>

void extractDomain(const char email[]) {
    int length = 0;
    int atIndex = -1;
    int i;
    
    length = (int)strlen(email);
    for (i = 0; i < length; i++) {
        if (email[i] == '@') {
            atIndex = i;
            break;
        }
    }

    if (atIndex != -1) {
        printf("Domain: ");
        for (i = atIndex + 1; i < length; i++) {
            printf("%c", email[i]);
        }
        printf("\n");
        
    } else {
        printf("Domain: Invalid email (Missing '@' symbol)\n");
    }
}

int main() {
    char email[128];
    int length;
    
    printf("Enter an email address: ");
    
    if (fgets(email, sizeof(email), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    length = (int)strlen(email);
    if (length > 0 && email[length - 1] == '\n') {
        email[length - 1] = '\0';
    }

    printf("----------------------------------\n");
    printf("Email: %s\n", email);
    
    extractDomain(email);

    printf("----------------------------------\n");

    return 0;
}
