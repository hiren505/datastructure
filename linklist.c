#include <stdio.h>
#include <stdlib.h>


//Structure defined
typedef struct link
{
	int data;
	struct link * next;
}node;

//Global Variables
node *head = NULL;
node *tail = NULL;

//Function to append a value to a linked list
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


//To display a linked list
void display()
{
	node * current = head;

	if(current == NULL)
	{
		printf("\n\nNo values are present\n\n");
	}
	else
	{
		while(current->next != NULL)
		{
			printf("\n Value is : %d",current->data);
			current = current->next;
		}
		printf("\n Value is : %d",current->data);
	}
	return;
}

//deletes a particular value
void delete()
{
	int value;
	int found = 0;
	node *prev = head;
	node *now = head;

	printf("\n\nEnter the value You want to delete : ");
	scanf("%d",&value);

	while(now->next != NULL)
	{
		if(now->data == value)
		{
			prev->next = now->next;
			free(now);
			found = 1;
		}
		prev->next = now->next;
		now = now->next;
	}

	if(found == 0)
	{
		printf("\n\nThe value Entered is not found in the list\n\n");
	}
	if(found == 1)
	{
		printf("\n\nValue Deleted Successfully\n\n");
	}
}

//Function to display the available options
void options()
{
	printf("\n\n\n0 : To quit");
	printf("\n1: To add a node");
	printf("\n2: To delete a node");
	printf("\n3: To display the linked list\n\n");
}

//Main funcion
int main()
{
	int choice;

	options();
	printf("\nEnter Your Choice : ");
	scanf("%d",&choice);

	while(choice != 0)
	{
		switch(choice)
		{
			case 0: printf("\nCasw 0 Quit");
			case 1: append();
					break;
			case 2: delete();
					break;
			case 3: display();
					break;
			default: printf("\nThis coice is not present");
		}
		options();
		printf("\n\nEnter Your Choice : ");
		scanf("%d" , &choice);
	}

	printf("\n\nThank You \n\n");

}