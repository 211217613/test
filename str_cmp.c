#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[]){
	int ret_val = 0;
	//printf("argv[0] = %s \t argv[1] = %s \n", argv[0], argv[1]);
	ret_val = strcmp("test", argv[1]);

	printf("ret_val %d\n", ret_val);

	return 0;

	
}
