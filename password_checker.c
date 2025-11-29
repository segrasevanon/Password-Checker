#include <stdio.h>
#include <string.h>
#include <ctype.h>

int passwordstrength(const char *password) {
    int len = strlen(password);
    int lower = 0;
    int upper = 0;
    int digit = 0;
    int special = 0;
    int result = 0;

    if (len < 8) {
        printf("The password must be minimum 8 characters long\n");
        result = 0;
    }

    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            lower = 1;
        }
        if (isupper(password[i])) {
            upper = 1;
        }
        if (isdigit(password[i])) {
            digit = 1;
        }
        if (ispunct(password[i])) {
            special = 1;
        }

        if (lower && upper && digit && special) {
            result = 2;
        }

        if (lower || upper || digit || special) {
            result = 1;
        } else {
            result = 0;
        }
        
    }
    if(lower==0){
            printf("The password must contain at least one lowercase letter\n");

        }
        if(upper==0){
            printf("The password must contain at least one uppercase letter\n");

        }
        if(digit==0){
            printf("The password must contain at least one digit\n");

        }
        if(special==0){
            printf("The password must contain at least one special character\n");

        }

    return result;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int s = passwordstrength(password);

    if (s == 2) {
        printf("Your password is strong\n");
    }
    if (s == 1) {
        printf("Your password is moderate\n");
    } else {
        printf("Your password is weak\n");
    }

    return 0;
}
