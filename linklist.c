/*
*  FILE          : linklist.c
*  PROJECT       : Linked List
*  PROGRAMMER    : Hirenkumar Tank
*  FIRST VERSION : 4th march 2017
*  DESCRIPTION   : I have developed a simple c code to perform the basic operations of a linked-list.
*				   IT performs following basic operations 
*				   1. Append: It takes the value from the user and stores it in a linked list.
*				   2. delete: IT takes the value from the user which the user wants to delete. Then the value
*					          is deleted from the linked list.
*				   3. Add at a particular position : Here the user needs to enter the value after which the user
*													 wants to add the new value. Once he gives the value and the 
*													 value after which the user wants to add, the data is added
*													 at that particular position.                  
*/

//********************************* Header Files ****************************************************************

#include <stdio.h>
#include <stdlib.h>


//********************************* Structure defination *******************************************************
typedef struct link
{
	int data;
	struct link * next;
}node;

//********************************* Global Variables ***********************************************************
node *head = NULL;
node *tail = NULL;

//********************************* Function Declarations ******************************************************


//
// FUNCTION      : append()
// DESCRIPTION   : Appends the value at the end of the list. 
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
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


//
// FUNCTION      : display()
// DESCRIPTION   : Displays all the values in the linked list
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
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

//
// FUNCTION      : delete()
// DESCRIPTION   : Delets a particular value from the linked list
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
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

//
// FUNCTION      : add_at_particular_position()
// DESCRIPTION   : Adds the value at a particular position
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
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

	node *newnode = malloc(sizeof(node));
	newnode->data = data;

	if(head->data == value)
	{
		newnode->next = head->next;
		head->next = newnode;

		printf("\n\nNew data added at the desired position\n\n");
		return;
	}

	while(now->next != NULL)
	{

		if(now -> data == value)
		{
			newnode->next = now->next;
			now->next = newnode;
			printf("\n\nNew data added at the desired position\n\n");
			return;
		}
		else
		{
			now = now->next;
		}
		
	}

	if(now->data == value)
	{
		now->next = newnode;
		newnode->next = NULL;
		tail = newnode;
		printf("\n\nNew data added at the desired position\n\n");
		return;
	}


}

//
// FUNCTION      : options()
// DESCRIPTION   : Contains all the functions that a user can perform a linked list.
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
void options()
{
	printf("\n\n\n0 : To quit");
	printf("\n1: To add a node");
	printf("\n2: To delete a node");
	printf("\n3: To display the linked list");
	printf("\n4: To add at a particular position\n\n");
}

//
// FUNCTION      : append()
// DESCRIPTION   : Appends the value at the end of the list
// PARAMETERS    : No parameters passsed.
// RETURNS       : Does not return anything
//
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