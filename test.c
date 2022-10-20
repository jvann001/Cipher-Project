#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>

int main(){	
	printf("hello world");
	char key[] = "33402";
	int num = convert_key(key);
	printf("\n here is the num in int: %d \n", num);

return 0;
}
