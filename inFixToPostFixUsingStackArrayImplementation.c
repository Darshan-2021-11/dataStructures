#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

bool isAlpha(char character){
	if((character>=97 && character<=122) || (character>=65 && character<=90)) return true;
	else return false;
}

bool isNumeric(char character){
	if(character>=48 && character<=57) return true;
	else return false;
}

bool isOperator(char c){
	if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') return true;
	else return false;
}

int OPriority(int character){
	switch(character){
		// priorities like this will help us pop operators from stack
		//
		// by conditions, we will never pop left and right parenthesis to
		// stack, however with their help, we will pop other operators to
		// output post-fix expression
		case '(':
		case '{':
		case '[':
			return 0;
			break;
		case ')':
		case '}':
		case ']':
			return 1;
			break;
		case'^':
			return 4;
			break;
		case '/':
		case '*':
			return 3;
			break;
		case '+':
		case '-':
			return 2;
			break;

		// this will never be reached
		default: return INT_MAX;
	}
}

// To give a nick name to struct with using `typedef` keyword, write the whole
// structure without a name, and at the very end, give a nick name to be used
// before semicolon(;)
typedef struct stackArr{
	int top;
	unsigned int size;
	char * arr;
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
	stack->arr = (char *)malloc(sizeof(char) * size);

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

bool push(stackArr * stack, char value){
	if(isFull(stack)){
		printf("\nSTACK OVERFLOW! Cannot push %c to stack.\n", value);
		return false;
	} else {
		stack->top++;
		stack->arr[stack->top] = value;
		printf("\nSuccessfully pushed %c to index %d of stack!\n", value, stack->top);
		return true;
	}
}

int pop(stackArr * stack){
	if(isEmpty(stack)){
		printf("\nSTACK UNDERFLOW! Cannot pop element.\n");
		return -1;
	} else {
		char value = stack->arr[stack->top];
		printf("\nElement %d: %c (POP)\n", stack->top, value);
		stack->top--;
		return value;
	}
}

bool isBalancedExpr(char expr[]){
	int count = 0, index = 0;
	stackArr * s = createStack(SIZE);

	char tmpChr = expr[index];
	while(tmpChr != '\0'){
		if(tmpChr == '(' || tmpChr == '{' || tmpChr == '['){
			push(s, tmpChr);
		}
		// the next condition will not be triggered until its counter part
		// bracket would be in the stack already, and if this creates error, it
		// means the expression is not balanced as the top of the stack is
		// empty.
		else if(tmpChr == ')' || tmpChr == '}' || tmpChr == ']'){
			if(isEmpty(s)){
				return false;
			} else {
				char compChr = s->arr[s->top];
				if(
						(tmpChr == ')' && compChr == '(') ||
						(tmpChr == '}' && compChr == '{') ||
						(tmpChr == ']' && compChr == '[')
				  ){
					pop(s);
				} else {
					return false;
				}
			}
		}

		index++; tmpChr = expr[index];
	}
	free(s->arr);
	free(s);
	return true;
}

bool inToPost(char out[], char in[]){
	if(!isBalancedExpr(in)) return false;

	stackArr * s = createStack(SIZE);
	int outIndex, inIndex;
	outIndex = inIndex = 0;

	push(s, '(');

	char tmpChr = in[inIndex];
	while(tmpChr != '\0'){

		if(isAlpha(tmpChr) || isNumeric(tmpChr) || tmpChr == ' '){

			out[outIndex] = tmpChr;
			outIndex++;

		} else if(isOperator(tmpChr)){

			// check if the character is left bracket, if it is, we will
			// pop all the elements till we encounter left parenthesis, which
			// has priority just less than that of right, and at last instead
			// of pushing it to the output, we will remove encountered left
			// bracket from stack

			char stackTop = s->arr[s->top];
			int chrPriority = OPriority(tmpChr);

			while((chrPriority <= OPriority(stackTop)) && tmpChr != '(' && tmpChr != '{' && tmpChr != '['){
				printf("\nWHILE\n");
				out[outIndex] = stackTop; outIndex++; pop(s); stackTop = s->arr[s->top];
				out[outIndex] = '\0';
			}
			if(chrPriority != 1){
				push(s, tmpChr);
			} else {
				// this condition will only occur if left parenthesis is 
				// encountered
				//
				// because of the way the priorities is set up, if it is a
				// right parenthesis, it would not push that to stack, and
				// other operators would already have been flushed out of stack
				// from the above while loop to the post-fix expression, only 
				// left parenthesis has less priority than right parenthesis,
				// resulting in its popping.
				printf("\nELSE\n");
				pop(s);
			}
		} else { printf("\nThis '%c' is not a valid symbol!\n", tmpChr);
			return false;
		}

		inIndex++;
		tmpChr = in[inIndex];
		printf("output: \"%s\"\n", out);
	}
	// if all the input characters has been encountered, all there is left to
	// put into the output is stack elements that are not left parenthesis
	while(!isEmpty(s)){
		if(s->arr[s->top] != '(') {
			out[outIndex] = pop(s);
			outIndex++;
			out[outIndex] = '\0';
			printf("output: \"%s\" s->top:%d\n", out, s->top);
		}
		else pop(s);
	}
	
	free(s->arr);
	free(s);
	return true;
}

int main(){
	char inExpr[SIZE], outExpr[SIZE];

	printf("Enter an expression in in-fix to convert to post-fix here: ");
	gets(inExpr);
	printf("\nGiven expression is: \"%s\"\n", inExpr);

	bool isComplete = inToPost(outExpr, inExpr);
	if(isComplete) printf("\nOutput expression is: \"%s\"\n", outExpr);
	else printf("\nPlease give a balanced input expression and TRY AGAIN!\n");

	return 0;
}
