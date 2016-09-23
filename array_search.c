#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// TODO: detect duplicates
void print_array(unsigned int array[]){
	unsigned int index = 0;
	for(index = 0; index < MAX; index++){
		printf("array[%d] = %d\n", index, array[index]);
	}
}

void pop_array(unsigned int array[]){
	unsigned int index = 0;
	for(index = 0; index < MAX; index++){
		array[index] = random();
	}
}

unsigned int search_array(int num, unsigned int array[]){
	unsigned int index = 0;
	for(index = 0; index < MAX; index++){
		if(num == array[index]){
			puts("found value");
			return 1;
		}
	}
	puts("Value not found");
	return -1;
}

int main(int argc, char* []){
	unsigned int array[MAX] = {0};
	pop_array(array);
	print_array(array);
	search_array(array[54], array);
	return 0;
}
