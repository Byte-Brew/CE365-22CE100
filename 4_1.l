%option noyywrap
%{
#include <stdio.h>
%}

%%
  // Count consonants
[0-9]+ { printf("%s\n", yytext); }          // Match and print numbers
.|\n { }                                    // Ignore other characters and newline

%%

int main() {
    printf("Enter the data: ");
    yylex();  // Start the lexical analysis
    return 0;
}