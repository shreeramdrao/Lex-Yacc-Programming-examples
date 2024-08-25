#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    c = a + b;

    printf("The sum of %d and %d is %d\n", a, b, c);

    return 0;
}
