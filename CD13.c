#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateTAC(char expr[]) {
    char tempVar = 'T';
    int tCount = 1;
    char op, operand1, operand2;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (!isalnum(expr[i]) && expr[i] != '=') {
            op = expr[i];
            operand1 = expr[i - 1];
            operand2 = expr[i + 1];
            printf("%c%d = %c %c %c\n", tempVar, tCount, operand1, op, operand2);
            expr[i + 1] = tempVar + (tCount++);
        }
    }
}

int main() {
    char expr[20];
    printf("Enter an expression (e.g., a=b+c*d): ");
    scanf("%s", expr);
    
    if (strchr(expr, '=') == NULL) {
        printf("Invalid expression. Must contain '='.\n");
        return 1;
    }
    
    generateTAC(expr);
    return 0;
}
