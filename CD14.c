#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempVar = 1;
char getTempVar() {
    return 't' + (tempVar++); // Generate unique temp variable names
}

void generateCode(char op, char arg1, char arg2, char result) {
    printf("MOV R0,%c\n", arg1);
    if (op == '+') printf("ADD R0,%c\n", arg2);
    else if (op == '-') printf("SUB R0,%c\n", arg2);
    else if (op == '*') printf("MUL R0,%c\n", arg2);
    else if (op == '/') printf("DIV R0,%c\n", arg2);
    printf("MOV %c,R0\n", result);
}

int main() {
    char expr[50], tokens[20];
    int i, j = 0;

    printf("Enter an arithmetic expression (e.g., x=a+b or x=a+b-c*d): ");
    scanf("%s", expr);

    int len = strlen(expr);
    for (i = 0; i < len; i++) {
        if (!isspace(expr[i])) tokens[j++] = expr[i];
    }
    tokens[j] = '\0';

    if (tokens[1] != '=') {
        printf("Invalid Expression\n");
        return 1;
    }

    char res = tokens[0]; // LHS variable
    char temp = tokens[2]; // Start with first variable
    int k = 3;

    while (k < j) {
        char op = tokens[k++];
        char nextVar = tokens[k++];
        char tempVar = getTempVar();
        generateCode(op, temp, nextVar, tempVar);
        temp = tempVar; // Store result in tempVar
    }

    printf("MOV R0,%c\nMOV %c,R0\n", temp, res);

    return 0;
}
