// WAP in C Language to perform enqueue,dequeue and display operations on a queue using Linked List.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue node structure
struct QueueNode
{
    int data;
    struct QueueNode *next;
};

struct QueueNode *front = NULL;
struct QueueNode *rear = NULL;

// Function prototypes
void enqueue(int data);
int dequeue();
bool isEmpty();
void displayQueue();

int main()
{
    int choice, data;

    do
    {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            if (!isEmpty())
            {
                printf("Dequeued element: %d\n", dequeue());
            }
            else
            {
                printf("Queue is empty.\n");
            }
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Deallocate memory before exiting
    while (!isEmpty())
    {
        dequeue();
    }

    return 0;
}

void enqueue(int data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Enqueue operation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d has been enqueued.\n", data);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    }

    struct QueueNode *temp = front;
    int data = temp->data;

    front = front->next;
    free(temp);

    if (front == NULL)
    {
        rear = NULL;
    }

    return data;
}

bool isEmpty()
{
    return (front == NULL);
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue contents: ");
        struct QueueNode *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
