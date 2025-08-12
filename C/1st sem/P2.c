#include <stdio.h>

int main() {
    int quiz1, quiz2, quiz3;
    int midterm, final;
    int quizTotal, total;

    printf("========Quizzes=============\n");
    printf("Enter the score of the first quiz: ");
    scanf("%d", &quiz1);
    printf("Enter the score of the second quiz: ");
    scanf("%d", &quiz2);
    printf("Enter the score of the third quiz: ");
    scanf("%d", &quiz3);

    printf("========Mid-term============\n");
    printf("Enter the score of the mid-term: ");
    scanf("%d", &midterm);

    printf("========Final================\n");
    printf("Enter the score of the final: ");
    scanf("%d", &final);

    quizTotal = quiz1 + quiz2 + quiz3;
    total = quizTotal + midterm + final;

    printf("\nQuiz Total: %d\n", quizTotal);
    printf("Mid-term: %d\n", midterm);
    printf("Final: %d\n", final);
    printf("..................\n");
    printf("Total: %d\n", total);

    return 0;
}
