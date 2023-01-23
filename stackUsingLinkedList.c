#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node * next;
}Node;

Node * createStack(int value){
	Node * top = (Node *)malloc(sizeof(Node));
	top->data = value;
	top->next = NULL;
	printf("\nCreation of stack SUCCESSFUL!\n");

	return top;
}

bool isEmpty(Node * top){
	if(top == NULL) return true;
	else return false;
}

// To change the top of the stack(i.e. Node ptr to top), we take Node ptr ptr
// to edit the Node ptr to push or pop elements in stack.
bool push(Node ** topPtr, int value){
	Node * node = (Node *)malloc(sizeof(Node));
	if(node == NULL){
		printf("\nSTACK OVERFLOW! Cannot store value %d.\n", value);
		return false;
	} else {
		node->data = value;
		node->next = *topPtr;

		*topPtr = node;
		return true;
	}
}

bool pop(Node ** topPtr){
	if(isEmpty(*topPtr)){
		printf("\nSTACK UNDERFLOW! Cannot pop elements.\n");
		return false;
	} else {
		Node * temp = *topPtr;
		*topPtr = (*topPtr)->next;
		free(temp);
		return true;
	}
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
}

bool displayStack(Node * top){
	if(top != NULL){
		Node * ptr = top;
		int index = 0;
		printf("\nDisplaying elements in the stack :\n");
		while(ptr != NULL){
			printf("Element %d: %d\n", index, ptr->data);
			ptr = ptr->next;
			index++;
		}
		printf("\n");
		return true;
	} else {
		printf("\nStack is empty\n");
		return false;
	}
}

int main(){
	Node * top = createStack(123);
	push(&top, 346);
	displayStack(top);
	peek(top, 1);
	displayStack(top);
	pop(&top);
	displayStack(top);
	pop(&top);
	displayStack(top);
	pop(&top);

	return 0;
}
