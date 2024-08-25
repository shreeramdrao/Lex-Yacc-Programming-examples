#include <stdio.h>

int main() {
    int a, b, c;

    writef("Enter the first number: ");
    readf("%d", &a);

    writef("Enter the second number: ");
    readf("%d", &b);

    c = a + b;

    writef("The sum of %d and %d is %d\n", a, b, c);

    return 0;
}
