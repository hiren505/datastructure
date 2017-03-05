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

	if(now == NULL)
	{
		printf("\n\nThere are no Items on the list\n\n");
		return;
	}

	printf("\n\nEnter the value You want to delete : ");
	scanf("%d",&value);


	if(head->data == value)
	{
		node *new_head = head->next;
		free(head);
		head = new_head;
		found = 1;
		printf("\n\nValue Deleted Successfully\n\n");
		return;
	}
	else
	{

		while(now->next != NULL)
		{
			if(now->data == value)
			{
				prev->next = now->next;
				found = 1;
				free(now);
				printf("\n\nValue Deleted Successfully\n\n");
				return;
			}
			
			prev = now;
			now = now->next;
			
		}

		if(now->data == value)
		{
			prev->next = NULL;
			found = 1;
			free(now);
			printf("\n\nValue Deleted Successfully\n\n");
			//Make sure you change tail when you delete last node of the list
			tail = prev;										
			return;
		}
	}

	if(found == 0)
	{
		printf("\n\nThe value Entered is not found in the list\n\n");
	}
	return;
}

//To add ata particular position
void add_at_particular_position()
{
	int value;
	int data;

	if(head == NULL)
	{
		printf("\n\nNo nodes found in the Linked List \n\n");
		return;
	}

	printf("\n\nEnter the New data You want to add to a linked list  : ");
	scanf("%d" , &data);

	printf("\n\nEnter the valu after which you want to add a node :");
	scanf("%d",&value);

	node * now = head;



	if(head->data == value)
	{
		node *newnode = malloc(sizeof(node));
		newnode->data = data;
		newnode->next = head->next;
		head->next = newnode;

		printf("\n\nNew data added at the desired position\n\n");
		return;
	}
}

//Function to display the available options
void options()
{
	printf("\n\n\n0 : To quit");
	printf("\n1: To add a node");
	printf("\n2: To delete a node");
	printf("\n3: To display the linked list");
	printf("\n4: To add at a particular position\n\n");
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
			case 4: add_at_particular_position();
					break;
			default: printf("\nThis coice is not present");
		}
		options();
		printf("\n\nEnter Your Choice : ");
		scanf("%d" , &choice);
	}

	printf("\n\nThank You \n\n");

}