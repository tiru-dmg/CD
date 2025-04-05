//8.Write a C program to check the validity of input string using Predictive Parser.

#include <stdio.h>
#include <string.h>

char *input;
int pos = 0;

// Function Prototypes
int E();
int T();
int F();

// Function to check if input matches expected character
int match(char expected) {
    if (input[pos] == expected) {
        pos++;
        return 1;
    }
    return 0;
}

// Grammar Functions
int E() { return T() && (input[pos] == '+' ? (pos++, E()) : 1); }
int T() { return F() && (input[pos] == '*' ? (pos++, T()) : 1); }
int F() { return (match('(') && E() && match(')')) || match('a'); }

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    input = str;
    
    if (E() && input[pos] == '\0')
        printf("Valid string\n");
    else
        printf("Invalid string\n");
    
    return 0;
}
