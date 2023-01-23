#include<stdio.h>

int linearSearch(int arr[], int size, int element){
	// Traverse all elements of the given array
	for(int i=0; i<size; i++){
		if(arr[i] == element){
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int size, int element){
	// Must be sorted array
	int low = 0, mid, high = size-1;
	
	// Keep searching until low <= high
	while (low <= high){
		// the searched elements changes to half the searching radius
		mid = (low + high)/2;
		if(arr[mid] == element) return mid;
		else if(arr[mid] < element) low = mid - 1;
		else high = mid + 1;
	}

	return -1;
}

int main(){
	int nums[] = {34, 134, 325, 519, 2439, 3950, 4041, 4325};
	int sizenums = sizeof(nums)/sizeof(int);
	int num = 2439;

	// nums does NOT need to be sorted for this to work
	printf("%d is found in index number %d by linearSearch.\n", num, linearSearch(nums, sizenums, num));
	// nums need to be SORTED
	printf("%d is found in index number %d by binarySearch.\n", num, binarySearch(nums, sizenums, num));

	return 0;
}
