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

int print_list(node_t* list){
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
	print_list(null);
	// push(head, 56);
	// print_list(head);
}