#include <stdio.h>
#include <string.h>

int main() {
    char name[50], regNumber[20], section[10];
    int numEmployees;
    int salary[10];
    int i, menuOption;
    int sum = 0, max, min;
    float avg;

    printf("=== Employee Salary Analyzer ===\n");

    // Step 1: Get student details
    printf("Enter your Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    printf("Enter Registration Number: ");
    fgets(regNumber, sizeof(regNumber), stdin);
    regNumber[strcspn(regNumber, "\n")] = '\0';

    printf("Enter Section: ");
    fgets(section, sizeof(section), stdin);
    section[strcspn(section, "\n")] = '\0';

    // Step 2: Enter number of employees
    printf("\nEnter number of employees (1-10): ");
    scanf("%d", &numEmployees);

    // Step 3: Input salaries
    for (i = 0; i < numEmployees; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%d", &salary[i]);
    }

    // Step 4: Menu-driven options
    do {
        printf("\n----- MENU -----\n");
        printf("1. View Salaries\n");
        printf("2. Find Total and Average Salary\n");
        printf("3. Find Highest and Lowest Salary\n");
        printf("4. Show Employees Above/Below Average\n");
        printf("5. Sort Salaries (Ascending)\n");
        printf("6. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &menuOption);

        if (menuOption == 1) {
            printf("\nEmployee Salaries:\n");
            for (i = 0; i < numEmployees; i++) {
                printf("%d\n", salary[i]);
            }
        }

        else if (menuOption == 2) {
            sum = 0;
            for (i = 0; i < numEmployees; i++) {
                sum += salary[i];
            }
            avg = (float)sum / numEmployees;
            printf("\nTotal Salary: %d\n", sum);
            printf("Average Salary: %.2f\n", avg);
        }

        else if (menuOption == 3) {
            max = salary[0];
            min = salary[0];
            for (i = 1; i < numEmployees; i++) {
                if (salary[i] > max)
                    max = salary[i];
                if (salary[i] < min)
                    min = salary[i];
            }
            printf("\nHighest Salary: %d\n", max);
            printf("Lowest Salary: %d\n", min);
        }

        else if (menuOption == 4) {
            sum = 0;
            for (i = 0; i < numEmployees; i++) {
                sum += salary[i];
            }
            avg = (float)sum / numEmployees;

            int aboveCount = 0, belowCount = 0;
            for (i = 0; i < numEmployees; i++) {
                if (salary[i] > avg)
                    aboveCount++;
                else if (salary[i] < avg)
                    belowCount++;
            }
            printf("\nEmployees Above Average: %d\n", aboveCount);
            printf("Employees Below Average: %d\n", belowCount);
        }

        else if (menuOption == 5) {
            // Using simple sorting (Selection Sort instead of Bubble Sort)
            for (i = 0; i < numEmployees - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < numEmployees; j++) {
                    if (salary[j] < salary[minIndex])
                        minIndex = j;
                }
                // Swap
                int temp = salary[i];
                salary[i] = salary[minIndex];
                salary[minIndex] = temp;
            }

            printf("\nSalaries in Ascending Order:\n");
            for (i = 0; i < numEmployees; i++) {
                printf("%d\n", salary[i]);
            }
        }

        else if (menuOption == 6) {
            printf("\nThank you for using the Salary Analyzer!\n");
        }

        else {
            printf("\nInvalid option! Please select a valid choice.\n");
        }

        // Student info display
        if (menuOption >= 1 && menuOption <= 5) {
            printf("\n-- Submitted By --\n");
            printf("Name: %s\n", name);
            printf("Reg No: %s\n", regNumber);
            printf("Section: %s\n", section);
        }

    } while (menuOption != 6);

    return 0;
}
