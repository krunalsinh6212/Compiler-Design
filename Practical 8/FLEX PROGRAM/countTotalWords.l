%{
#include <stdio.h>
int word_count = 0;

int yywrap(void) {
    return 1;
}
%}

%%
[a-zA-Z]+  { word_count++; }

%%

int main() {
    yylex();
    printf("Total number of words: %d\n", word_count);
    return 0;
}
