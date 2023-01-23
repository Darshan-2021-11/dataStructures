#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node *next;
}
bool peek(Node * top, int index){
	Node * ptr = top;
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
	int n = 1;
	while(ptr != NULL){
		printf("Element %d: %d\n", n, ptr->data);
		ptr = ptr->next;
		n++;
	}
}

int main(){
	// Declaring nodes of the struct
	struct Node *head, *second, *third, *fourth;

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
	linkedListTraverse(head);

	return 0;
}
