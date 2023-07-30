// WAP in C language to create an array of structures and display its value

#include <stdio.h>
#include <string.h>

// Define the structure
struct Student
{
    char name[50];
    int age;
    float roll_number;
};

int main()
{
    int size;

    // Create an array of structures
    printf("Enter the size of the array :\n");
    scanf("%d", &size);
    struct Student students[size];

    // Input student details
    for (int i = 0; i < size; i++)
    {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);


        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter roll number for student %d: ", i + 1);
        scanf("%f", &students[i].roll_number);
    }

    // Display student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Roll Number: %.2f\n\n", students[i].roll_number);
    }

    return 0;
}
