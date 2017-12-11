#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void insert_start(struct node** head, int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

void insert_end(struct node** head, int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = (*head);
        new_node->data = data;
	new_node->next =  NULL;
	if((*head) == NULL)
	{
		printf("\nhead is NULL\n");
		(*head) = new_node;
		return;
	}
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new_node;
	return;
}	

void insert_after(struct node* ref, int data)
{
	if(ref == NULL)
	{
		printf("\nthe node you specified is not present\n");
		return;
	}
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
	new_node->next = ref->next;
	ref->next = new_node;
}

void print(struct node* Node)
{
	if(Node == NULL)
	{
		printf("\nList is empty\n");		
		return;
	}
	while(Node){
	printf("\n List=%d\n",Node->data);
	Node= Node->next;
	}
}	

int main()
{
	struct node* head = NULL;
	insert_start(&head,1);
	insert_end(&head,3);
	insert_end(&head,7);
	insert_after(head->next,9);
	print(head);
	return 0;
}
