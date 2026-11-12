#include <stdio.h>
#include <ctype.h>

void printRoutes(void) {
    printf("\n===== CITY BUS SERVICE =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

int getRoute(void) {
    int r;
    do {
        printf("Enter route number (1-3): ");
        scanf("%d", &r);
    } while (r < 1 || r > 3);
    return r;
}

int getSeats(void) {
    int s;
    do {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &s);
    } while (s < 1 || s > 6);
    return s;
}

char getSeatType(void) {
    char c;
    do {
        printf("Seat type - Economy (E) or Business (B): ");
        scanf(" %c", &c);
        c = toupper(c);
    } while (c != 'E' && c != 'B');
    return c;
}

const char *getRouteName(int route) {
    if (route == 1) return "Karachi to Hyderabad";
    if (route == 2) return "Karachi to Sukkur";
    return "Karachi to Multan";
}

double getSeatFare(int route) {
    if (route == 1) return 800;
    if (route == 2) return 2200;
    return 3500;
}

double getTotalFare(double seatFare, int seats) {
    return seatFare * seats;
}

double addSeatTypeCharge(double total, char type) {
    if (type == 'B') return total + total * 0.30;
    return total;
}

void printTicket(const char *route, int seats, char type, double fare) {
    printf("\n------- BUS TICKET -------\n");
    printf("Route     : %s\n", route);
    printf("Seats     : %d\n", seats);
    printf("Seat Type : %s\n", type == 'B' ? "Business" : "Economy");
    printf("Final Fare: Rs. %.2f\n", fare);
    printf("--------------------------\n");
}

int main(void) {
    double totalEarnings = 0;
    int i;
    for (i = 1; i <= 2; i++) {
        printf("\n*** Passenger %d of 2 ***", i);
        printRoutes();
        int route = getRoute();
        int seats = getSeats();
        char type = getSeatType();

        double total = getTotalFare(getSeatFare(route), seats);
        double finalFare = addSeatTypeCharge(total, type);

        printTicket(getRouteName(route), seats, type, finalFare);
        totalEarnings += finalFare;
    }
    printf("\nTotal earnings of the bus company: Rs. %.2f\n", totalEarnings);
    return 0;
}