#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

struct Node
{
	int data;
	struct Node * next;
};

int insert_node_start(struct Node* head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;
	if(!head)
	{
		printf("List is empty... Inserting at begining...\n");
		head = new_node;printf("\nhead->data in !head is %d\n",new_node->data);
		return 1;
	}
	new_node->next = head->next;
	head->next = new_node;
	printf("\nnew value appended in list is head->data is %d\n",new_node->data);
	return 1;
}

int insert_afterRef(struct Node* ref, int newData)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = newData;
	new_node->next = NULL;
	if(!ref)
	{
		printf("\nERROR\n");
		return 0;
	}
	new_node->next = ref->next;
	ref->next = new_node;
	printf("\nvalue added in ref is %d\n",ref->data);
	return 1;
	
}
void printList(struct Node* head)
{	struct Node* cur;
	cur = head;
	if(!cur)
	return 0;
	while((cur->next))
	{
		cur = cur->next;
		printf("list is %d",cur->data);
	}
}
int main()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = NULL;
	head->next = NULL;
	struct Node* ref = (struct Node*)malloc(sizeof(struct Node));
	ref->next = NULL;
	struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
	//head = NULL;
	//ref = NULL;
	insert_node_start(head,NULL);
	insert_node_start(head,5);
	//insert_afterRef(head,3);
	printList(head);
return 0;
}
