#include <stdio.h>

int main(void) {
    int n, marks[10];
    int highest, lowest;
    int countAplus = 0, countA = 0, countB = 0, countC = 0, countD = 0, countFail = 0;
    int totalPassed = 0, totalFailed = 0;
    float sum = 0.0f, avg = 0.0f;

    printf("========= Student Performance Analyzer =========\n");
    printf("Enter total number of students: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    if (n < 1 || n > 10) {
        printf("Invalid number of students. Please enter up to 10.\n");
        return 0;
    }

    printf("Enter marks for each student:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        if (scanf("%d", &marks[i]) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks entered. Please enter marks between 0 and 100.\n");
            return 0;
        }
    }

    highest = lowest = marks[0];

    for (int i = 0; i < n; i++) {
        int m = marks[i];
        sum += m;
        if (m > highest) highest = m;
        if (m < lowest)  lowest  = m;

        if (m >= 90) { countAplus++; totalPassed++; }
        else if (m >= 80) { countA++; totalPassed++; }
        else if (m >= 70) { countB++; totalPassed++; }
        else if (m >= 60) { countC++; totalPassed++; }
        else if (m >= 50) { countD++; totalPassed++; }
        else { countFail++; totalFailed++; }
    }

    avg = sum / n;

    printf("\n===== Final Report =====\n");
    printf("Average Marks  : %.2f\n", avg);
    printf("Highest Marks  : %d\n", highest);
    printf("Lowest Marks   : %d\n", lowest);
    printf("Passed Students: %d\n", totalPassed);
    printf("Failed Students: %d\n", totalFailed);

    printf("\nGrade Summary:\n");
    printf("A+   : %d\n", countAplus);
    printf("A    : %d\n", countA);
    printf("B    : %d\n", countB);
    printf("C    : %d\n", countC);
    printf("D    : %d\n", countD);
    printf("Fail : %d\n", countFail);
    printf("=========================\n");

    return 0;
}
