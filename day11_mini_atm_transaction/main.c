#include <stdio.h>

int main() 
{
    int choice, transaction_count = 0, max_transaction = 5;
    float balance = 10000.0, amount;

    printf("Welcome to Mini Bank Transaction System\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. CHECK BALANCE\n");
        printf("2. DEPOSIT\n");
        printf("3. WITHDRAW\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Amount deposited successfully!\n");
                printf("Updated balance: %.2f\n", balance);
            } else {
                printf("Invalid deposit amount!\n");
            }
            transaction_count++;
        } 
        else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("Withdrawal successful!\n");
                printf("Remaining balance: %.2f\n", balance);
            } else {
                printf("Invalid withdrawal amount!\n");
            }
            transaction_count++;
        } 
        else if (choice == 1) {
            printf("Current Balance: %.2f\n", balance);
        } 
        else if (choice == 4) {
            printf("Thank you for using Mini Bank!\n");
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }

        if (transaction_count >= max_transaction && choice != 4) {
            printf("\nMaximum transaction limit reached. Session ended automatically.\n");
            break;
        }

    } while (choice != 4);

    printf("\n--- Transaction Summary ---\n");
    printf("Total Transactions: %d\n", transaction_count);
    printf("Final Balance: %.2f\n", balance);
    printf("\nP. Nanda Kishore | AP25110090190\n");

    return 0;
}
