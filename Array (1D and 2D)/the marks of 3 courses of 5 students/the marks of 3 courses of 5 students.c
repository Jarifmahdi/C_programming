#include <stdio.h>

int main() {
    int marks[5][3];   
    int i, j;
    
    printf("Enter marks of 5 students (3 courses each):\n");
    for(i = 0; i < 5; i++) {
        printf("Student %d:\n", i+1);
        for(j = 0; j < 3; j++) {
            printf("  Course %d: ", j+1);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\n--- Results ---\n");
    for(i = 0; i < 5; i++) {
        int total = 0, highest = marks[i][0], lowest = marks[i][0];
        
        for(j = 0; j < 3; j++) {
            total += marks[i][j];
            if(marks[i][j] > highest)
                highest = marks[i][j];
            if(marks[i][j] < lowest)
                lowest = marks[i][j];
        }

        float avg = total / 3.0;

        printf("\nStudent %d:\n", i+1);
        printf("  Total Marks = %d\n", total);
        printf("  Average Marks = %.2f\n", avg);
        printf("  Highest Marks = %d\n", highest);
        printf("  Lowest Marks = %d\n", lowest);
    }

    return 0;
}
