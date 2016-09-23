#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


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

void print_list(node_t* list){
	node_t* current = list;
	while(NULL != current){
		printf("Val: %d\n", current->val);
		current = current->next;
	}
}

void push(node_t* list, unsigned int val){
	node_t* current = list;
	node_t* tail = NULL;
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



int main(){
	// Create  a pointer to structs
	printf("size of node_t %lu\n", sizeof(node_t));
	node_t *head = NULL; //pointers of type node_t, only pointer mem being used
	node_t *tail = NULL;
	node_t node = {.val = 88, .next = NULL}; //Actually making memory on the stack for this
	// malloc memory for structs
	head = (node_t*)malloc(sizeof(node_t));
	tail = (node_t*)malloc(sizeof(node_t));

	printf("size of node_t: %lu\n",sizeof(node) );
	printf("size of node_t*: %lu\n",sizeof(head) );

	if(NULL == head){
		return 1;
	}
	head->val = 1;
	(*head).val = 1;

	head->next = NULL;
	print_list(head);
	push(head, 56);
	print_list(head);
}