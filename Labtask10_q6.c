#include <stdio.h>

int main() {
    char names[5][20] = {"Alice", "Bob", "Charlie", "David", "Emma"};
    int marks[5] = {85, 92, 78, 88, 95};

    int i;
    int topMarks = marks[0];
    int topIndex = 0;
    float sum = 0, average;

    // Print table
    printf("Student Marks Table:\n");
    printf("------------------------------\n");
    printf("Name\t\tMarks\n");
    printf("------------------------------\n");

    for (i = 0; i < 5; i++) {
        printf("%-10s\t%d\n", names[i], marks[i]);
        sum += marks[i];

        if (marks[i] > topMarks) {
            topMarks = marks[i];
            topIndex = i;
        }
    }

    // Calculate average
    average = sum / 5;

    printf("------------------------------\n");
    printf("Top Student: %s with %d marks\n", names[topIndex], topMarks);
    printf("Class Average: %.2f\n", average);

    return 0;
}

