%{
#include <stdio.h>

int positive_count = 0;
int negative_count = 0;
%}

%%
[0-9]+   { printf("%s is a positive number\n", yytext); positive_count++; }
-[0-9]+  { printf("%s is a negative number\n", yytext); negative_count++; }
\n       { /* ignore newline characters */ }
.        { /* ignore any other characters */ }
%%

int main() {
    printf("Enter numbers (Ctrl+C to end input):\n");
    yylex();
    printf("\nTotal positive numbers: %d\n", positive_count);
    printf("Total negative numbers: %d\n", negative_count);
    return 0;
}

int yywrap() {
    return 1;
}

