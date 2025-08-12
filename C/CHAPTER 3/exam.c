#include <stdio.h>

int main() {
    float sub1, sub2, sub3;
    float total, percentage;

    // Taking marks as input
    printf("Enter marks for subject 1: ");
    scanf("%f", &sub1);
    printf("Enter marks for subject 2: ");
    scanf("%f", &sub2);
    printf("Enter marks for subject 3: ");
    scanf("%f", &sub3);

    // Calculate total and percentage
    total = sub1 + sub2 + sub3;
    percentage = (total / 300) * 100; // Assuming each subject is out of 100

    // Check pass conditions
    if (percentage >= 40 && sub1 >= 33 && sub2 >= 33 && sub3 >= 33) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}