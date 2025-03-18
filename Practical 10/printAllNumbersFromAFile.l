%{
#include<stdio.h>
%}
%%
[0-9]+    printf("Number: %s\n", yytext);
.         ;  /* Ignore other characters */
%%

int main() {
    extern FILE *yyin;
    yyin = fopen("basic.txt", "r");
    if (!yyin) {
        printf("Error opening file\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    return 0;
}
