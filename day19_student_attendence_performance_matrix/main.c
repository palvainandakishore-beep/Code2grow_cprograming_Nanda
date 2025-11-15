#include <stdio.h>

int main() {
    int attendance[5][5], marks[5][5];
    char names[5][20];
    int present[5] = {0}, absent[5] = {0};      // helper arrays (still arrays)
    int total[5] = {0};                         // helper arrays
    float avg[5] = {0.0f};                      // helper arrays
    int i, j, option;

    /* ---------- INPUT ---------- */
    printf("Input names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Name of student %d: ", i + 1);
        scanf("%19s", names[i]);
    }

    printf("\nRecord attendance (1=Present, 0=Absent):\n");
    for (i = 0; i < 5; i++) {
        printf("Attendance for %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &attendance[i][j]);
            present[i] += attendance[i][j];          // accumulate while reading
        }
        absent[i] = 5 - present[i];
    }

    printf("\nRecord marks (0-100):\n");
    for (i = 0; i < 5; i++) {
        printf("Marks for %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];                 // accumulate while reading
        }
        avg[i] = total[i] / 5.0f;
    }

    /* ---------- MENU ---------- */
    do {
        printf("\n====== STUDENT DATA MENU ======\n");
        printf("1. Show Attendance Table\n");
        printf("2. Show Marks Table\n");
        printf("3. Generate Attendance Summary\n");
        printf("4. Generate Performance Summary\n");
        printf("5. Show Grade Report\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        /* ---- 1. Attendance Table ---- */
        if (option == 1) {
            printf("\nAttendance Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%-15s", names[i]);
                for (j = 0; j < 5; j++) printf("%d ", attendance[i][j]);
                printf("\n");
            }
        }

        /* ---- 2. Marks Table ---- */
        else if (option == 2) {
            printf("\nMarks Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%-15s", names[i]);
                for (j = 0; j < 5; j++) printf("%d ", marks[i][j]);
                printf("\n");
            }
        }

        /* ---- 3. Attendance Summary ---- */
        else if (option == 3) {
            int maxP = -1, minP = 6, idxMax = 0, idxMin = 0;
            for (i = 0; i < 5; i++) {
                if (present[i] > maxP) { maxP = present[i]; idxMax = i; }
                if (present[i] < minP) { minP = present[i]; idxMin = i; }
            }
            printf("\nAttendance Summary:\n");
            for (i = 0; i < 5; i++)
                printf("%-15s Present: %d, Absent: %d\n", names[i], present[i], absent[i]);
            printf("Top Attendance: %s with %d classes present\n", names[idxMax], maxP);
            printf("Lowest Attendance: %s with %d classes present\n", names[idxMin], minP);
        }

        /* ---- 4. Performance Summary ---- */
        else if (option == 4) {
            int maxT = -1, minT = 501, idxTop = 0, idxLow = 0;
            for (i = 0; i < 5; i++) {
                if (total[i] > maxT) { maxT = total[i]; idxTop = i; }
                if (total[i] < minT) { minT = total[i]; idxLow = i; }
            }
            printf("\nPerformance Summary:\n");
            for (i = 0; i < 5; i++)
                printf("%-15s Total: %d, Average: %.2f\n", names[i], total[i], avg[i]);
            printf("Topper: %s with %d total marks\n", names[idxTop], maxT);
            printf("Lowest Performer: %s with %d total marks\n", names[idxLow], minT);
        }

        /* ---- 5. Grade Report ---- */
        else if (option == 5) {
            printf("\nGrade Report:\n");
            for (i = 0; i < 5; i++) {
                char grade;
                if (avg[i] >= 90)      grade = 'A';   // A+ shown as A+ in printf
                else if (avg[i] >= 80) grade = 'A';
                else if (avg[i] >= 70) grade = 'B';
                else if (avg[i] >= 60) grade = 'C';
                else if (avg[i] >= 50) grade = 'D';
                else                   grade = 'F';

                printf("%-15s Average: %.2f, Grade: %c%s\n",
                       names[i], avg[i],
                       (avg[i] >= 90 ? 'A' : grade),
                       (avg[i] >= 90 ? "+" : ""));
            }
        }

        /* ---- 6. Exit ---- */
        else if (option == 6) {
            printf("Program terminated. Have a nice day!\n");
        }

        /* ---- Invalid ---- */
        else {
            printf("Invalid option. Try again.\n");
        }

    } while (option != 6);

    return 0;
}
