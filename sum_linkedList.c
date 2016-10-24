#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

/*
  ------------------------------         ------------------------------
  |              |             |       \ |              |             |
  |     DATA     |     NEXT    |---------|     DATA     |     NEXT    |
  |              |             |       / |              |             |
  ------------------------------         ------------------------------
*/

// Defining a struct recuresevily. Struct inside a struct
typedef struct node{
	uint16_t val;
	struct node *next;
} node_t;

unsigned int length(node_t* head){
	unsigned int counter = 0;
	node_t* current = head;
	while(NULL != current->next){
		current = current->next;
		counter++;
	}
	return counter;
}
// Use const where necessary. Printing shouldn't modify the list
int print_list(const node_t* list){
	if(NULL == list->next){
		puts("Empty list");
		return 1;	
	}
	node_t* current = list;

	while(NULL != current){
		printf("Val: %d\n", current->val);
		current = current->next;
	}
	return 1;
}
/*
Reference Parameters In C
We are bumping into a basic "feature" of the C language that changes to local parameters
are never reflected back in the caller's memory. This is a traditional tricky area of C
programming. We will present the traditional "reference parameter" solution to this
problem, but you may want to consult another C resource for further information. (See
Pointers and Memory (http://cslibrary.stanford.edu/102/) for a detailed explanation of
reference parameters in C and C++.)
We need Push() to be able to change some of the caller's memory — namely the head
variable. The traditional method to allow a function to change its caller's memory is to
pass a pointer to the caller's memory instead of a copy. So in C, to change an 
int in the caller, pass a int*  instead. To change a struct fraction
, pass a struct fraction*  intead. To change an X , pass an X* . So in this case, the value we want to
change is struct node* , so we pass a struct node**
 instead. The two stars (**) are a little scary, but really it's just a straight application of the rule. It just happens
that the value we want to change already has one star (*), so the parameter to change it
has two (**). Or put another way: the type of the head pointer is "pointer to a struct
node." In order to change that pointer, we need to pass a pointer to it, which will be a
"pointer to a pointer to a struct node". Instead of defining WrongPush(struct node* head, int data);
 we define Push(struct node** headRef, int data);
. The first form passes a copy of the head pointer. The second, correct form passes a pointer to the head pointer. The rule
is: to modify caller memory, pass a pointer to that memory. The parameter has the word
"ref" in it as a reminder that this is a "reference" (
struct node**) pointer to the head pointer instead of an ordinary (
struct node*) copy of the head pointer.
*/
void Push(node_t** headRef, int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->val = data;
	newNode->next = *headRef;
	*headRef = newNode;

}


// TODO: check this for correctness, should be node_t** list
void push(node_t* list, unsigned int val){
	node_t* current = list;
	node_t* tail = NULL;
	// node_t* test = (node_t*)malloc(10000000000000);
	// assert(test);
	while(NULL != current->next){
		current = current->next; 
	}
	current->next = (node_t*)malloc(sizeof(node_t));
	tail = current->next;
	current->val = val;
	tail->next = NULL;
}

/*
*	Removing the first item: 
*	int pop()
*/

void populate(node_t* head){
	node_t* current = head;
	unsigned int index = 0;
	for(index = 0; index < 10; index++){
		current->val = index;
		current->next = (node_t*)malloc(sizeof(node_t*));
		current = current->next;
	}
}

node_t* buildLL(){

	node_t* head = NULL;
	node_t* second = NULL;
	node_t* third = NULL;

	head =(node_t*) malloc(sizeof(node_t)); // this will give the wrong size. 8 bits?
	second = (node_t*)malloc(sizeof(node_t));
	third = (node_t*)malloc(sizeof(node_t));
	return head;

}

int main(){
	// Create  a pointer to structs
	printf("size of node_t %lu\n", sizeof(node_t));
	node_t *head = NULL; //pointers of type node_t, only pointer mem being used
	node_t *tail = NULL;
	node_t *null = NULL;
	node_t node = {.val = 88, .next = NULL}; //Actually making memory on the stack for this
	// malloc memory for structs
	head = (node_t*)malloc(sizeof(node_t));
	tail = (node_t*)malloc(sizeof(node_t));
	null = (node_t*)malloc(sizeof(node_t));

	printf("size of node: %lu\n",sizeof(node) );
	printf("size of head: %lu\n",sizeof(head) ); //Head is just a pointer of type node_t
	printf("Contents of null.val: %d null.next: %p\n",null->val, null->next ); //Head is just a pointer of type node_t

	if(NULL == head){
		return 1;
	}

	// head->next = NULL;
	populate(head);
	// push(head, 56);
	// print_list(head);
	printf("Lenght of ll is: %u\n", length(head) ); //Head is just a pointer of type node_t
	free(head);
	free(tail);
	free(null);
}