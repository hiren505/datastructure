#include <stdio.h>
#include <stdlib.h>



typedef struct link
{
	int data;
	struct node * next;
}node;

node *head = NULL;
node *tail = NULL;

void append()
{
	if(head == NULL)
	{
		head = malloc(sizeof(node));
		printf("\nEnter the Value : ");
		scanf("%d", &(head->data));
		head->next = NULL;
		tail = head;
		return;
	}

	node *newnode = malloc(sizeof(node));
	printf("\nEnter the value : ");
	scanf("%d",&(newnode->data));
	newnode->next = NULL;
	tail -> next = newnode;
	tail = newnode;
	return;

}

void options()
{
}

void display()
{
	node * current = head;

	while(current->next != NULL)
	{
		printf("\n Value is : %d",current->data);
		current = current->next;
	}
	return;
}

int main()
{
	int choice;

	printf("\nEnter Your Choice : ");
	scanf("%d",&choice);

	while(choice != 0)
	{
		switch(choice)
		{
			case 0: printf("\nCasw 0 Quit");
			case 1: printf("\nCase 1 ADD");
					append();
					break;
			case 2: printf("\nCase 2 Delete");
					break;
			case 3: printf("\nCase 3 Display");
					display();
					break;
			default: printf("\nThis coice is not present");
		}
		printf("\n\nEnter Your Choice : ");
		scanf("%d" , &choice);
	}

	printf("\n\nThank You \n\n");

}