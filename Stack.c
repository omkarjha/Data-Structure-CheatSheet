#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->size = size;
    stack->top = -1;
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d has been pushed to the stack.\n", data);
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}
void display(Stack *stack)
{
    int i; 
    if(isEmpty(stack))
    {
        printf("The stack is empty");
        return;
    }
    else
    {
        printf("The status of the stack is: ");
        for (i = stack -> top; i >= 0; i--)
        {
            printf("%d \t",stack->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &size);

    Stack *stack = createStack(size);
    int choice, data;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be pushed: ");
            scanf("%d", &data);
            push(stack, data);
            break;
        case 2:
            printf("%d has been popped from the stack.\n", pop(stack));
            break;
        case 3:
            printf("Top element is %d\n", peek(stack));
            break;
        case 4:
            display(stack);
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
