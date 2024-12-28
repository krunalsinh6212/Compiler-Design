// Program to check validation of Username and Password
#include<stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the username is valid
int is_valid_username(const char *username) {
    if (strlen(username) < 5 || strlen(username) > 20) {
        printf("Username must be between 5 and 20 characters.\n");
        return 0;
    }
    for (int i = 0; username[i]; i++) {
        if (!isalnum(username[i])) {
            printf("Username can only contain alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}

// Function to check if the password is valid
int is_valid_password(const char *password) {
    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else has_special = 1;
    }
    if (!has_upper || !has_lower || !has_digit || !has_special) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 0;
    }
    return 1;
}

int main() {
    char username[50], password[50];
    const char correct_username[] = "krunalsinh6212";
    const char correct_password[] = "Chhasatiya#6212";

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (!is_valid_username(username) || !is_valid_password(password)) {
        printf("Validation failed. Please try again.\n");
        return 1;
    }

    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}
