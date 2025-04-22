#include <stdio.h>
#include <stdlib.h>    // для atof
#include <string.h>    // для strcmp
#include <math.h>      // для isnan и NAN

#define LEN 6
#define FRACTION 0.3

typedef struct sales_record {
    double a;
    double b;
    double sum;
} seles;

int miss(double val) {
    return isnan(val);
}

void fix_sales(seles sales[], int len, double fraction) {
    for (int i = 0; i < len; i++) {
        double a = sales[i].a;
        double b = sales[i].b;
        double sum = sales[i].sum;

        if (!miss(a) && !miss(b) && miss(sum)) {
            sales[i].sum = a + b;
        } else if (!miss(a) && miss(b) && !miss(sum)) {
            sales[i].b = sum - a;
        } else if (miss(a) && !miss(b) && !miss(sum)) {
            sales[i].a = sum - b;
        } else if (!miss(sum) && miss(a) && miss(b)) {
            sales[i].a = sum * fraction;
            sales[i].b = sum * (1.0 - fraction);
        } else if (miss(sum) && !miss(a) && miss(b)) {
            sales[i].b = a * (1.0 / fraction - 1.0);
            sales[i].sum = a + sales[i].b;
        } else if (miss(sum) && miss(a) && !miss(b)) {
            sales[i].a = b * (fraction / (1.0 - fraction));
            sales[i].sum = sales[i].a + b;
        }
    }
}

double parse_value(const char* token) {
    if (strcmp(token, "NAN") == 0 || strcmp(token, "nan") == 0) {
        return NAN;
    } else {
        return atof(token);
    }
}

void print_value(double val) {
    if (miss(val)) {
        printf("NAN");
    } else {
        printf("%.1f", val);
    }
}

int main() {
    FILE *file = fopen("input_file.txt", "r");
    if (file == NULL) {
        printf("Error while opening file\n");
        return 1;
    }

    struct sales_record sales[LEN];
    int count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) && count < LEN) {
        char a_str[20], b_str[20], sum_str[20];
        if (sscanf(line, "%s %s %s", a_str, b_str, sum_str) == 3) {
            sales[count].a = parse_value(a_str);
            sales[count].b = parse_value(b_str);
            sales[count].sum = parse_value(sum_str);
            count++;
        }
    }

    fclose(file);

    fix_sales(sales, LEN, FRACTION);
    
    for (int i = 0; i < LEN; i++) {
        printf("Month: %d Product A: ", i + 1);
        print_value(sales[i].a);
        printf(" Product B: ");
        print_value(sales[i].b);
        printf(" Total: ");
        print_value(sales[i].sum);
        printf("\n");
    }

    return 0;
}
