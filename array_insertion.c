#include<stdio.h>

int indInsert(int array[], int capacity, int size, int elem, int index){
	if(size >= capacity){
		return -1;
	}
	for(int i=size-1; i>index; i--){
		array[i+1] = array[i];
	}
	array[index] = elem;
	return 1;
}

void display(int array[], int size){
	for(int i=0; i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	int arr[100] = {1, 4, 6, 78, 594, 695,4593};
	int size = 7;

	int index = 3, elem = 350;
	indInsert(arr, 100, size, elem, index);
	size++;

	display(arr, size);
}
