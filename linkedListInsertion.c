#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void linkedListTraverse(struct Node *ptr){
	int n = 0;
	while(ptr != NULL){
		printf("Element %d: %d\n", n, ptr->data);
		ptr = ptr->next;
		n++;
	}
}

// Function that returns (struct node *) datatype output
struct Node * insertAtFirst(struct Node *head, int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->next = head;
	ptr->data = data;

	return ptr;
}

// Function that returns (struct node *) datatype output
struct Node * insertAtIndex(struct Node *head, int index, int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node * p = head;

	for(int i=1; i<index; i++){
		p = p->next;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;

	return ptr;
}

// Function that returns (struct node *) datatype output
struct Node * insertAtEnd(struct Node *head, int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node * p = head;

	while(p->next!= NULL){ 
		p = p->next;
	}
	ptr->data = data;
	ptr->next = NULL;
	p->next = ptr;

	return ptr;
}

int main(){

/*	THIS IS NOT HOW YOU DECLARE/ USE LINKED LIST  */
	// Declaring nodes of the struct
	struct Node *head, *second, *third, *fourth, *node, *end;

	// Allocate memory to the linked list addressses
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node))
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));

	head->data = 13;
	head->next = second;

	second->data = 324;
	second->next = third;

	third->data = 230;
	third->next = fourth;

	fourth->data = 27;
	fourth->next = NULL;

	// Running linked list traverse function
	printf("Linked list before inserting at first\n");
	linkedListTraverse(head);

/*	THIS IS HOW YOU DECLARE/ USE LINKED LISTS  */
	printf("\nLinked list after inserting at first\n");
	head = insertAtFirst(head, 7);
	linkedListTraverse(head);

	printf("\nLinked list after inserting at index 2\n");
	node = insertAtIndex(head, 2, 57);
	linkedListTraverse(head);

	printf("\nLinked list after inserting at last\n");
	end = insertAtEnd(head, 2039);
	linkedListTraverse(head);

	return 0;
}
