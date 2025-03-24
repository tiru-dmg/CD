!apt-get install -y flex bison

%%writefile calc.l
%{ 
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *);
#include "y.tab.h" 
%} 
%% 
[a-z] { yylval = *yytext - 'a'; return VARIABLE; } 
[0-9]+ { yylval = atoi(yytext); return INTEGER; } 
[\t ] ; 
\n { return '\n'; }
. { return yytext[0]; }
%%
int yywrap(void) { return 1; }

%%writefile calc.y
%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *);
int sym[26];
%}

%token INTEGER VARIABLE
%left '+' '-'
%left '*' '/'

%%
PROG: PROG STMT '\n' | ;
STMT: EXPR { printf("\n Answer: %d\n", $1); }
    | VARIABLE '=' EXPR { sym[$1] = $3; }
    ;
EXPR: INTEGER { $$ = $1; }
    | VARIABLE { $$ = sym[$1]; }
    | EXPR '+' EXPR { $$ = $1 + $3; }
    | EXPR '-' EXPR { $$ = $1 - $3; }
    | EXPR '*' EXPR { $$ = $1 * $3; }
    | EXPR '/' EXPR { $$ = $1 / $3; }
    | '(' EXPR ')' { $$ = $2; }
    ;
%%
void yyerror(char *s) {
    printf("\n Error: %s\n", s);
}

int main(void) {
    printf("\n Enter the Expression:\n");
    yyparse();
    return 0;
}

!flex calc.l
!bison -d calc.y
!gcc lex.yy.c y.tab.c -o calc -lm
!./calc

Enter the Expression: (5+4)*3

Answer: 27
