#include <stdio.h>

int *head = NULL;
int *tail = NULL;

struct link
{
	int data;
	struct node * next;
}node;

void add()
{
	if(head == NULL)
	{
		head = malloc(sizeof(node));
		printf("\nEnter the Value :");
		scanf("%d", head->data);
		head->next = NULL;
		tail = head;
	}

	


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
					break;
			case 2: printf("\nCase 2 Delete");
					break;
			case 3: printf("\nCase 3 Display");
					break;
			default: printf("\nThis coice is not present");
		}
		printf("\nEnter Your Choice : ");
		scanf("%d" , &choice);
	}

	printf("\n\nThank You \n\n")

}