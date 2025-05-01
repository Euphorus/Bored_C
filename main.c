#include<stdio.h>
#include<stdlib.h>
#include "node_type.h"


int main(void)
{
	Node* first = (Node*)malloc(sizeof(Node));

	//assigning data
	first->data = 10;

	//Creating the second node in the list
	Node* second = (Node*)malloc(sizeof(Node));

	//assigning the second data
	second->data = 20;

	//Creating the third node
	Node* third = (Node*)malloc(sizeof(Node));

	//Assigning the third data
	third->data = 30;

	//linking the nodes
	first->next = second;
	second->next = third;
	third->next = NULL;

	printf("Linked List: ");
	Node* temp = first;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	return 0;
}