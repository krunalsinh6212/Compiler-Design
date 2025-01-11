#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[100];
int pos = 0; // Tracks the current position in the input string

void E(), EPRIME(), T(), TPRIME(), F();

void error() {
    printf("Error: Invalid string\n");
    exit(1);
}

void match(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        error();
    }
}

// E -> T E'
void E() {
    T();
    EPRIME();
}

// E' -> + T E' | ε
void EPRIME() {
    if (input[pos] == '+') {
        match('+');
        T();
        EPRIME();
    }
    // Else: ε (do nothing)
}

// T -> F T'
void T() {
    F();
    TPRIME();
}

// T' -> * F T' | ε
void TPRIME() {
    if (input[pos] == '*') {
        match('*');
        F();
        TPRIME();
    }
    // Else: ε (do nothing)
}

// F -> ( E ) | id
void F() {
    if (input[pos] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(input[pos])) { // Match an identifier (id)
        match(input[pos]);
    } else {
        error();
    }
}

int main() {
    printf("Enter an arithmetic expression (end with $): ");
    scanf("%s", input);

    // Start parsing from E
    E();

    // If successfully parsed, the input string should end with '$'
    if (input[pos] == '$') {
        printf("Valid string\n");
    } else {
        error();
    }

    return 0;
}
