										//STUDENT MANANGEMENT SYSTEM
#include <stdio.h>
#include <stdlib.h>

const int MAX = 100; // Maximum number of students

// Student information stored in A Structure
struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

// Global array and student count tracker
struct Student students[MAX];
int count = 0;

// Function declarations
void addStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("\nPlease enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("\nThank you for using the Student Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Oops! That’s not a valid option. Please try again.\n");
        }
    }

    return 0;
}

// Show menu options to the user
void displayMenu() {
    printf("\n====== Student Management System ======\n");
    printf("1. Add a New Student\n");
    printf("2. Search for a Student\n");
    printf("3. Update Student Information\n");
    printf("4. Delete a Student Record\n");
    printf("5. Exit the Program\n");
}

// Add a new student's details
void addStudent() {
    if (count >= MAX) {
        printf("\nSorry, the student list is full. You can't add more students.\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);  // Read full name with spaces

    printf("Enter Student Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Student Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// Search for a student by their ID
void searchStudent() {
    int id, found = 0;
    printf("\n--- Search Student ---\n");
    printf("Enter the Student ID you're looking for: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n✅ Student Found:\n");
            printf("ID    : %d\n", students[i].id);
            printf("Name  : %s\n", students[i].name);
            printf("Age   : %d\n", students[i].age);
            printf("Marks : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ No student found with ID %d.\n", id);
    }
}

// Update an existing student's details
void updateStudent() {
    int id, found = 0;
    printf("\n--- Update Student ---\n");
    printf("Enter the Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("✅ Student information updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Student with ID %d not found. Cannot update.\n", id);
    }
}

// Delete a student from the record
void deleteStudent() {
    int id, found = 0;
    printf("\n--- Delete Student ---\n");
    printf("Enter the Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            // Shift the remaining students to fill the gap
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("✅ Student with ID %d has been deleted successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Student with ID %d not found. Nothing was deleted.\n", id);
    }
}

