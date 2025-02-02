%%writefile lex.l
%{
#include <stdio.h>
%}

%%

"int"       { printf("KEYWORD: %s\n", yytext); }
"float"     { printf("KEYWORD: %s\n", yytext); }
"return"    { printf("KEYWORD: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*  { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+      { printf("NUMBER: %s\n", yytext); }
[+\-*/]     { printf("OPERATOR: %s\n", yytext); }
[ \t\n]     ; // Ignore whitespace
.           { printf("UNKNOWN: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        yyin = file;
    }
    yylex();
    return 0;
}
----------------------------------------------------
%%writefile test.c
int main() {
    int a = 10;
    float b = 20.5;
    return a + b;
}
----------------------------------------------------
