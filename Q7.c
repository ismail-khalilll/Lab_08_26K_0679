#include <stdio.h>

int findMax(int *p, int n) {
    int i, mx = *p;
    for (i = 1; i < n; i++)
        if (*(p + i) > mx) mx = *(p + i);
    return mx;
}

int findMin(int *p, int n) {
    int i, mn = *p;
    for (i = 1; i < n; i++)
        if (*(p + i) < mn) mn = *(p + i);
    return mn;
}

double findAverage(int *p, int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) sum += *(p + i);
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (*(p + i) > avg) count++;
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    int i;
    for (i = 0; i < n; i++)
        if (*(p + i) == key) return i;
    return -1;
}

void printArray(int *p, int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", *(p + i));
    printf("\n");
}

int main(void) {
    int marks[10];
    const int N = 10;
    int i;

    for (i = 0; i < N; i++) {
        do {
            printf("Enter marks of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
        } while (marks[i] < 0 || marks[i] > 100);
    }

    double avg = findAverage(marks, N);
    printf("\nHighest mark : %d\n", findMax(marks, N));
    printf("Lowest mark  : %d\n", findMin(marks, N));
    printf("Average      : %.2f\n", avg);
    printf("Students above average: %d\n", countAbove(marks, N, avg));

    int passCount = 0;
    int *p;
    for (p = marks; p < marks + N; p++)
        if (*p >= 40) passCount++;
    printf("Pass count (40 or more): %d\n", passCount);

    int key;
    printf("\nEnter a mark to search: ");
    scanf("%d", &key);
    int pos = searchMark(marks, N, key);
    if (pos == -1) printf("Mark %d not found.\n", key);
    else           printf("Mark %d found at position %d (roll no. %d).\n", key, pos, pos + 1);

    printf("\nBefore reversing: ");
    printArray(marks, N);
    reverseArray(marks, N);
    printf("After reversing : ");
    printArray(marks, N);
    return 0;
}