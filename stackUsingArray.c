#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// To give a nick name to struct with using `typedef` keyword, write the whole
// structure without a name, and at the very end, give a nick name to be used
// before semicolon(;)
typedef struct stackArr{
	int top;
	unsigned int size;
	int * arr;
}stackArr;

// We get to know that structure in C, can be passed in two ways, pass by value
// or pass by reference... Just like any other primitive datatype, even though
// it is not...
//
//
// Why we are not using stack instead of using stack pointer as a return value
// of this function creating stack is that we need to
// change the stack itself many times through functions,
// but if return stack, we need to pass the pointer to many functions, instead
// we use the pointer as a return type any way instead of using pass by value.
//
// Saves so much overhead of referencing and dereferencing pointers.
stackArr * createStack(int size){
	stackArr * stack = (stackArr *)malloc(sizeof(stackArr));
	stack->top = -1;
	stack->size = size;
	stack->arr = (int *)malloc(sizeof(int) * size);

	printf("\nCreation of a stack with size: %d, was successful!\n", size);

	return stack;
}

bool isFull(stackArr * stack){
	if(stack->top == stack->size-1) return true;
	else return false;
}

bool isEmpty(stackArr * stack){
	if(stack->top == -1) return true;
	else return false;
}

bool push(stackArr * stack, int value){
	if(isFull(stack)){
		printf("\nSTACK OVERFLOW! Cannot push %d to stack.\n", value);
		return false;
	} else {
		stack->top++;
		stack->arr[stack->top] = value;
		printf("\nSuccessfully pushed %d to index %d of stack!\n", value, stack->top);
		return true;
	}
}

bool pop(stackArr * stack){
	if(isEmpty(stack)){
		printf("\nSTACK UNDERFLOW! Cannot pop element.\n");
		return false;
	} else {
		printf("\nElement %d: %d (POP)\n", stack->top, stack->arr[stack->top]);
		stack->top--;
		return true;
	}
}

bool peek(stackArr * stack, unsigned int index){
	int top = stack->top;
	int stackIndex = top - index;
	if(stackIndex < 0 && stackIndex > top){
		printf("\nThe given index, %d, is not available in the stack.\n", index);
		return false;
	} else {
		printf("\nElement %d: %d (PEEK)\n", index, stack->arr[index]);
		return true;
	}
}

bool displayStackArr(stackArr * stack){
	int top = stack->top;
	if(top == -1){
		printf("\nSTACK UNDERFLOW! Cannot display stack elements.\n");
		return false;
	} else {
		printf("\nDISPLAYING the elements on the stack:\n");
		for(int i = top; i > -1; i--){
			printf("Element %d: %d\n", i, stack->arr[i]);
		}
		printf("\n");
		return true;
	}
}

void stackOperations(stackArr * s1){
	int switch_choice, temp;
	bool flag = true;

	while(flag){
		printf("\nEnter choice:\n1.Push\t2.Pop\t3.Peek\t4.DisplayStack\t5.Exit\n");
		scanf("%d", &switch_choice);

		switch(switch_choice){
			case 1:
				printf("Enter a number to push to stack: ");
				scanf("%d", &temp);
				push(s1, temp);
				break;
			case 2:
				pop(s1);
				break;
			case 3:
				printf("Enter a index to peek: ");
				scanf("%d", &temp);
				peek(s1, temp);
				break;
			case 4:
				displayStackArr(s1);
				break;
			case 5:
				flag = false;
				break;

			default:
				printf("\nEnter a valid choice to perform...\n");
		}
	}
}

int main(){

	int size;
	printf("Enter the size of the stack to make: ");
	scanf("%d", &size);
	stackArr * s1 = createStack(size);
	stackOperations(s1);

	free(s1->arr);
	free(s1);
	printf("\nFreed the memory used for the stack.\n");
	printf("\nThanks for using our stack implementation using array.\n");

	return 0;
}
