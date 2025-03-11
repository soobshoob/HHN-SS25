#include <stdio.h>

void separator() {
    printf("\n");
    for (int i = 0; i < 60; i++) {
        printf("=");
    }
    printf("\n\n");
}

int f(int n) {
    if (n<=2){
        return 1;
    }
    else {
        return f(n-1)+f(n-2);
    }
}

int main () {
    int n;
    printf("Please give n: ");
    scanf("%d", &n);

    separator();
    printf("Answer is: %d\n", f(n));
    separator();
    
    return 0;
}