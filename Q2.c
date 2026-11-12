#include <stdio.h>

void printRooms(void) {
    printf("===== CITY CARE HOSPITAL =====\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
}

int getRoomType(void) {
    int t;
    do {
        printf("Enter room type (1-3): ");
        scanf("%d", &t);
    } while (t < 1 || t > 3);
    return t;
}

int getDays(void) {
    int d;
    do {
        printf("Enter days stayed (1-30): ");
        scanf("%d", &d);
    } while (d < 1 || d > 30);
    return d;
}

const char *getRoomName(int type) {
    if (type == 1) return "General Ward";
    if (type == 2) return "Semi-Private";
    return "Private";
}

double getRoomCharges(int type, int days) {
    int rate = 0;
    switch (type) {
        case 1: rate = 1500; break;
        case 2: rate = 3500; break;
        case 3: rate = 6000; break;
    }
    return rate * days;
}

double getMedicineCharge(double bill) {
    return bill + bill * 0.05;
}

double applyDiscount(double total, int days) {
    if (days >= 7) return total - total * 0.08;
    return total;
}

void printBill(const char *room, int days, double roomCharges, double medCharges, double finalAmount) {
    printf("\n------- FINAL BILL -------\n");
    printf("Room           : %s\n", room);
    printf("Days           : %d\n", days);
    printf("Room Charges   : Rs. %.2f\n", roomCharges);
    printf("Medicine Charge: Rs. %.2f\n", medCharges);
    printf("Final Amount   : Rs. %.2f\n", finalAmount);
    printf("--------------------------\n");
}

int main(void) {
    printRooms();
    int type = getRoomType();
    int days = getDays();

    double medBill;
    do {
        printf("Enter medicine bill: ");
        scanf("%lf", &medBill);
    } while (medBill < 0);

    double roomCharges = getRoomCharges(type, days);
    double medCharges = getMedicineCharge(medBill);
    double finalAmount = applyDiscount(roomCharges + medCharges, days);

    char senior;
    do {
        printf("Is the patient a senior citizen? (y/n): ");
        scanf(" %c", &senior);
    } while (senior != 'y' && senior != 'Y' && senior != 'n' && senior != 'N');

    if (senior == 'y' || senior == 'Y') finalAmount -= 1000;
    if (finalAmount < 0) finalAmount = 0;

    printBill(getRoomName(type), days, roomCharges, medCharges, finalAmount);
    return 0;
}