//3.write a c program to simulate lexical analyzer to validate a given input string

#include <stdio.h>
#include <string.h>

void identify(char *s) {
    char *rel[] = {"<", ">", "<=", ">=", "==", "!="};
    char *arith[] = {"+", "-", "*", "/", "%"};
    char *logical[] = {"&&", "||", "!"};
    char *bitwise[] = {"&", "|", "^", "~", "<<", ">>"};
    char *assign[] = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};
    
    for (int i = 0; i < 6; i++) if (!strcmp(s, rel[i])) { printf("It is a Relational Operator\n"); return; }
    for (int i = 0; i < 5; i++) if (!strcmp(s, arith[i])) { printf("It is an Arithmetic Operator\n"); return; }
    for (int i = 0; i < 3; i++) if (!strcmp(s, logical[i])) { printf("It is a Logical Operator\n"); return; }
    for (int i = 0; i < 6; i++) if (!strcmp(s, bitwise[i])) { printf("It is a Bitwise Operator\n"); return; }
    for (int i = 0; i < 11; i++) if (!strcmp(s, assign[i])) { printf("It is an Assignment Operator\n"); return; }
    
    printf("Invalid Operator\n");
}

int main() {
    char op[10];
    printf("Enter value to be identified: ");
    scanf("%s", op);
    identify(op);
    return 0;
}
