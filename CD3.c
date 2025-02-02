#include <stdio.h>

int main() {
    char s[3];
    printf("Enter any operator: ");
    scanf("%s", s);

    const char *ops[] = {"Greater than", "Less than", "Assignment", "Bit Not", "Bitwise AND", "Bitwise OR", 
                         "Addition", "Subtraction", "Multiplication", "Division", "Modulus"};
    const char *logical_ops[] = {"Greater than or equal", "Less than or equal", "Equal to", "Not Equal", 
                                 "Logical AND", "Logical OR"};

    switch(s[0]) {
        case '>': printf("%s\n", s[1] == '=' ? logical_ops[0] : ops[0]); break;
        case '<': printf("%s\n", s[1] == '=' ? logical_ops[1] : ops[1]); break;
        case '=': printf("%s\n", s[1] == '=' ? logical_ops[2] : ops[2]); break;
        case '!': printf("%s\n", s[1] == '=' ? logical_ops[3] : ops[3]); break;
        case '&': printf("%s\n", s[1] == '&' ? logical_ops[4] : ops[4]); break;
        case '|': printf("%s\n", s[1] == '|' ? logical_ops[5] : ops[5]); break;
        case '+': printf("%s\n", ops[6]); break;
        case '-': printf("%s\n", ops[7]); break;
        case '*': printf("%s\n", ops[8]); break;
        case '/': printf("%s\n", ops[9]); break;
        case '%': printf("%s\n", ops[10]); break;
        default: printf("Not an operator\n");
    }

    return 0;
}
