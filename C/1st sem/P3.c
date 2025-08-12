#include <stdio.h>

int main() {
    char name[50], regNo[20], address[100];
    int age;
    float weight, cgpa;
    double height;

    // Input section
    printf("Enter Name of Student: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter Register Number: ");
    fgets(regNo, sizeof(regNo), stdin);

    printf("Enter Address: ");
    fgets(address, sizeof(address), stdin);

    printf("Enter Age (in years): ");
    scanf("%d", &age);

    printf("Enter Weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter Height (in meters): ");
    scanf("%lf", &height);

    printf("Enter CGPA/percentage: ");
    scanf("%f", &cgpa);

    // Output section
    printf("\nName of Student: %s", name);
    printf("Roll Number: %s", regNo);
    printf("Percentage Score Secured: %.1f%%\n", cgpa);

    return 0;
}
