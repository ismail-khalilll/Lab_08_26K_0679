#include <stdio.h>

int main(void) {
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, profit, profitPercent;

    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty  = &quantity;
    double *pTotalCost  = &totalCost;
    double *pTotalSales = &totalSales;
    double *pProfit     = &profit;
    double *pPercent    = &profitPercent;

    printf("Enter cost price: ");
    scanf("%lf", pCost);
    printf("Enter selling price: ");
    scanf("%lf", pSell);
    printf("Enter quantity sold: ");
    scanf("%lf", pQty);

    *pTotalCost  = (*pCost) * (*pQty);
    *pTotalSales = (*pSell) * (*pQty);
    *pProfit     = *pTotalSales - *pTotalCost;

    printf("\nTotal cost  : Rs. %.2f\n", *pTotalCost);
    printf("Total sales : Rs. %.2f\n", *pTotalSales);

    if (*pProfit > 0)      printf("Result: Profit of Rs. %.2f\n", *pProfit);
    else if (*pProfit < 0) printf("Result: Loss of Rs. %.2f\n", -(*pProfit));
    else                   printf("Result: No profit no loss\n");

    if (*pTotalCost != 0) {
        *pPercent = (*pProfit / *pTotalCost) * 100;
        printf("Profit percentage: %.2f%%\n", *pPercent);
    } else {
        *pPercent = 0;
        printf("Profit percentage: cannot be calculated (total cost is 0)\n");
    }

    double *pLarger = (*pCost >= *pSell) ? pCost : pSell;
    printf("\nLarger price pointer points to: %s with value %.2f\n",
           (pLarger == pCost) ? "costPrice" : "sellPrice", *pLarger);

    printf("\n%-14s%-20s%s\n", "Name", "Address", "Holds");
    printf("------------------------------------------------------\n");
    printf("%-14s%-20p%.2f\n", "costPrice",   (void *)&costPrice,   costPrice);
    printf("%-14s%-20p%.2f\n", "sellPrice",   (void *)&sellPrice,   sellPrice);
    printf("%-14s%-20p%.2f\n", "quantity",    (void *)&quantity,    quantity);
    printf("%-14s%-20p%.2f\n", "totalCost",   (void *)&totalCost,   totalCost);
    printf("%-14s%-20p%.2f\n", "totalSales",  (void *)&totalSales,  totalSales);
    printf("%-14s%-20p%.2f\n", "profit",      (void *)&profit,      profit);
    printf("%-14s%-20p%.2f\n", "profitPct",   (void *)&profitPercent, profitPercent);
    printf("%-14s%-20p%p\n", "pCost",       (void *)&pCost,       (void *)pCost);
    printf("%-14s%-20p%p\n", "pSell",       (void *)&pSell,       (void *)pSell);
    printf("%-14s%-20p%p\n", "pQty",        (void *)&pQty,        (void *)pQty);
    printf("%-14s%-20p%p\n", "pTotalCost",  (void *)&pTotalCost,  (void *)pTotalCost);
    printf("%-14s%-20p%p\n", "pTotalSales", (void *)&pTotalSales, (void *)pTotalSales);
    printf("%-14s%-20p%p\n", "pProfit",     (void *)&pProfit,     (void *)pProfit);
    printf("%-14s%-20p%p\n", "pPercent",    (void *)&pPercent,    (void *)pPercent);
    printf("%-14s%-20p%p\n", "pLarger",     (void *)&pLarger,     (void *)pLarger);
    printf("\n(Third column: value for variables, address stored for pointers)\n");
    return 0;
}