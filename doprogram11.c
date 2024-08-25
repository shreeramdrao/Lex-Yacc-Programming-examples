#include <stdio.h>

int main() {
    int n, i = 1;
    unsigned long long f = 1; // Use unsigned long long to handle large numbers
    printf("Enter a number: ");
    scanf("%d", &n);

    // For negative numbers, factorial does not exist
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        do {
            f = f * i;
            i++;
        } while (i <= n);

        printf("Factorial of %d is %llu\n", n, f);
    }

    return 0;
}
