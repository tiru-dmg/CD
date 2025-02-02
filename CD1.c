#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    int i, j = 0;

    // Simulated input file content
    const char *input = "int main() {\n    int a = 10;\n    int b = 20;\n    int sum = a + b;\n    return 0;\n}";

    // Simulate reading from a file by iterating over the input string
    for (int k = 0; (ch = input[k]) != '\0'; k++) {
        for (i = 0; i < 6; i++) {
            if (ch == operators[i]) printf("%c is operator\n", ch);
        }
        if (isalnum(ch)) buffer[j++] = ch;
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer)) printf("%s is keyword\n", buffer);
            else printf("%s is identifier\n", buffer);
        }
    }

    return 0;
}
