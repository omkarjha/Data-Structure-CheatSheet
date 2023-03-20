#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     int data;
     struct node *prev;
     struct node *next;
} Node;

Node *head = NULL;

void display();
void insert();
void delete();
void search();

int main()
{
     int choice;

     do
     {
          printf("\nDoubly Linked List Operations\n");
          printf("1. Display List\n");
          printf("2. Insert Node\n");
          printf("3. Delete Node\n");
          printf("4. Search List\n");
          printf("5. Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               display();
               break;
          case 2:
               insert();
               break;
          case 3:
               delete ();
               break;
          case 4:
               search();
               break;
          case 5:
               printf("Exiting from the program...\n");
               exit(0);
          default:
               printf("Invalid choice. Please try again.\n");
          }
     } while (1);

     return 0;
}

void display()
{
     if (head == NULL)
     {
          printf("List is empty.\n");
          return;
     }
     Node *temp = head;
     printf("List: ");
     while (temp != NULL)
     {
          printf("%d ", temp->data);
          temp = temp->next;
     }
     printf("\n");
}

void insert()
{
     int data;
     Node *new_node = (Node *)malloc(sizeof(Node));
     if (new_node == NULL)
     {
          printf("Memory allocation failed.\n");
          return;
     }
     printf("Enter the data to be inserted: ");
     scanf("%d", &data);
     new_node->data = data;
     new_node->prev = NULL;
     new_node->next = head;
     if (head != NULL)
     {
          head->prev = new_node;
     }
     head = new_node;
     printf("%d inserted successfully.\n", data);
}

void delete()
{
     int data;
     Node *temp;
     if (head == NULL)
     {
          printf("List is empty.\n");
          return;
     }
     printf("Enter the data to be delete: ");
     scanf("%d", &data);
     temp = head;
     while (temp != NULL)
     {
          if (temp->data == data)
          {
               if (temp->prev != NULL)
               {
                    temp->prev->next = temp->next;
               }
               else
               {
                    head = temp->next;
               }

               if (temp->next != NULL)
               {
                    temp->next->prev = temp->prev;
               }
               free(temp);
               printf("%d deleted successfully.\n", data);
               return;
          }
          temp = temp->next;
     }
     printf("%d not found in list.\n", data);
}

void search()
{
     int data, position = 0;
     Node *temp;
     if (head == NULL)
     {
          printf("List is empty.\n");
          return;
     }
     printf("Enter data to search: ");
     scanf("%d", &data);
     temp = head;
     while (temp != NULL)
     {
          position++;
          if (temp->data == data)
          {
               printf("%d found at position %d.\n", data, position);
               return;
          }
          temp = temp->next;
     }
     printf("%d not found in list.\n", data);
}