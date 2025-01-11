#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char stack[20], ip[20], opt[10][10][1], ter[10];
    int i, j, k, n, top = 0, row, col;
    int len;

    // Initialize arrays
    for (i = 0; i < 10; i++) {
        stack[i] = '\0';
        ip[i] = '\0';
        for (j = 0; j < 10; j++) {
            opt[i][j][0] = '\0';
        }
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("\nEnter the terminals: ");
    scanf("%s", ter);

    printf("\nEnter the table values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for %c %c: ", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    // Print Operator Precedence Table
    printf("\nOPERATOR PRECEDENCE TABLE:\n");
    for (i = 0; i < n; i++) {
        printf("\t%c", ter[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("\n%c |", ter[i]);
        for (j = 0; j < n; j++) {
            printf("\t%c", opt[i][j][0]);
        }
    }

    stack[top] = '$';
    printf("\n\nEnter the input string (append with $): ");
    scanf("%s", ip);

    i = 0;
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, ip);
    len = strlen(ip);

    while (i <= len) {
        // Find the row and column indices
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k]) row = k;
            if (ip[i] == ter[k]) col = k;
        }

        // If stack and input both have $, accept the string
        if ((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is ACCEPTED");
            break;
        }
        // Shift operation
        else if ((opt[row][col][0] == '<') || (opt[row][col][0] == '=')) {
            stack[++top] = opt[row][col][0];
            stack[++top] = ip[i];
            ip[i] = ' ';
            printf("Shift %c", ip[i]);
            i++;
        }
        // Reduce operation
        else if (opt[row][col][0] == '>') {
            while (stack[top] != '<') {
                --top;
            }
            top = top - 1;
            printf("Reduce");
        }
        // Error in parsing
        else {
            printf("\nString is not accepted");
            break;
        }

        // Print stack and input after each operation
        printf("\n%s\t\t\t%s\t\t\t", stack, ip);
    }

    getch();
    return 0;
}
