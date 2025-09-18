#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
struct Student {
    int roll;
    char name[50];
    struct Student* next;
};

struct Student* head = NULL; // head pointer

// Function to insert a student record at the end
void insertStudent(int roll, char name[]) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No records found!\n");
        return;
    }
    struct Student* temp = head;
    printf("\nStudent Records:\n");
    printf("Roll\tName\n");
    while (temp != NULL) {
        printf("%d\t%s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, roll;
    char name[50];

    while (1) {
        printf("\n--- Student Linked List Menu ---\n");
        printf("1. Insert a student record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf(" %[^\n]s", name);  // read string with spaces
                insertStudent(roll, name);
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
