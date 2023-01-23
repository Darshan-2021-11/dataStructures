#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
// This program will fail for large amounts of circulations of front and rear
// value of queue until INT_MAX value is reached.
// But that's practically not possible since nobody is gonna use this code
// anyways xD
//
// Assume the front to be the one increasing when any element is added and rear
// be the one following the front while dequeuing.
//
// Also note that if we ever had to implement the modulo operator for the
// implementation for whatever reason, keep in mind the fact that front will
// never cross rear;
// that means if rear value is found out to be more than front, it must be the
// case that 
// front = (rear + {total number of elements in the queue} - 1)% SIZE
//		where SIZE is the preprocessor directive of the program
//
// because front and rear are inclusive elements, so rear was counted twice and
// hence decreased one from the total no. of elements...

struct Queue{
	int f;	//front
	int r;	//rear
	int size;
	int * arr;
};

bool isEmpty(struct Queue * queue){
	if(queue->r == queue->f + 1) return true;
	else return false;
}

bool isFull(struct Queue * queue){
	if(queue->f - queue->r + 1 == SIZE) return true;
	else return false;
}

struct Queue * createQueue(int size){
	struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->size = size;
	queue->f = queue->r = -1;
	queue->arr = (int *)malloc(sizeof(int) * size);

	return queue;
}

bool enqueue(struct Queue * queue, int value){
	if(isFull(queue)){
		printf("\nSTACK OVERFLOW! Cannot add %d to queue.\n", value);
		return false;
	} else {
		if(queue->r == -1){
			queue->r++;
		}
		queue->f++;
		queue->arr[queue->f%SIZE] = value;
		printf("\nSuccessfully added %d to index %d of queue.\n", value, queue->f - queue->r);
		return true;
	}
}

bool dequeue(struct Queue * queue){
	if(isEmpty(queue)){
		printf("\nSTACK UNDERFLOW! Cannot dequeue item.\n");
		return false;
	} else {
		printf("\nSuccessfully removed %d from queue.\n", queue->arr[queue->r%SIZE]);
		queue->r++;
		return true;
	}
}

bool peek(struct Queue * queue, int index){
		if(index > (queue->r - queue->f)){
			printf("\nIndex out of bound! Try lowering the index\n");
			return false;
	} else {
		printf("\nElement %d: %d\n", index, queue->arr[(queue->r + index)%SIZE]);
		return true;
	}
}

void display(struct Queue * queue){
	printf("\nDISPLAYING QUEUE:\n");
	int r = queue->r, f = queue->f;
	for(int i = r; i <= f; i++){
		printf("Element %d: %d\n", i-r, queue->arr[i%SIZE]);
	}
	printf("\n");
}

int main(){

	struct Queue * q = createQueue(SIZE);

	bool flag = true;
	int switch_choice, value;
	while(flag){
		printf("\n1.Enqueue\t2.Dequeue\t3.Peek\t4.Display\t5.Exit\nEnter choice: ");
		scanf("%d", &switch_choice);

		switch(switch_choice){
			case 1:
				printf("Enter a value to enqueue: ");
				scanf("%d", &value);
				enqueue(q, value);
				break;
			case 2:
				dequeue(q);
				break;
			case 3:
				printf("Enter index to peek: ");
				scanf("%d", &value);
				peek(q, value);
				break;
			case 4:
				display(q);
				break;
			case 5:
				flag = false;
				break;

			default:
				printf("\nINVALID OPTION. Please enter a valid option.\n");
		}
	}

	return 0;
}
