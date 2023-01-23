#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void linkedListTraverse(struct Node *ptr){
	int n = 0;
	struct Node * head = ptr;
	do{
		printf("Element %d: %d\n", n, ptr->data);
		ptr = ptr->next;
		n++;
	}while(ptr != head);
}

// Function that returns (struct node *) datatype output
struct Node * insertAtFirst(struct Node *head, int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->next = head;
	ptr->data = data;

	struct Node * ptrTmp = head;
	do{
		ptrTmp = ptrTmp->next;
	}while(ptrTmp->next != head);
	ptrTmp->next = ptr;
	head = ptr;

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

	do{
		p = p->next;
	}while(p->next != head);

	ptr->data = data;
	ptr->next = head;
	p->next = ptr;

	return ptr;
}

struct Node * deleteAtFirst(struct Node *head){
	struct Node * ptr = head;

	struct Node * ptrTmp = ptr->next;
	while(ptrTmp->next != head){
		ptrTmp = ptrTmp->next;
	}

	ptrTmp->next = head = head->next;
	free(ptr);

	return head;
}

struct Node * deleteAtIndex(struct Node *head, int index){
	struct Node * ptr = head;

	for(int i=0; i < index-1; i++){
		ptr = ptr->next;
	}

	struct Node * ptrTmp = ptr->next;

	ptr->next = ptrTmp->next;
	free(ptrTmp);

	return ptr;
}

struct Node * deleteAtEnd(struct Node *head){
	struct Node * ptr = head;
	struct Node * ptrTmp = ptr->next;

	while(ptrTmp->next != head){
		ptr = ptrTmp;
		ptrTmp = ptrTmp->next;
	}

	free(ptrTmp);
	ptr->next = head;

	return ptr;
}

struct Node * deleteByValue(struct Node * head, int value){
	struct Node * ptr = head;
	struct Node * ptrTmp = ptr->next;
	
	while(ptrTmp->data != value && ptrTmp->next != head){
		ptr = ptrTmp;
		ptrTmp = ptrTmp->next;
	}

	if(ptrTmp->data = value){
		ptr->next = ptrTmp->next;
		free(ptrTmp);

	return ptr;
	}
	else{
		printf("\nNo NODE found with the value of %d.\n", value);
	}
}

int main(){

/*	THIS IS NOT HOW YOU DECLARE/ USE LINKED LIST  */
	// Declaring nodes of the struct
	struct Node *head, *second, *third, *fourth, *node, *end;

	// Allocate memory to the linked list addressses
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));

	head->data = 13;
	head->next = second;

	second->data = 324;
	second->next = third;

	third->data = 230;
	third->next = fourth;

	fourth->data = 27;
	fourth->next = head;

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

	printf("\nLinked list after deleting at first\n");
	head = deleteAtFirst(head);
	linkedListTraverse(head);

	printf("\nLinked list after deleting at index 2\n");
	node = deleteAtIndex(head, 2);
	linkedListTraverse(head);

	printf("\nLinked list after deleting at last\n");
	end = deleteAtEnd(head);
	linkedListTraverse(head);

	printf("\nLinked list after deleting by value(230)\n");
	end = deleteByValue(head, 230);
	linkedListTraverse(head);

	return 0;
}
