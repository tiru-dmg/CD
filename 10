#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len;

void check() {
    if (stack[st_ptr] == 'a' || stack[st_ptr] == 'b') {
        stack[st_ptr] = 'E';
        printf("\n $%s\t\t%s$\t\tE->%c", stack, ip_sym, stack[st_ptr]);
    }
    if (!strcmp(stack, "E+E") || !strcmp(stack, "E/E") || !strcmp(stack, "E*E")) {
        strcpy(stack, "E");
        st_ptr = 0;
        printf("\n $%s\t\t%s$\t\tE->E op E", stack, ip_sym);
    }
    if (!strcmp(stack, "E") && ip_ptr == len)
        printf("\n $%s\t\t%s$\t\tACCEPT", stack, ip_sym), exit(0);
}

int main() {
    printf("\n\t\t SHIFT REDUCE PARSER\n\n GRAMMAR\n\n E->E+E\n E->E/E\n E->E*E\n E->a/b\n\n Enter the input symbol: ");
    scanf("%s", ip_sym);
    len = strlen(ip_sym);
    printf("\n\t Stack Implementation Table\n\n Stack \t\t Input Symbol\t\t Action\n___________________________________________________\n");
    printf("\n $\t\t%s$\t\t--", ip_sym);
    for (int i = 0; i < len; i++) {
        stack[st_ptr++] = ip_sym[ip_ptr++];
        stack[st_ptr] = '\0';
        printf("\n $%s\t\t%s$\t\tshift %c", stack, ip_sym, ip_sym[ip_ptr]);
        check();
    }
    check();
    return 0;
}
