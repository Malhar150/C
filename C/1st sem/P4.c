#include <stdio.h>
int main()
{
    char name[50], rolno[50];
    int age;
    float weight, cgpa;
    double height;

    // Input Section
    printf("Enter the Name of Student:");
    fgets(name, sizeof(name), stdin);

    printf("Enter the roll no:");
    fgets(rolno, sizeof(rolno), stdin);

    printf("Enter Age(in years)");
    scanf("%d", &age);

    printf("Enter Weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter Height (in meters): ");
    scanf("%lf", &height);

    printf("Enter CGPA/percentage: ");
    scanf("%f", &cgpa);

    Heightt = height % 100 Weightt = weight % 1000 AgeM = age * 12

                                                          printf("\nName of Student: %s", name);
    printf("Roll no: %s", rolno);
    printf("Age in months:", AgeM);
    printf("Weight of the student:", Weightt);
    printf("Height of the student:", Heightt);
    printf("Percentage Score Secured: %.1f%%\n", cgpa);

    return 0;
}