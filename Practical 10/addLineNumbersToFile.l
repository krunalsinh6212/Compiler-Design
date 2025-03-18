%{ 
#include<stdio.h> 
int ln=0; 
%} 

%% 
[\n] {} 
.* {ln++;fprintf(yyout,"\n%d.%s",ln,yytext);} 
%% 

int yywrap() { 
return 1; 
} 

int main() { 
extern FILE *yyin,*yyout; 
yyin = fopen("basic.txt","r"); 
yyout = fopen("basic1.txt","w"); 
yylex(); 
return 0; 
} 