#include <stdio.h>

void separator() {
    printf("\n");
    for (int i = 0; i < 60; i++) {
        printf("=");
    }
    printf("\n\n");
}

int f(int n) {
    if (n <= 0) {
        return 0;
    } 
    else if (n%2==0) {
        return f(n/2)+1;
    }
    else {
        return f((n-1)/2)+2;
    }
}

int main () {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    separator();
    printf("Answer is: %d\n", f(n));
    separator();

    return 0;
}