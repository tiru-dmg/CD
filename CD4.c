
//4. Write a C program to implement the Brute force technique of Top down Parsing



#include <stdio.h>
#include <string.h>

#define MAX 20

int nt, t, m[MAX][MAX], n;
char p[MAX][MAX], n1[MAX], t1[MAX], f[MAX][MAX], fl[MAX][MAX];

int scannt(char a) {
    for (int i = 0; i < nt; i++) if (n1[i] == a) return i;
    return -1;
}

int scant(char b) {
    for (int j = 0; j < t; j++) if (t1[j] == b) return j;
    return -1;
}

void input() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions one by one:\n");
    for (int i = 0; i < n; i++) scanf("%s", p[i]);
    nt = t = 0;
}

void process() {
    for (int i = 0; i < n; i++) if (scannt(p[i][0]) == -1) n1[nt++] = p[i][0];
    for (int i = 0; i < n; i++) for (int j = 3; j < strlen(p[i]); j++) if (p[i][j] != 'e' && scannt(p[i][j]) == -1 && scant(p[i][j]) == -1) t1[t++] = p[i][j];
    t1[t++] = '$';
    for (int i = 0; i < nt; i++) for (int j = 0; j < t; j++) m[i][j] = -1;
    for (int i = 0; i < nt; i++) printf("Enter first[%c]: ", n1[i]), scanf("%s", f[i]);
    for (int i = 0; i < nt; i++) printf("Enter follow[%c]: ", n1[i]), scanf("%s", fl[i]);
    for (int i = 0; i < n; i++) {
        int p1 = scannt(p[i][0]), q;
        if ((q = scant(p[i][3])) != -1) m[p1][q] = i;
        if ((q = scannt(p[i][3])) != -1) for (int j = 0; j < strlen(f[q]); j++) m[p1][scant(f[q][j])] = i;
        if (p[i][3] == 'e') for (int j = 0; j < strlen(fl[p1]); j++) m[p1][scant(fl[p1][j])] = i;
    }
    for (int i = 0; i < t; i++) printf("\t%c", t1[i]);
    printf("\n");
    for (int j = 0; j < nt; j++) {
        printf("%c", n1[j]);
        for (int i = 0; i < t; i++) printf("\t%s", m[j][i] != -1 ? p[m[j][i]] : " ");
        printf("\n");
    }
}

int main() {
    input();
    process();
    return 0;
}
