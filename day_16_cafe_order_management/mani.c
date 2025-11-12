#include <stdio.h>
int main() 
{
    int itemnumber[5] = {1, 2, 3, 4, 5};
    char itemNames[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int itemPrices[5] = {50, 30, 80, 120, 60};
    int max_item = 5;
    int numItems, itemNo, quantity;
    int customerTotal, totalRevenue = 0;
    int totalItemsOrdered[5] = {0}; 
    int totalItemsSold = 0;
    int numCustomers;

    printf("========= Café Order Management System =========\n");
    printf("Enter total number of customers (max 10): ");
    scanf("%d", &numCustomers);

    if (numCustomers < 1 || numCustomers > 10) 
    {
        printf("Invalid number of customers\n");
        return 0;
    }

    printf("\n========= MENU =========\n");
    printf("Item No.\tItem Name\tPrice \n");
    for (int i = 0; i < max_item; i++) 
    {
        printf("%d\t\t%s\t\t%d\n", itemnumber[i], itemNames[i], itemPrices[i]);
    }
    printf("========================\n\n");

    for (int j = 1; j <= numCustomers; j++) 
    {
        customerTotal = 0;
        printf("--- Customer %d ---\n", j);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        for (int k = 1; k <= numItems; k++)
        {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &quantity);

            if (itemNo < 1 || itemNo > 5 || quantity < 1)
            {
                printf("Invalid input! Try again.\n");
                k--;
                continue;
            }

            int index = itemNo - 1;
            int cost = itemPrices[index] * quantity;
            customerTotal += cost;
            totalRevenue += cost;
            totalItemsOrdered[index] += quantity;
            totalItemsSold += quantity;
        }

        printf("Total Bill for Customer %d: %d\n\n", j, customerTotal);
    }

    int mostOrdered = 0, leastOrdered = 0;
    for (int i = 1; i < max_item; i++)
    {
        if (totalItemsOrdered[i] > totalItemsOrdered[mostOrdered])
            mostOrdered = i;
        if (totalItemsOrdered[i] < totalItemsOrdered[leastOrdered])
            leastOrdered = i;
    }

    printf("========= Cafe Summary =========\n");
    printf("Total Revenue: %d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", itemNames[mostOrdered]);
    printf("Least Ordered Item: %s\n", itemNames[leastOrdered]);
    printf("================================\n");

    return 0;
}
