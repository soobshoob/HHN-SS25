#include <stdio.h>

typedef struct complex {
    double real;
    double imag;
} complex;

void print_complex(complex c) {
    if (c.imag >= 0) {
        printf("%.6f + %.6f i\n", c.real, c.imag);
    } else {
        printf("%.6f - %.6f i\n", c.real, -c.imag);
    }
}

complex addition(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex multiplication(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

complex inverse(complex a) {
    complex result;
    double denominator = a.real * a.real + a.imag * a.imag;
    
    if (denominator == 0) {
        printf("Error: Division by zero\n");
        result.real = 0;
        result.imag = 0;
        return result;
    }
    
    result.real = a.real / denominator;
    result.imag = -a.imag / denominator;
    return result;
}

complex subtraction(complex a, complex b) {
    complex negated_b;
    negated_b.real = -b.real;
    negated_b.imag = -b.imag;
    return addition(a, negated_b);
}

complex division(complex a, complex b) {
    return multiplication(a, inverse(b));
}

int main() {
    complex val[] = {
        {2.0, 4.2},
        {-1.3, 1.1},
        {5.4, -3.6},
        {-8.9, -0.1},
        {0.0, -2.9}
    };
    
    // Example val[4] - (val[3] / (val[2] * (val[0] + val[1])))
    complex addition_result = addition(val[0], val[1]);
    complex multiplication_result = multiplication(val[2], addition_result);
    complex division_result = division(val[3], multiplication_result);
    complex result = subtraction(val[4], division_result);
    
    printf("Result: ");
    print_complex(result);
    
    if (result.imag >= 0) {
        printf("The solution of the calculation is %.6f + %.6f i\n", result.real, result.imag);
    } else {
        printf("The solution of the calculation is %.6f - %.6f i\n", result.real, -result.imag);
    }
    
    return 0;
}