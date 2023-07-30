// WAP in C language to implement stack to reverse the string as input.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack node structure
struct StackNode
{
    char data;
    struct StackNode *next;
};

// Function prototypes
void push(struct StackNode **top, char c);
char pop(struct StackNode **top);
int isEmpty(struct StackNode *top);

int main()
{
    struct StackNode *top = NULL;
    char inputString[100];
    int i;

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Push each character of the input string into the stack
    for (i = 0; inputString[i] != '\0'; i++)
    {
        if (inputString[i] != '\n')
        {
            push(&top, inputString[i]);
        }
    }

    // Pop characters from the stack and print them to reverse the string
    printf("Reversed string: ");
    while (!isEmpty(top))
    {
        printf("%c", pop(&top));
    }

    return 0;
}

// Function to push an element onto the stack
void push(struct StackNode **top, char c)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
char pop(struct StackNode **top)
{
    if (isEmpty(*top))
    {
        return '\0'; // Return null character for an empty stack
    }

    char data = (*top)->data;
    struct StackNode *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode *top)
{
    return top == NULL;
}
