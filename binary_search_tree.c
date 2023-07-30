// WAP in C language to form Binary Search Tree and perform operations such as insertion,deletion,search and then do all three traversals.


#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *left;
     struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->left = newNode->right = NULL;
     return newNode;
}

// Function to insert a new node in the BST
struct Node *insert(struct Node *root, int data)
{
     if (root == NULL)
     {
          return createNode(data);
     }

     if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = insert(root->right, data);
     }

     return root;
}

// Function to find the minimum value node in a BST
struct Node *findMin(struct Node *root)
{
     while (root->left != NULL)
     {
          root = root->left;
     }
     return root;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int key)
{
     if (root == NULL)
     {
          return root;
     }

     if (key < root->data)
     {
          root->left = deleteNode(root->left, key);
     }
     else if (key > root->data)
     {
          root->right = deleteNode(root->right, key);
     }
     else
     {
          // Node with only one child or no child
          if (root->left == NULL)
          {
               struct Node *temp = root->right;
               free(root);
               return temp;
          }
          else if (root->right == NULL)
          {
               struct Node *temp = root->left;
               free(root);
               return temp;
          }

          struct Node *temp = findMin(root->right);

          root->data = temp->data;

          root->right = deleteNode(root->right, temp->data);
     }
     return root;
}

// Function to search for a node in the BST
struct Node *search(struct Node *root, int key)
{
     if (root == NULL || root->data == key)
     {
          return root;
     }

     if (key < root->data)
     {
          return search(root->left, key);
     }

     return search(root->right, key);
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          inOrderTraversal(root->left);
          printf("%d ", root->data);
          inOrderTraversal(root->right);
     }
}

// Function to perform pre-order traversal
void preOrderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          printf("%d ", root->data);
          preOrderTraversal(root->left);
          preOrderTraversal(root->right);
     }
}

// Function to perform post-order traversal
void postOrderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          postOrderTraversal(root->left);
          postOrderTraversal(root->right);
          printf("%d ", root->data);
     }
}

// Function to free the memory and delete the BST
void deleteTree(struct Node *root)
{
     if (root == NULL)
     {
          return;
     }
     deleteTree(root->left);
     deleteTree(root->right);
     free(root);
}

int main()
{
     struct Node *root = NULL;
     int choice, data, key;

     do
     {
          printf("\nBinary Search Tree Operations\n");
          printf("1. Insert\n");
          printf("2. Delete\n");
          printf("3. Search\n");
          printf("4. In-order Traversal\n");
          printf("5. Pre-order Traversal\n");
          printf("6. Post-order Traversal\n");
          printf("7. Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               printf("Enter data to insert: ");
               scanf("%d", &data);
               root = insert(root, data);
               break;
          case 2:
               printf("Enter data to delete: ");
               scanf("%d", &data);
               root = deleteNode(root, data);
               break;
          case 3:
               printf("Enter data to search: ");
               scanf("%d", &key);
               struct Node *result = search(root, key);
               if (result != NULL)
               {
                    printf("Node with data %d found.\n", result->data);
               }
               else
               {
                    printf("Node not found.\n");
               }
               break;
          case 4:
               printf("In-order Traversal: ");
               inOrderTraversal(root);
               printf("\n");
               break;
          case 5:
               printf("Pre-order Traversal: ");
               preOrderTraversal(root);
               printf("\n");
               break;
          case 6:
               printf("Post-order Traversal: ");
               postOrderTraversal(root);
               printf("\n");
               break;
          case 7:
               printf("Exiting...\n");
               break;
          default:
               printf("Invalid choice. Please try again.\n");
          }

     } while (choice != 7);

     // Clean up the memory by deleting the entire BST
     deleteTree(root);

     return 0;
}