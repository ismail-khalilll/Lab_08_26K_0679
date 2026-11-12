#include <stdio.h>

void printRules(void) {
    printf("\n===== CITY TAXI SERVICE =====\n");
    printf("Base fare : Rs. 150\n");
    printf("First 10 km : Rs. 60 per km\n");
    printf("After 10 km : Rs. 45 per km\n");
    printf("Waiting     : first 5 min free, then Rs. 10 per min\n");
    printf("Night (10 PM - 6 AM): +25%%\n");
}

double getDistance(void) {
    double d;
    do {
        printf("Enter distance in km (>0, up to 200): ");
        scanf("%lf", &d);
    } while (d <= 0 || d > 200);
    return d;
}

int getWaitingTime(void) {
    int w;
    do {
        printf("Enter waiting time in minutes (0-120): ");
        scanf("%d", &w);
    } while (w < 0 || w > 120);
    return w;
}

int getHour(void) {
    int h;
    do {
        printf("Enter hour of the trip (0-23): ");
        scanf("%d", &h);
    } while (h < 0 || h > 23);
    return h;
}

double getDistanceCharge(double km) {
    double charge = 150;
    if (km <= 10) charge += km * 60;
    else          charge += 10 * 60 + (km - 10) * 45;
    return charge;
}

double getWaitingCharge(int minutes) {
    if (minutes > 5) return (minutes - 5) * 10;
    return 0;
}

double addNightCharge(double fare, int hour) {
    if (hour >= 22 || hour < 6) return fare + fare * 0.25;
    return fare;
}

void printReceipt(double km, int wait, double fare) {
    printf("\n------ TRIP RECEIPT ------\n");
    printf("Distance     : %.2f km\n", km);
    printf("Waiting Time : %d min\n", wait);
    printf("Final Fare   : Rs. %.2f\n", fare);
    printf("--------------------------\n");
}

int main(void) {
    printRules();
    double totalEarnings = 0, highest = 0;
    int i;
    for (i = 1; i <= 3; i++) {
        printf("\n*** Trip %d of 3 ***\n", i);
        double km = getDistance();
        int wait = getWaitingTime();
        int hour = getHour();

        double fare = getDistanceCharge(km) + getWaitingCharge(wait);
        fare = addNightCharge(fare, hour);

        printReceipt(km, wait, fare);
        totalEarnings += fare;
        if (fare > highest) highest = fare;
    }
    printf("\nTotal earnings     : Rs. %.2f\n", totalEarnings);
    printf("Highest fare today : Rs. %.2f\n", highest);
    return 0;
}