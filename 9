#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[30];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return (top != -1) ? stack[top--] : 'x'; }
void printstat() {
    printf("\n\t\t\t $");
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

void main() {
    char s1[20];
    int l;
    printf("\n\n\t\t LR PARSING");
    printf("\n\t\t ENTER THE EXPRESSION: ");
    scanf("%s", s1);
    l = strlen(s1);
    printf("\n\t\t $");

    for (int i = 0; i < l; i++) {
        if (s1[i] == 'i' && s1[i + 1] == 'd') {
            s1[i] = ' '; s1[i + 1] = 'E';
            printstat();
            printf("id");
            push('E');
            printstat();
        } else if (strchr("+-*/", s1[i])) {
            push(s1[i]);
            printstat();
        }
    }
    printstat();

    while (top != -1) {
        char ch1 = pop();
        if (ch1 == 'x') break;
        if (strchr("+-*/", ch1)) {
            if (pop() != 'E') {
                printf("error");
                exit(0);
            }
            push('E');
            printstat();
        }
    }
}
