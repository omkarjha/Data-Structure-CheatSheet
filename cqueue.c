#include <stdio.h>
#include <stdlib.h>

struct Q
{
	int front;
	int rear;
	int arr[10];
};
void insert_queue(struct Q*);
int delete_queue(struct Q*);
void display_queue(struct Q*);
int isempty(struct Q*);
int isfull(struct Q*);


int main()
{
	struct Q S;
	S.front=S.rear=-1;
	int choice;
	while(1)
	{
                printf("Enter a choice:\n 0->Enqueue \n 1->Dequeue\n 2->Display the queue\n 3 ->exit\n");                                                                                      
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				insert_queue(&S);
				break;
			case 1:
				delete_queue(&S);
				break;
			case 2:
				display_queue(&S);
				break;
			case 3:
				return 0;
			default:
				printf("Wrong Input.\n");
		}
	}
	return 0;
}
int isfull(struct Q *S)
{
	if(S->front==(S->rear+1)%5)
	{
		return 1;
	}
	else 
	{
		return 	0;
	}
}

int isempty(struct Q *S)
{
	if(S->front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}	

void insert_queue(struct Q *S)
{
	int item;
	printf("Enter the element you want to insert:");
	scanf("%d",&item);

	if (isfull(S))
	{
		printf("Queue is full \n");
	}
	else
	{
		if((S->front==-1 && S->rear==-1))
		{
			S->front=0;
			S->rear=0;
		}
		else
		{
			S->rear=(S->rear+1)%5;
		}
		S->arr[S->rear]=item;
	}
}


int delete_queue(struct Q *S)
{
	int item;
	if (isempty(S))
	{
		printf("Queue is empty \n");
	}
	
	else
	{
		item=S->arr[S->front];
		printf("Element deleted is : %d \n",item);
	
		if(S->front==S->rear)
		{
			S->front=-1;
			S->rear=-1;
		}
		else
		{
			S->front=(S->front+1)%5;
		}
	}
	return item;
} 
void display_queue(struct Q *S)
{
	int i;
	if(isempty(S))
	{
		printf("Queue is empty....nothing to display.\n");
	}
	else
	{
		printf("The status of my queue is: \n");
		i=S->front;
		while(i!=S->rear)
		{
			printf("%d \t",S->arr[i%5]);
			i = (i+1)%5;
		}
		printf("%d \t",S->arr[S->rear]);
	}printf("\n");
}	