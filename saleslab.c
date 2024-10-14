// Name: Calder Kamman
// KUID: 3123207

#include <stdio.h>
#define MONTHS 12

void printMonthlySalesReport(float sales[]);
void printSalesSummaryReport(float sales[]);
void printSixMonthMovingAverage(float sales[]);
void printSalesReportDescending(float sales[]);

int main() {
    float sales[MONTHS];
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter the sales for each month:\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("Enter sales for %s: ", months[i]);
        scanf("%f", &sales[i]);
    }

    printMonthlySalesReport(sales);
    printSalesSummaryReport(sales);
    printSixMonthMovingAverage(sales);
    printSalesReportDescending(sales);

    return 0;
}

void printMonthlySalesReport(float sales[]) {
    printf("\nMonthly Sales Report:\n");
    printf("Month\tSales\n");
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < MONTHS; i++) {
        printf("%d\t$%.2f\n", months[i], sales[i]);
    }
}

void printSalesSummaryReport(float sales[]) {
    float min = sales[0], max = sales[0], total = 0;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;           
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }

    float average = total / MONTHS;

    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\nSales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", average);
}

void printSixMonthMovingAverage(float sales[]) {
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i <= MONTHS - 6; i++) {
        float total = 0;
        for (int j = i; j < i +6; j++) {
            total += sales[j];
        }
        float average = total / 6;

        printf("%s-%s: $%.2f\n", months[i], months[i + 5], average);
    }
}

void printSalesReportDescending(float sales[]) {
    float sortedSales[MONTHS];
    int monthsSorted[MONTHS];
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        monthsSorted[i] = i;
    }

    for (int i = 0; i < MONTHS -1; i++) {
        for(int j = i + 1; j < MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                float tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                int tempMonth = monthsSorted[i];
                monthsSorted[i] = monthsSorted[j];
                monthsSorted[j] = tempMonth;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[monthsSorted[i]], sortedSales[i]);
    }
}