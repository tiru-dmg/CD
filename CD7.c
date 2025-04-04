#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void removeLeftRecursion(char prod[][MAX], int n) {
    printf("AFTER REMOVING LEFT RECURISON:\n");
    for (int i = 0; i < n; i++) {
        char A = prod[i][0];
        if (A == prod[i][3]) {
            printf("%c->%s%c'\n%c'->%s%c'|epsilon\n", A, prod[i] + 4, A, A, strchr(prod[i] + 4, '|') + 1, A);
        } else {
            printf("%s\n", prod[i]);
        }
    }
}

void removeLeftFactoring(char prod[][MAX], int n) {
    printf("AFTER REMOVING LEFT FACTORING:\n");
    for (int i = 0; i < n; i++) {
        char A = prod[i][0], common[MAX] = "", *p = strchr(prod[i], '|');
        if (p && prod[i][3] == p[1]) {
            printf("%c->%cX\nX->%s\n", A, prod[i][3], p + 2);
        } else {
            printf("%s\n", prod[i]);
        }
    }
}

int main() {
    int n;
    char prod[MAX][MAX];
    printf("ENTER NUMBER OF PRODUCTIONS: ");
    scanf("%d", &n);
    printf("ENTER THE PRODUCTIONS:\n");
    for (int i = 0; i < n; i++) scanf(" %s", prod[i]);
    removeLeftRecursion(prod, n);
    removeLeftFactoring(prod, n);
    return 0;
}
