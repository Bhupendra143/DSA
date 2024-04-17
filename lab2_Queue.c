#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int queue_arr[MAX];
int rear = -1;
int front = -1;
int IsEmpty()
{
	if (front == -1 && rear == -1) 
	{
		return 1; 
	}
	else
	{
		return 0; 
	}
}
void Enqueue()
{
	int added_item;
	if (rear == MAX - 1)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	else
	{
		if (IsEmpty() == 1) 
		{
			printf("Queue is Empty, Your are going to create a queue\n");
			front = 0;
		}
		printf("\nInput the element for adding in queue:");
		scanf("%d", &added_item);
		rear = rear + 1;
		queue_arr[rear] = added_item;
	}
}
void Dequeue()
{
	if (IsEmpty() == 1)
	{
		printf("\nQueue Underflow or Queue is Empty\n");
		return;
	}
	else
	{
		printf("\nElement deleted from queue is : %d\n",queue_arr[front]);
		front = front + 1;
	}
} 
void Traverse()
{
	int i;
	
	if (IsEmpty() == 1)
	{
		printf("\nQueue is empty\n");
		return;
	}
	else
	{
		printf("\nFront is %d and Queue is :\n", front);
		for (i = front; i <= rear; i++)
			printf("%d ", queue_arr[i]);
		printf("\n");
	}
} 
int main()
{
	int choice;
	while (1)
	{
		printf("\n1.Enqueue Operation\n");
		printf("2.Dequeue Operation\n");
		printf("3.Traverse Operation\n");
		printf("4.Size of Queue\n");
		printf("5.Quit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Enqueue();
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Traverse();
			break;
		case 4:
			printf("The size of the queue is %d\n", rear - front + 1);
			break;
		case 5:
			exit(1);
		default:
			printf("\n Wrong choice\n");
		} 
	}	  
	return 0;
} 
