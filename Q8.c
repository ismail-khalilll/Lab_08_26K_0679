#include <stdio.h>
#include <stdlib.h>

void display(int *a, int n) {
    int i;
    if (n == 0) { printf("Stock is empty.\n"); return; }
    for (i = 0; i < n; i++)
        printf("Item %d: %d\n", i + 1, *(a + i));
}

void showSummary(int *a, int n) {
    if (n == 0) { printf("Total stock: 0 (no items)\n"); return; }
    int total = 0;
    int *lowest = a, *p;
    for (p = a; p < a + n; p++) {
        total += *p;
        if (*p < *lowest) lowest = p;
    }
    printf("Total stock: %d\n", total);
    printf("Lowest stock: item %d with %d\n", (int)(lowest - a) + 1, *lowest);
}

int readStock(void) {
    int v;
    do {
        printf("Enter stock value (0 or more): ");
        scanf("%d", &v);
    } while (v < 0);
    return v;
}

void updateStock(int *a, int n) {
    int pos;
    if (n == 0) { printf("Nothing to update.\n"); return; }
    printf("Enter position (1-%d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) { printf("Invalid position.\n"); return; }
    *(a + pos - 1) = readStock();
    showSummary(a, n);
}

/* a and n are passed by address so the function can change them */
void insertItem(int **a, int *n) {
    int pos, i;
    printf("Enter position to insert (1-%d): ", *n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1) { printf("Invalid position.\n"); return; }
    int value = readStock();

    int *b = (int *)malloc((*n + 1) * sizeof(int));
    if (b == NULL) { printf("Memory allocation failed.\n"); return; }
    for (i = 0; i < pos - 1; i++) *(b + i) = *(*a + i);
    *(b + pos - 1) = value;
    for (i = pos - 1; i < *n; i++) *(b + i + 1) = *(*a + i);

    free(*a);
    *a = b;
    (*n)++;
    showSummary(*a, *n);
}

void deleteItem(int **a, int *n) {
    int pos, i, k = 0;
    if (*n == 0) { printf("Nothing to delete.\n"); return; }
    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n) { printf("Invalid position.\n"); return; }

    int *b = NULL;
    if (*n > 1) {
        b = (int *)malloc((*n - 1) * sizeof(int));
        if (b == NULL) { printf("Memory allocation failed.\n"); return; }
        for (i = 0; i < *n; i++)
            if (i != pos - 1) *(b + k++) = *(*a + i);
    }

    free(*a);
    *a = b;
    (*n)--;
    showSummary(*a, *n);
}

void sortStock(int *a, int n) {
    int i;
    int *p;
    for (i = 0; i < n - 1; i++)
        for (p = a; p < a + n - 1 - i; p++)
            if (*p > *(p + 1)) {
                int t = *p; *p = *(p + 1); *(p + 1) = t;
            }
    printf("Stock sorted in ascending order.\n");
    showSummary(a, n);
}

int main(void) {
    int n, i, choice;
    do {
        printf("Enter starting number of items (3-8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));
    if (stock == NULL) { printf("Memory allocation failed.\n"); return 1; }
    for (i = 0; i < n; i++) {
        printf("Item %d - ", i + 1);
        *(stock + i) = readStock();
    }
    showSummary(stock, n);

    do {
        printf("\n1. Display stock\n2. Update stock of one item\n3. Insert a new item\n"
               "4. Delete an item\n5. Sort stock\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(stock, n); break;
            case 2: updateStock(stock, n); break;
            case 3: insertItem(&stock, &n); break;
            case 4: deleteItem(&stock, &n); break;
            case 5: sortStock(stock, n); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    free(stock);
    stock = NULL;
    printf("Memory released.\n");
    return 0;
}