#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

void check();

int main() {
    printf("GRAMMAR is\nE->E+E\nE->E*E\nE->(E)\nE->id\n");
    printf("Enter input string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';  // Remove newline character
    c = strlen(a);
    strcpy(act, "SHIFT->");
    printf("stack \t input \t action\n");
    printf("\n$\t%s$\t---", a);
    
    for (k = 0, i = 0, j = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbols", stk, a, act);
            check();
        }
    }
    return 0;
}

void check() {
    strcpy(ac, "REDUCE TO E");
    
    for (z = 0; z <= i; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            for (int k = z + 1; k < i - 1; k++) {
                stk[k] = stk[k + 2];
            }
            i -= 1;
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    }

    for (z = 0; z < i; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            for (int k = z + 1; k < i - 2; k++) {
                stk[k] = stk[k + 3];
            }
            i -= 2;
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    }

    for (z = 0; z < i; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            for (int k = z + 1; k < i - 2; k++) {
                stk[k] = stk[k + 3];
            }
            i -= 2;
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    }

    for (z = 0; z < i; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            for (int k = z + 1; k < i - 2; k++) {
                stk[k] = stk[k + 3];
            }
            i -= 2;
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    }
}
