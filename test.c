#include "caesar.h"
#include "augustus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("augustus_decrypt(augustus_encrypt(Zac's FAV # is 123! ,1): %s\n", augustus_decrypt(augustus_encrypt("Zac's FAV # is 123!","1"),"1"));


	printf("caesar_encrypt(gusty, 1): %s\n", caesar_encrypt("Hello!",
"13"));
	printf("augustus_encrypt(gusty, 1): %s\n", augustus_encrypt("Hello!",
"13"));  
	printf("augustus_decript(augustus_encrypt(gusty, 1), 1): %s\n",
	augustus_decrypt(augustus_encrypt("gusty", "1"), "1"));
	printf("ceasar_encrypt(gusty, 11): %s\n", caesar_encrypt("gusty", "11"));
	printf("augustus_encrypt(gusty, 11): %s\n",
	augustus_encrypt("gusty", "11"));
	printf("augustus_decript(augustus_encrypt(gusty, 11), 11): %s\n",
	augustus_decrypt(augustus_encrypt("gusty", "11"), "11"));
}
