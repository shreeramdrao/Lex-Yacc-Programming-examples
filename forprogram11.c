#include <stdio.h>

int main() {
    int i, number;
    unsigned long long fact = 1; // Use unsigned long long to handle large numbers
    printf("Enter a number: ");
    scanf("%d", &number);

    // For negative numbers, factorial does not exist
    if (number < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        for (i = 1; i <= number; i++) {
            fact = fact * i;
        }
        printf("Factorial of %d is: %llu\n", number, fact);
    }

    return 0;
}
