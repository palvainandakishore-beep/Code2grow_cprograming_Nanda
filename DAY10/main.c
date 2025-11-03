#include <stdio.h>

int main() {
    int totalCustomers;
    int customerNumber = 1;
    int totalRevenue = 0;

    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);

    while (customerNumber <= totalCustomers) {
        printf("\n--- Customer %d ---\n", customerNumber);
        printf("Menu Card:\n");
        printf("1. Sandwich - Rs 80\n");
        printf("2. Burger   - Rs 120\n");
        printf("3. Pizza    - Rs 150\n");
        printf("4. Coffee   - Rs 60\n");
        printf("5. Juice    - Rs 50\n");

        int numberOfItems;
        printf("Enter number of items: ");
        scanf("%d", &numberOfItems);

        int totalBill = 0;

        for (int i = 1; i <= numberOfItems; i++) {
            int itemCode, quantity, price = 0;

            printf("\nEnter item code: ");
            scanf("%d", &itemCode);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            // Set price based on item code
            if (itemCode == 1)
                price = 80;
            else if (itemCode == 2)
                price = 120;
            else if (itemCode == 3)
                price = 150;
            else if (itemCode == 4)
                price = 60;
            else if (itemCode == 5)
                price = 50;
            else {
                printf("Invalid item code! Skipping item.\n");
                continue;
            }

            totalBill = totalBill + (price * quantity);
        }

        printf("\nTotal Bill = Rs %d\n", totalBill);

        int discount = 0;
        if (totalBill > 500) {
            discount = totalBill * 10 / 100;
            printf("Discount (10%%) = Rs %d\n", discount);
        }

        int finalBill = totalBill - discount;
        printf("Final Bill = Rs %d\n", finalBill);

        totalRevenue = totalRevenue + finalBill;
        customerNumber++;
    }

    printf("\n--- Canteen Summary ---\n");
    printf("Total Customers Served: %d\n", totalCustomers);
    printf("Total Revenue: Rs %d\n", totalRevenue);

    return 0;
}
