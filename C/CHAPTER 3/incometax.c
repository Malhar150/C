#include <stdio.h>

int main() {
    float income, tax = 0;

    // Input annual income in Lakhs
    printf("Enter your annual income in Lakhs: ");
    scanf("%f", &income);

    // Tax calculation based on given slabs
    if (income <= 2.5) {
        tax = 0;
    }
    else if (income > 2.5 && income <= 5.0) {
        tax = (income - 2.5) * 0.05;
    }
    else if (income > 5.0 && income <= 10.0) {
        tax = (5.0 - 2.5) * 0.05;              // Tax for slab 2.5L–5L
        tax += (income - 5.0) * 0.20;         // Tax for slab 5L–10L
    }
    else {
        tax = (5.0 - 2.5) * 0.05;              // Tax for slab 2.5L–5L
        tax += (10.0 - 5.0) * 0.20;           // Tax for slab 5L–10L
        tax += (income - 10.0) * 0.30;        // Tax above 10L
    }

    printf("Total Tax Payable: %.2f Lakhs\n", tax);

    return 0;
}