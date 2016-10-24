#include <stdio.h>

int* TAB(){
	int temp;
	return temp;
}

int main(){
	int* ptr;
	ptr = TAB();
	printf("addr of ptr: %p\n", &ptr);
	printf("contents of ptr: %d\n", ptr );

	return 0;
}
