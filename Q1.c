#include <stdio.h>

void printMenu(void) {
    printf("\n===== PREPAID RECHARGE =====\n");
    printf("1. Rs. 100\n2. Rs. 200\n3. Rs. 500\n4. Rs. 1000\n");
}

int getPackNumber(void) {
    int pack;
    do {
        printf("Enter pack number (1-4): ");
        scanf("%d", &pack);
    } while (pack < 1 || pack > 4);
    return pack;
}

long long getMobileNumber(void) {
    long long mobile;
    do {
        printf("Enter 11-digit mobile number: ");
        scanf("%lld", &mobile);
    } while (mobile < 1000000000LL || mobile > 99999999999LL); /* a leading 0 is not stored */
    return mobile;
}

int getPackAmount(int pack) {
    int amount = 0;
    switch (pack) {
        case 1: amount = 100;  break;
        case 2: amount = 200;  break;
        case 3: amount = 500;  break;
        case 4: amount = 1000; break;
    }
    return amount;
}

double addTax(double amount) {
    return amount + amount * 0.15;
}

double getBonus(double amount) {
    if (amount >= 500) return amount * 0.10;
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double bonus, double totalBalance) {
    printf("\n------ RECHARGE SLIP ------\n");
    printf("Mobile Number : %011lld\n", mobile);
    printf("Pack Amount   : Rs. %.2f\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Bonus         : Rs. %.2f\n", bonus);
    printf("Total Balance : Rs. %.2f\n", totalBalance);
    printf("---------------------------\n");
}

int main(void) {
    double totalSpent = 0;
    int i;
    for (i = 1; i <= 3; i++) {
        printf("\n*** Recharge %d of 3 ***", i);
        printMenu();
        int pack = getPackNumber();
        long long mobile = getMobileNumber();

        double amount = getPackAmount(pack);
        double amountWithTax = addTax(amount);
        double tax = amountWithTax - amount;
        double bonus = getBonus(amount);
        double totalBalance = amount + bonus;

        printSlip(mobile, amount, tax, bonus, totalBalance);
        totalSpent += amountWithTax;
    }
    printf("\nTotal money spent in 3 recharges: Rs. %.2f\n", totalSpent);
    return 0;
}