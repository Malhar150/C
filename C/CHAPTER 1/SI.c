#include <stdio.h>
    int main(){
         
int principal,rate,time;

        printf("Enter the principal amount \n");
        scanf("%d",&principal);

        printf("Enter the rate of interest \n");
        scanf("%d",&rate);

        printf("Enter no. of years \n");
        scanf("%d",&time);

        printf("The total amount is %d",(principal*rate*time)/100);

    }