// Program to count digit, vowels, consonants and symbols in c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countCharacterType(const char *str) {
    int vowels = 0, consonants = 0, digits = 0, specialChar = 0;
    char vowelChars[100] = "", consonantChars[100] = "", digitChars[100] = "", specialChars[100] = "";

    // Traverse the string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            // Convert uppercase to lowercase for uniformity
            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
                if (strlen(vowelChars) > 0) strcat(vowelChars, ",");
                strncat(vowelChars, &str[i], 1);
            } else {
                consonants++;
                if (strlen(consonantChars) > 0) strcat(consonantChars, ",");
                strncat(consonantChars, &str[i], 1);
            }
        } else if (ch >= '0' && ch <= '9') {
            digits++;
            if (strlen(digitChars) > 0) strcat(digitChars, ",");
            strncat(digitChars, &str[i], 1);
        } else {
            specialChar++;
            if (strlen(specialChars) > 0) strcat(specialChars, ",");
            strncat(specialChars, &str[i], 1);
        }
    }

    // Print the results
    printf("Vowels (%d): %s\n", vowels, vowelChars);
    printf("Consonants (%d): %s\n", consonants, consonantChars);
    printf("Digits (%d): %s\n", digits, digitChars);
    printf("Special Characters (%d): %s\n", specialChar, specialChars);
}

int main() {
    char str[100];

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Call the function to count and display character types
    countCharacterType(str);

    return 0;
}
