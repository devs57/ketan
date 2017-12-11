#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};

struct node* header, *ptr, *temp;

void insert_start();
void insert_end();
void insert_any();
void display();

int main()
{
	int choice;
	int cont = 1;
	header = (struct node*)malloc(sizeof(struct node));
	header->data = NULL;
	header->link = NULL;
	while(cont == 1)
	{
	
        printf("\n1. Insert start\n2.Insert End\n3.Insert any position\n4.Dispplay\n");
        printf("\nChoose your option\n");
        scanf("%d",&choice);

	switch(choice)
	{
	case 1:
		insert_start();
	break;
	case 2:
		insert_end();
	break;
	case 3:
		insert_any();
	break;
	case 4:
		display();
	break;
	default:
		printf("\nPlease choose a valid option from 1 to 4\n");
	break;
	}
	printf("\nDo you want to continue 1/0\n");
	scanf("%d",&cont);
	}
}

void insert_start()
{
	int data_value;

	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data_value;
	temp->link = header->link;
	header->link = temp;
}

void insert_end()
{
	  int data_value;

        printf("\nEnter data of the last node: ");
        scanf("%d", &data_value);

        temp = (struct node*)malloc(sizeof(struct node));
	ptr = header;
	while(ptr->link!= NULL)
	{
		ptr = ptr->link;
	}
	temp->data = data_value;
	temp->link = ptr->link;
	ptr->link = temp; 
}

void insert_any()
{
	int key,data;
	printf("\nEnter data you want to insert\n");
	scanf("%d",&data);
	printf("\nEnter the key after which you want to insert data\n");
	scanf("%d",&key);
	temp = (struct node*)malloc(sizeof(struct node));
	ptr = header;
	while(ptr->link!= NULL && ptr->data!=key)
	{
		ptr=ptr->link;
	}
	if(ptr->data == key)
	{
		temp->data = data;
		temp->link = ptr->link;
		ptr->link = temp;
	}
	else
	{
		printf("\nData not found\n");
	}
}

void display()
{
	printf("\nContents of the linked list are: \n");
	ptr = header;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
		printf("%d ", ptr->data);
	}
}
