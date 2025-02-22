%{
#include<stdio.h>
int word=0;
int line=0;
int space=0;
int tab=0;
%}
%%
([A-Za-z0-9])+ {word++;}
"\n" {line++;}
([ ])+ {space++;}
"\t" {tab++;}
%%
int main() {
extern FILE *yyin;
yyin=fopen("basic.txt","r");
yylex();
printf("words:%d \n liens :%d \n spaces :%d \n tabs: %d \n ",word,line,space,tab);
return 0;
}
int yywrap()
{
return 1;
}
