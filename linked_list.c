#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head;

void begin_insert();
void last_insert();
void begin_delete();
void last_delete();
void display();
void search();

int main()
{
	int choice = 0;
	while (choice != 7)
	{
		printf("\nConsider the following list:\n");
		printf("\n1.Insert at Begining\n2.Insert at Last\n3.Delete at Begining\n4.Delete at Last\n5.Display the Linked List\n6.Search for an element in the list\n7.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				begin_insert();
				break;
			case 2:
				last_insert();
				break;
			case 3:
				begin_delete();
				break;
			case 4:
				last_delete();
				break;
			case 5:
				display();
				break;
			case 6:
				search();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Please enter a valid choice....");
		}
	}
}

void begin_insert()
{
	struct Node *ptr;
	int item;
	ptr = (struct Node*)malloc(sizeof(struct Node*));
	if(ptr == NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("\nEnter the value\n");
		scanf("%d",&item);
		ptr ->data = item;
		ptr ->next = head;
		head = ptr;
		printf("\nNode Inserted\n");
	}
}

void last_insert()
{
	struct Node *ptr,*temp;
	int item;
	ptr = (struct Node*)malloc(sizeof(struct Node*));
	if(ptr == NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("\nEnter the value\n");
		scanf("%d",&item);
		ptr ->data = item;
		if(head == NULL)
		{
			ptr ->next = NULL;
			head = ptr;
			printf("\n Node Inserted");
		}
		else
		{
			temp = head;
			while (temp -> next !=NULL)
			{
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> next = NULL;
			printf("\nNode Inserted");
		}
	}
}

void begin_delete()
{
	struct Node *ptr;
	if(head == NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("\nNode deleted from the begining....\n");
	}
	
}

void last_delete()
{
	struct Node *ptr,*ptr1;
	if (head == NULL)
	{
		printf("List is empty");
	}
	else if(head -> next == NULL)
	{
		head = NULL;
		free(head);
		printf("The single node from the list is deleted");

	}
	else
	{
		ptr = head;
		while(ptr -> next != NULL)
		{
			ptr1 = ptr;
			ptr = ptr -> next;
		}
		ptr1 -> next = NULL;
		free(ptr);
		printf("...\nNode from the end has been deleted...\n");
	}
}
void search()
{
	struct Node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL)
	{
		printf("\nEmpty List\n");
	}
	else
	{
		printf("\nEnter the item which you want to search?\n");   
     	scanf("%d",&item);  
        	while (ptr!=NULL)  
        	{  
          	if(ptr->data == item)  
            	{  
                	printf("Item found at the location %d ",i+1);  
                	flag=0;  
            	}   
            	else  
            	{  
                	flag=1;  
            	}  
            	i++;  
            	ptr = ptr -> next;  
        	}  
        	if(flag==1)  
        	{  
            printf("Item not found in the last\n");  
        	}  
    }     
          
}  
  
void display()
{
	struct Node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("\nNo values to be printed\n");
	}
	else
	{
		printf("The values of the list are:");
		while(ptr != NULL)
		{
			printf("\n%d",ptr -> data);
			ptr = ptr -> next;
		}
	}
}