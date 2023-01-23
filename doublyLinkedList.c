#include<stdio.h>
#include<stdlib.h>

struct DoubleNode{
	int data;
	struct DoubleNode * next;
	struct DoubleNode * prev;
};

void traverseDoublyLinkedList(struct DoubleNode * head){
	int index = 0, flag = 1;
	struct DoubleNode * ptr = head;

	do{
		printf("Element %d: %d\n", index, ptr->data);
		index++;
		if(ptr->next != NULL){
			ptr = ptr->next;
			flag = 1;
		} else { flag = 0; }
	}while(flag);
	printf("END\n");
}

struct DoubleNode * createDoublyLinkedList(int value){
	struct DoubleNode * head = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
	head->data = value;
	head->prev = NULL;
	head->next = NULL;

	return head;
}

struct DoubleNode * insertAtFirst(struct DoubleNode * head, int value){
	struct DoubleNode * ptr = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
	ptr->data = value;
	ptr->prev = NULL;
	ptr->next = head;
	head->prev = ptr;

	return ptr;
}

struct DoubleNode * insertAtIndex(struct DoubleNode * head, int value, int index){
	struct DoubleNode * ptr = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
	struct DoubleNode * ptrTmp = head;

	while(index > 1){
		ptrTmp = ptrTmp->next;
		index--;
	}

	ptr->data = value;
	ptr->next = ptrTmp->next;
	ptr->prev = ptrTmp;
	ptrTmp->next = ptr;

	return ptr;
}

struct DoubleNode * insertAtEnd(struct DoubleNode * head, int value){
	struct DoubleNode * ptr = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
	struct DoubleNode * ptrTmp = head;

	while(ptrTmp->next != NULL){
		ptrTmp = ptrTmp->next;
	}

	ptr->data = value;
	ptr->next = NULL;
	ptr->prev = ptrTmp;
	ptrTmp->next = ptr;

	return ptr;
}

struct DoubleNode * deleteAtFirst(struct DoubleNode * head){
	head = head->next;
	free(head->prev);
	head->prev = NULL;

	return head;
}

struct DoubleNode * deleteAtIndex(struct DoubleNode * head, int index){
	struct DoubleNode * ptr = head;

	while(index > 1){
		ptr = ptr->next;
		index--;
	}

	struct DoubleNode * ptrTmp = ptr->next;
	ptr->next = ptrTmp->next;
	(ptrTmp->next)->prev = ptr;

	free(ptrTmp);

	return ptr->next;
}

struct DoubleNode * deleteAtEnd(struct DoubleNode * head){
	struct DoubleNode * ptr = head;

	while(ptr->next != NULL) ptr = ptr->next;
	ptr = ptr->prev;

	free(ptr->next);
	ptr->next = NULL;

	return ptr;
}

int main(){
	printf("Creating doubly linked list:\n");
	struct DoubleNode * head = createDoublyLinkedList(46);
	traverseDoublyLinkedList(head);

	printf("Inserting at head:\n");
	head = insertAtFirst(head, 89);
	traverseDoublyLinkedList(head);

	printf("Inserting at index 1:\n");
	insertAtIndex(head, 47, 1);
	traverseDoublyLinkedList(head);

	printf("Inserting at end:\n");
	insertAtEnd(head, 24);
	traverseDoublyLinkedList(head);

	printf("Deleting at head:\n");
	head = deleteAtFirst(head);
	traverseDoublyLinkedList(head);

	printf("Deleting at index 1:\n");
	deleteAtIndex(head, 1);
	traverseDoublyLinkedList(head);

	printf("Deleting at the end:\n");
	deleteAtEnd(head);
	traverseDoublyLinkedList(head);

	return 0;
}
