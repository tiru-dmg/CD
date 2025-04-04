#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {"int", "char", "float", "double", "return", "if", "else", "while", "for", "do"};
char *operators = "=+-*/%";

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int isValidIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_') return 0;
    for (int i = 1; word[i]; i++)
        if (!isalnum(word[i]) && word[i] != '_') return 0;
    return 1;
}

int main() {
    char input[][10] = {"int", "a", "=", "b", "+", "1c"};
    int n = sizeof(input) / sizeof(input[0]);
    
    for (int i = 0; i < n; i++) {
        if (isKeyword(input[i]))
            printf("'%s' IS A KEYWORD\n", input[i]);
        else if (strchr(operators, input[i][0]) && strlen(input[i]) == 1)
            printf("'%s' IS AN OPERATOR\n", input[i]);
        else if (isValidIdentifier(input[i]))
            printf("'%s' IS A VALID IDENTIFIER\n", input[i]);
        else
            printf("'%s' IS NOT A VALID IDENTIFIER\n", input[i]);
    }
    return 0;
}
