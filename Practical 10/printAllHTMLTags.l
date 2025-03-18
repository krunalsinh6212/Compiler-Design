%{ 
#include<stdio.h> 
%}
 
%% 
"<"[^>]*> {printf("%s ",yytext );} 
. ; 
%% 

int yywrap() { 
return 1; 
} 

int main() { 
extern FILE *yyin; 
yyin=fopen("basic.txt","r"); 
yylex(); 
return 0; 
} 