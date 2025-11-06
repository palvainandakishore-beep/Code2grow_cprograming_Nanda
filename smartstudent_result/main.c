#include <stdio.h>

int main() {
    int totalStudents;
    int studentNumber = 1;
    int marks1, marks2, marks3;
    int totalMarks;
    float average;
    int passedCount = 0, failedCount = 0;
    float classTotalAverage = 0;
    float highestAverage = 0, lowestAverage = 100;
    char grade;
    printf("Enter the total number of students: ");
    scanf("%d", &totalStudents);
    while (studentNumber <= totalStudents) {
        printf("\nStudent %d:\n", studentNumber);
        printf("Enter marks for subject 1 :");
        scanf("%d", &marks1);
        printf("Enter marks for subject 2 : ");
        scanf("%d", &marks2);
        printf("Enter marks for subject 3 : ");
        scanf("%d", &marks3);
        totalMarks = marks1 + marks2 + marks3;
        average = totalMarks / 3.0;
        if (average >= 90) {
            grade = 'A';  
        } else if (average >= 80) {
            grade = 'B';  
        } else if (average >= 70) {
            grade = 'C'; 
        } else if (average >= 60) {
            grade = 'D'; 
        } else if (average >= 50) {
            grade = 'E'; 
        } else {
            grade = 'F';  
        }
        printf("Student %d Total Marks: %d\n", studentNumber, totalMarks);
        printf("Student %d Average Marks: %.2f\n", studentNumber, average);
        if (grade == 'A') {
            printf("Grade: A+ (Excellent)\n");
        } else if (grade == 'B') {
            printf("Grade: A (Very Good)\n");
        } else if (grade == 'C') {
            printf("Grade: B (Good)\n");
        } else if (grade == 'D') {
            printf("Grade: C (Average)\n");
        } else if (grade == 'E') {
            printf("Grade: D (Pass)\n");
        } else {
            printf("Grade: Fail\n");
        }
        if (grade == 'F') {
            failedCount = failedCount + 1;
        } else {
            passedCount = passedCount + 1;
        }
        if (average > highestAverage) {
            highestAverage = average;
        }
        if (average < lowestAverage) {
            lowestAverage = average;
        }
        classTotalAverage = classTotalAverage + average;
        studentNumber = studentNumber + 1;
    }
    int choice = 0;
    while (choice != 3) {
        printf("\nMenu:\n");
        printf("1. View All Results\n");
        printf("2. View Class Summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("All individual student results were shown during data entry.\n");
            printf("For detailed reports, please refer to the above individual results.\n");
        } 
        else if (choice == 2) {    
            printf("\nClass Summary:\n");
            printf("Total Students: %d\n", totalStudents);
            printf("Passed: %d\n", passedCount);
            printf("Failed: %d\n", failedCount);
            printf("Class Average Marks: %.2f\n", classTotalAverage / totalStudents);
            printf("Highest Average Marks: %.2f\n", highestAverage);
            printf("Lowest Average Marks: %.2f\n", lowestAverage);
        } 
        else if (choice == 3) {
            printf("Exiting the program. Thank you!\n");
        } 
        else {
            printf("Invalid choice, please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}
