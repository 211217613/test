#include <stdio.h>

#define MAX 100
void ArrayTest(){
	int scores [MAX] = {0};
	for (int index = 0; index < MAX; index++){
		scores[index] = index;
	}
	printf("The addr of scores is %p\n", scores);
	printf("And the value at that addr is %d\n", *scores);
}

int main(){
	int *p, *q;
	p = q; //Both pointers point to the same thing. Does not make a copy in memory
	printf("addr of p is %x and q is %x\n", &p, &q);
	ArrayTest();
}
