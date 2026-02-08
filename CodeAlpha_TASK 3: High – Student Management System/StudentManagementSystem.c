/*
 * Description:
 * A menu-driven program to manage student records.
 * Features:
 *  - Add Student
 *  - Display Students
 *  - Search Student
 *  - Update Student
 *  - Delete Student
 *
 * Uses structures + file handling to store data permanently.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

// Function to add a student
void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while(fread(&s, sizeof(struct Student), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Course: %s\n", s.id, s.name, s.age, s.course);
    }
    fclose(fp);
}

// Function to search a student by ID
void searchStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(struct Student), 1, fp)) {
        if(s.id == id) {
            printf("Record Found: ID: %d | Name: %s | Age: %d | Course: %s\n", s.id, s.name, s.age, s.course);
            found = 1;
            break;
        }
    }
    if(!found) printf("Student not found!\n");
    fclose(fp);
}

// Function to update student record
void updateStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb+");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(struct Student), 1, fp)) {
        if(s.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new Age: ");
            scanf("%d", &s.age);
            printf("Enter new Course: ");
            scanf(" %[^\n]", s.course);

            fseek(fp, -sizeof(struct Student), SEEK_CUR);
            fwrite(&s, sizeof(struct Student), 1, fp);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) printf("Student not found!\n");
    fclose(fp);
}

// Function to delete student record
void deleteStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(struct Student), 1, fp)) {
        if(s.id != id) {
            fwrite(&s, sizeof(struct Student), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if(found) printf("Record deleted successfully!\n");
    else printf("Student not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
