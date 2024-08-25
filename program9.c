#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void FIRST(char c);
int count, n = 0;
char prodn[10][10], first[10];

int main() {
    int i, choice;
    char c, ch;
    
    printf("Enter the number of productions: ");
    scanf("%d", &count);
    
    printf("Enter %d productions:\nEpsilon=$\n", count);
    for (i = 0; i < count; i++) {
        scanf("%s", prodn[i]);
    }
    
    do {
        n = 0; // Reset n for each new FIRST computation
        printf("Element : ");
        scanf(" %c", &c); // Added space before %c to consume any newline left in the input buffer
        
        FIRST(c);
        
        printf("\nFIRST(%c) = {", c);
        for (i = 0; i < n; i++) {
            printf(" %c", first[i]);
        }
        printf(" }\n");
        
        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    } while (choice == 1);
    
    return 0;
}

void FIRST(char c) {
    int j;
    
    if (!isupper(c)) {
        first[n++] = c;
        return;
    }
    
    for (j = 0; j < count; j++) {
        if (prodn[j][0] == c) {
            if (prodn[j][2] == '$') {
                first[n++] = '$';
            } else if (islower(prodn[j][2])) {
                first[n++] = prodn[j][2];
            } else {
                FIRST(prodn[j][2]);
            }
        }
    }
}
