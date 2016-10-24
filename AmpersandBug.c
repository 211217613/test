#include <stdio.h>

int* TAB(){
	int temp;
	return (&temp);
}

int main(){
	int* ptr;
	ptr = TAB();

	return 0;
}
