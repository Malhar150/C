#include <stdio.h>
int main()
{
    // Calculate the total no of secounds in a particular time

    int hours, minutes, secounds;
    int jam, pam, totalsecounds;

    printf("hours:");
    scanf("%d", &hours);

    printf("minutes:");
    scanf("%d", &minutes);

    printf("secound:");
    scanf("%d", &secounds);

    jam = hours * 60 * 60;
    pam = minutes * 60;

    totalsecounds = jam + pam;

    printf("Enter the total no of secounds:%d", totalsecounds);
    return 0;
}