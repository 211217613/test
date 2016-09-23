#include <stdio.h>
//Given three numbers, return the second largest

int find_second(int a, int b, int c){
	if (a > b && b > c)
		return b;
	else if (a > c && c > b)
		return c;
	else 
		return -1;
}

int main(void){
	//Edge cases: all the same numbers 1,1,2
	int a, b, c, second1, second2, second3;
	scanf("%d %d %d", &a, &b, &c );

	second1 = find_second(a, b, c);
	second2 = find_second(b, c, a);
	second3 = find_second(c, a, b);

	if (second1 != -1)
		printf("%d\n", second1);
	if(second2 != -1 )
		printf("%d\n",second2);
	if(second3 != -1)
		printf("%d\n", second3);

	return 0;
}
