#include <stdio.h>
#include <ctype.h>

#define SIZE 10
int hash_function(char* key){
	int hash = toupper(key[0] - 'A');
	return hash % SIZE;
}

int main(){
	char key[4] = {"H"};
	// hash_function(key);
	printf("hash_function: %d\n",hash_function(key) );
}