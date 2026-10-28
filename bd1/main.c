#include <stdio.h>

int main(void) {
    int n, i;
    double score, credit, points;
    double totalPoints = 0, totalCredit = 0, gpa;
    double max1 = 0, max2 = 0, max3 = 0;
    char grade;

    /* Хичээлийн тоо авах (5-10), буруу бол дахин асууна */
    do {
        printf("Хичээлийн тоо (5-10): ");
        scanf("%d", &n);
    } while (n < 5 || n > 10);

    /* Хүснэгтийн толгой (Flowgorithm-д PrintHeader функц) */
    printf("\n%-8s %-8s %-6s %-8s\n", "Хичээл", "Оноо", "Үсэг", "Кредит");

    i = 1;
    while (i <= n) {
        /* Оноо авах (0-100) */
        do {
            printf("Оноо (0-100): ");
            scanf("%lf", &score);
        } while (score < 0 || score > 100);

        /* Кредит авах (1-6) */
        do {
            printf("Кредит (1-6): ");
            scanf("%lf", &credit);
        } while (credit < 1 || credit > 6);

        /* GetGrade ба GetPoints-ийн логик (else-if шат) */
        if (score >= 90)      { grade = 'A'; points = 4.0; }
        else if (score >= 80) { grade = 'B'; points = 3.0; }
        else if (score >= 70) { grade = 'C'; points = 2.0; }
        else if (score >= 60) { grade = 'D'; points = 1.0; }
        else                  { grade = 'F'; points = 0.0; }

        totalPoints += points * credit;
        totalCredit += credit;

        /* Шилдэг 3 оноог шинэчлэх */
        if (score > max1)      { max3 = max2; max2 = max1; max1 = score; }
        else if (score > max2) { max3 = max2; max2 = score; }
        else if (score > max3) { max3 = score; }

        /* Хүснэгтийн мөр */
        printf("%-8d %-8.1f %-6c %-8.1f\n", i, score, grade, credit);
        i++;
    }

    gpa = totalPoints / totalCredit;
    printf("\nГолч дүн: %.2f\n", gpa);
    printf("Шилдэг 3 оноо: %.1f, %.1f, %.1f\n", max1, max2, max3);

    return 0;
}
