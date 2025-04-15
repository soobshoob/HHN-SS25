#include <stdio.h>

void separator() {
    printf("\n");
    for (int i = 0; i < 60; i++) {
        printf("=");
    }
    printf("\n\n");
}

// Correct function for exponentiation
double functional(int x, int n) {
    if (n == 0) {
        return 1;  // x^0 = 1 by definition
    } 
    if (n < 0) {
        return 1.0 / functional(x, -n);  // Negative exponent
    }
    return x * functional(x, n - 1);  // Positive exponent
}

int main() {
    int x, n;
    printf("Enter a base (x): ");
    scanf("%d", &x);
    printf("Enter an exponent (n): ");
    scanf("%d", &n);

    separator();
    printf("%d^%d = %.5f\n", x, n, functional(x, n)); // .5f for proper fractional number display
    separator();
    return 0;
}