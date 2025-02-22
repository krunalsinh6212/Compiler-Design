%{
int vowel=0;
int consonant =0;
%}
%%
[a,e,i,o,u,A,E,I,O,U] {vowel++;}
[a-zA-Z] {consonant++;}
%%
int yywrap()
{return 1; }
int main()
{
printf("Enter the string ");
yylex();
printf("Number of vowels are: %d \n", vowel);
printf("Number of consonants are: %d \n", consonant);
return 0;
}
