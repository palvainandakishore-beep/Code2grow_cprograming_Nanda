#include <stdio.h>

int main() {

    // Arrays to store details of up to 10 products
    int productID[10];
    char productName[10][50];
    int quantity[10];
    float price[10];

    int totalProducts = 0; // How many products the shopkeeper has entered
    int choice;

    while (1) { // Keep showing the menu until the user chooses to exit

        // Menu
        printf("\n=========================\n");
        printf("   SHOP INVENTORY MENU\n");
        printf("=========================\n");
        printf("1. Add Product Details\n");
        printf("2. View All Products\n");
        printf("3. Inventory Summary\n");
        printf("4. Search Product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // -------------------- OPTION 1: ADD PRODUCTS --------------------
        if (choice == 1) {

            if (totalProducts == 10) {
                printf("You have already added 10 products. No more can be stored!\n");
            } 
            else {
                printf("\nEnter Product ID: ");
                scanf("%d", &productID[totalProducts]);

                printf("Enter Product Name: ");
                scanf("%s", productName[totalProducts]);

                printf("Enter Quantity in Stock: ");
                scanf("%d", &quantity[totalProducts]);

                printf("Enter Price per Item: ");
                scanf("%f", &price[totalProducts]);

                printf("Product saved successfully!\n");
                totalProducts++; // Increase product count
            }
        }

        // -------------------- OPTION 2: DISPLAY ALL --------------------
        else if (choice == 2) {

            if (totalProducts == 0) {
                printf("No products have been added yet.\n");
            }
            else {
                printf("\n======= ALL PRODUCTS =======\n");

                for (int i = 0; i < totalProducts; i++) {
                    printf("\nProduct %d\n", i + 1);
                    printf("ID       : %d\n", productID[i]);
                    printf("Name     : %s\n", productName[i]);
                    printf("Quantity : %d\n", quantity[i]);
                    printf("Price    : %.2f\n", price[i]);
                }
            }
        }

        // -------------------- OPTION 3: INVENTORY SUMMARY --------------------
        else if (choice == 3) {

            if (totalProducts == 0) {
                printf("No products available to calculate summary.\n");
            }
            else {
                float totalValue = 0;
                float highestValue, lowestValue;
                int highIndex = 0, lowIndex = 0;

                // Initial values for comparison
                highestValue = quantity[0] * price[0];
                lowestValue = quantity[0] * price[0];

                for (int i = 0; i < totalProducts; i++) {
                    float value = quantity[i] * price[i];
                    totalValue += value;

                    if (value > highestValue) {
                        highestValue = value;
                        highIndex = i;
                    }

                    if (value < lowestValue) {
                        lowestValue = value;
                        lowIndex = i;
                    }
                }

                printf("\n======= INVENTORY SUMMARY =======\n");
                printf("Total Inventory Value: %.2f\n", totalValue);

                printf("\nMost Valuable Product:\n");
                printf("ID: %d, Name: %s, Value: %.2f\n",
                       productID[highIndex], productName[highIndex], highestValue);

                printf("\nLeast Valuable Product:\n");
                printf("ID: %d, Name: %s, Value: %.2f\n",
                       productID[lowIndex], productName[lowIndex], lowestValue);
            }
        }

        // -------------------- OPTION 4: SEARCH BY PRODUCT ID --------------------
        else if (choice == 4) {

            if (totalProducts == 0) {
                printf("No products to search.\n");
            }
            else {
                int searchID;
                int found = 0;

                printf("Enter the Product ID you want to search for: ");
                scanf("%d", &searchID);

                for (int i = 0; i < totalProducts; i++) {
                    if (productID[i] == searchID) {
                        found = 1;
                        printf("\nProduct found!\n");
                        printf("ID       : %d\n", productID[i]);
                        printf("Name     : %s\n", productName[i]);
                        printf("Quantity : %d\n", quantity[i]);
                        printf("Price    : %.2f\n", price[i]);
                        break;
                    }
                }

                if (!found) {
                    printf("No product found with ID %d\n", searchID);
                }
            }
        }

        // -------------------- OPTION 5: EXIT --------------------
        else if (choice == 5) {
            printf("Thank you! Exiting the inventory system.\n");
            break;
        }

        // -------------------- INVALID OPTION --------------------
        else {
            printf("Invalid choice! Please select a valid menu option.\n");
        }
    }

    return 0;
}
