#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100

// Define the structure for a student
typedef struct {
    char full_name[MAX_NAME_LENGTH];
    int ds_grade; // Data Structures in C
    int mad_grade; // Mobile Application Development
    int csharp_grade; // Programming in C#
    int ml_grade; // Machine Learning Techniques
    int blockchain_grade; // Introduction to Blockchain Development
} Student;

// Function to input student data
void inputStudentData(Student *student) {
    printf("Enter full name of the student: ");
    fgets(student->full_name, MAX_NAME_LENGTH, stdin);
    student->full_name[strcspn(student->full_name, "\n")] = '\0'; // Remove the newline character

    printf("Enter grade for Data Structures in C (0-100): ");
    scanf("%d", &student->ds_grade);

    printf("Enter grade for Mobile Application Development (0-100): ");
    scanf("%d", &student->mad_grade);

    printf("Enter grade for Programming in C# (0-100): ");
    scanf("%d", &student->csharp_grade);

    printf("Enter grade for Machine Learning Techniques (0-100): ");
    scanf("%d", &student->ml_grade);

    printf("Enter grade for Introduction to Blockchain Development (0-100): ");
    scanf("%d", &student->blockchain_grade);

    getchar(); // To consume the newline character left by the previous scanf
}

// Function to write student data to a file
void writeStudentDataToFile(Student *students, int n) {
    FILE *file = fopen("students_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "Full Name: %s\n", students[i].full_name);
        fprintf(file, "Data Structures in C: %d\n", students[i].ds_grade);
        fprintf(file, "Mobile Application Development: %d\n", students[i].mad_grade);
        fprintf(file, "Programming in C#: %d\n", students[i].csharp_grade);
        fprintf(file, "Machine Learning Techniques: %d\n", students[i].ml_grade);
        fprintf(file, "Introduction to Blockchain Development: %d\n", students[i].blockchain_grade);
        fprintf(file, "----------------------------------------\n");
    }

    fclose(file);
}

int main() {
    int n;

    // Get the number of students
    printf("Enter the number of students (5 < n < 100): ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    if (n <= 5 || n >= 100) {
        printf("Invalid number of students. Please enter a value between 6 and 99.\n");
        return 1;
    }

    Student students[n]; // Declare an array of students

    // Input data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        inputStudentData(&students[i]);
    }

    // Write the student data to a file
    writeStudentDataToFile(students, n);

    printf("Data has been written to students_data.txt.\n");

    return 0;
}
