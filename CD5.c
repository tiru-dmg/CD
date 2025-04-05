//5.write a c program to implement a recursvie descent parser


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *inp;
void E(), T(), Edash(), Tdash(), F();
void error() { printf("Error in parsing String\n"); exit(1); }
void match(char t) { if (*inp == t) inp++; else error(); }

void E() { printf("E->TE'\n"); T(); Edash(); }
void Edash() { if (*inp == '+') { printf("E'->+TE'\n"); match('+'); T(); Edash(); } else printf("E'->ε\n"); }
void T() { printf("T->FT'\n"); F(); Tdash(); }
void Tdash() { if (*inp == '*') { printf("T'->*FT'\n"); match('*'); F(); Tdash(); } else printf("T'->ε\n"); }
void F() { 
    if (*inp == '(') { 
        printf("F->(E)\n"); match('('); E(); match(')'); 
    } else if (isalnum(*inp)) { 
        printf("F->id\n"); while (isalnum(*inp)) inp++;  // Supports multi-char identifiers
    } else error(); 
}

int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%99s", input); // Prevents buffer overflow
    inp = input;
    E();
    if (*inp == '\0') printf("String parsed successfully\n");
    else error();
    return 0;
}
