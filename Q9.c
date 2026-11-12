#include <stdio.h>
#include <string.h>

/* C has no references (&), so "send back" parameters are pointers. */

void readMarks(int *m1, int *m2, int *m3) {
    do { printf("  Subject 1 marks (0-100): "); scanf("%d", m1); } while (*m1 < 0 || *m1 > 100);
    do { printf("  Subject 2 marks (0-100): "); scanf("%d", m2); } while (*m2 < 0 || *m2 > 100);
    do { printf("  Subject 3 marks (0-100): "); scanf("%d", m3); } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;
    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortDescending(int *a, int *b, int *c) {
    if (*a < *b) swapMarks(a, b);
    if (*b < *c) swapMarks(b, c);
    if (*a < *b) swapMarks(a, b);
}

void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark <= 39) {
        int needed = 40 - *mark;
        if (grace > 5) grace = 5;
        *mark += (grace < needed) ? grace : needed;
    }
}

void findGrade(double avg, char *grade, char *remarks) {
    if (avg >= 80)      { *grade = 'A'; strcpy(remarks, "Excellent"); }
    else if (avg >= 60) { *grade = 'B'; strcpy(remarks, "Good"); }
    else if (avg >= 40) { *grade = 'C'; strcpy(remarks, "Needs Improvement"); }
    else                { *grade = 'F'; strcpy(remarks, "Needs Improvement"); }
}

void incrementByValue(int x)      { x++; }
void incrementByReference(int *x) { (*x)++; }

int main(void) {
    int totals[5], highs[5], lows[5], i;
    double avgs[5];
    char grades[5];
    char remarks[5][20];

    for (i = 0; i < 5; i++) {
        int m1, m2, m3, grace;
        printf("\nStudent %d:\n", i + 1);
        readMarks(&m1, &m2, &m3);
        do {
            printf("  Grace marks to give (0-5): ");
            scanf("%d", &grace);
        } while (grace < 0 || grace > 5);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        sortDescending(&m1, &m2, &m3);
        calculateStats(m1, m2, m3, &totals[i], &avgs[i], &highs[i], &lows[i]);
        findGrade(avgs[i], &grades[i], remarks[i]);
        printf("  Marks after grace (high to low): %d %d %d\n", m1, m2, m3);
    }

    printf("\n%-9s%-8s%-10s%-8s%-8s%-7s%s\n", "Student", "Total", "Average", "High", "Low", "Grade", "Remarks");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < 5; i++)
        printf("%-9d%-8d%-10.2f%-8d%-8d%-7c%s\n", i + 1, totals[i], avgs[i], highs[i], lows[i], grades[i], remarks[i]);

    int num = 10;
    incrementByValue(num);
    printf("\nAfter incrementByValue(num)     : %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference(&num): %d\n", num);
    /* incrementByValue changes only a copy of num, so the original stays 10.
       incrementByReference receives num's address and changes num itself, so it becomes 11. */
    return 0;
}