#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 50 

struct Student {
    char name[MAX_NAME_LENGTH];
    int marks;
};

void findHighestScorer(struct Student students[], int count) {
    int i;
    int maxMarks = -1;
    char highestScorerName[MAX_NAME_LENGTH];
    
    for (i = 0; i < count; i++) {
        if (students[i].marks > maxMarks) {
            maxMarks = students[i].marks;
            strcpy(highestScorerName, students[i].name); 
        }
    }
    
    printf("\n----------------------------------------\n");
    printf("Highest Scorer: %s with %d marks\n", highestScorerName, maxMarks);
    printf("----------------------------------------\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;
    int i;
    char buffer[10]; 

    printf("How many students will you enter (max %d)? ", MAX_STUDENTS);
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &numStudents) != 1) {
        printf("Invalid input for number of students.\n");
        return 1;
    }

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students entered.\n");
        return 1;
    }

    printf("Please enter the name and marks for each student:\n");
    
    for (i = 0; i < numStudents; i++) {
        printf("Student %d Name: ", i + 1);
        
        if (fgets(students[i].name, MAX_NAME_LENGTH, stdin) == NULL) {
            printf("Error reading name.\n");
            return 1;
        }
        
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        
        printf("Student %d Marks: ", i + 1);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &students[i].marks) != 1) {
            printf("Invalid input for marks.\n");
            return 1;
        }

        if (students[i].marks < 0 || students[i].marks > 100) {
            printf("Marks must be between 0 and 100.\n");
            return 1;
        }
    }

    printf("\n--- Student Marks ---\n");
    printf("Name\t\tMarks\n");
    printf("---------------------\n");
    
    for (i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\n", students[i].name, students[i].marks);
    }
    
    findHighestScorer(students, numStudents);

    return 0;
}

