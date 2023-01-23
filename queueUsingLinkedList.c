#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node *next;
};

bool peek(struct Node * top, int index){
	struct Node * ptr = top;
	for(int i=index; i>0; i--){
		if(ptr != NULL)
			ptr = ptr->next;
		else{
			printf("\nNot that much elements in stack!\n");
			return false;
		}
	}
	printf("\nThe value at index %d is %d\n", index, ptr->data);
	return true;
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
//
//
// Instead of returning the pointer and reassigning the Node ptr of the head to
// the returned value, we can also use Node ptr ptr and change the value of the
// head pointer to new head pointer
// as done in the stackUsingLinkedList.c implementation in the data structure.


// insertAtIndex function from linked list becomes enqueue
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
}// insertAtIndex function from linked list becomes enqueue
struct Node * enqueue(struct Node *head, int data){
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

// deleteAtFirst from linked list becomes dequeue
struct Node * deleteAtFirst(struct Node *head){
	struct Node * ptr = head;

	head = head->next;
	free(ptr);

	return head;
}
// deleteAtFirst from linked list becomes dequeue
struct Node * dequeue(struct Node *head){
	struct Node * ptr = head;

	head = head->next;
	free(ptr);

	return head;
}

//	These functions becomes obsolete in queue implementation of linked list.
//	
//	struct Node * insertAtFirst(struct Node *head, int data){
//		struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
//		ptr->next = head;
//		ptr->data = data;
//	
//		return ptr;
//	}
//	
//	struct Node * insertAtIndex(struct Node *head, int index, int data){
//		struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
//		struct Node * p = head;
//	
//		for(int i=1; i<index; i++){
//			p = p->next;
//		}
//		ptr->data = data;
//		ptr->next = p->next;
//		p->next = ptr;
//	
//		return ptr;
//	}
//
//	struct Node * deleteAtIndex(struct Node *head, int index){
//		struct Node * ptr = head;
//	
//		for(int i=0; i < index-1; i++){
//			ptr = ptr->next;
//		}
//	
//		struct Node * ptrTmp = ptr->next;
//	
//		ptr->next = ptrTmp->next;
//		free(ptrTmp);
//	
//		return ptr;
//	}
//	
//	struct Node * deleteAtEnd(struct Node *head){
//		struct Node * ptr = head;
//		struct Node * ptrTmp = ptr->next;
//	
//		while(ptrTmp->next != NULL){
//			ptr = ptrTmp;
//			ptrTmp = ptrTmp->next;
//		}
//	
//		free(ptrTmp);
//		ptr->next = NULL;
//	
//		return ptr;
//	}
//	
//	struct Node * deleteByValue(struct Node * head, int value){
//		struct Node * ptr = head;
//		struct Node * ptrTmp = ptr->next;
//		
//		while(ptrTmp->data != value && ptrTmp->next != NULL){
//			ptr = ptrTmp;
//			ptrTmp = ptrTmp->next;
//		}
//	
//		if(ptrTmp->data = value){
//			ptr->next = ptrTmp->next;
//			free(ptrTmp);
//	
//		return ptr;
//		}
//		else{
//			printf("\nNo NODE found with the value of %d.\n", value);
//		}
//	}

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
	fourth->next = NULL;

	// Running linked list traverse function
	printf("\nLinked list before enqueue\n");
	linkedListTraverse(head);

	printf("\nLinked list after enqueue\n");
	end = enqueue(head, 2039);
	linkedListTraverse(head);

	printf("\nLinked list after dequeue\n");
	head = dequeue(head);
	linkedListTraverse(head);

	return 0;
}
