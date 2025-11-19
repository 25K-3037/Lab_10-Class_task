#include <stdio.h>
#include <string.h>

int main() {
    // Student names
    char students[4][20] = {"Alice", "Bob", "Charlie", "Diana"};

    // Each student's courses
    char courses[4][5][20] = {
        {"Math", "Physics", "English"},                       // Alice: 3 courses
        {"Biology", "Chemistry"},                             // Bob: 2 courses
        {"Math", "Physics", "Chemistry", "Computer"},         // Charlie: 4 courses
        {"History", "English", "Art", "Math", "Physics"}      // Diana: 5 courses
    };

    // Number of courses per student (must match the lists above)
    int courseCount[4] = {3, 2, 4, 5};

    int i, j;
    char searchCourse[20];

    // 1. Display all students with their courses
    printf("=== Student Course List ===\n");
    for (i = 0; i < 4; i++) {
        printf("%s is taking: ", students[i]);
        for (j = 0; j < courseCount[i]; j++) {
            printf("%s  ", courses[i][j]);
        }
        printf("\n");
    }

    printf("\n-------------------------------------------\n");

    // 2. Find students taking a specific course
    printf("Enter course to search (e.g., Physics): ");
    scanf("%s", searchCourse);

    printf("\nStudents taking %s:\n", searchCourse);

    int found = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < courseCount[i]; j++) {
            if (strcmp(courses[i][j], searchCourse) == 0) {
                printf("%s\n", students[i]);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("No student is taking this course.\n");
    }

    printf("\n-------------------------------------------\n");

    // 3. Identify overloaded students
    printf("Students with MORE than 3 courses:\n");

    int overloadFound = 0;
    for (i = 0; i < 4; i++) {
        if (courseCount[i] > 3) {
            printf("%s (taking %d courses)\n", students[i], courseCount[i]);
            overloadFound = 1;
        }
    }

    if (!overloadFound) {
        printf("No overloaded students.\n");
    }

    return 0;
}

