#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){	
	printf("hello %s\n", "world");
	printf("ceasar_encrypt(gusty, 1): %s\n", caesar_encrypt("gusty", "1"));
	printf("ceasar_encrypt(gusty, 27): %s\n", caesar_encrypt("gusty", "27"));
	printf("ceasar_encrypt(gusty, 3): %s\n", caesar_encrypt("gusty", "3"));
	printf("ceasar_encrypt(gusty, 29): %s\n", caesar_encrypt("gusty", "29"));
	printf("ceasar_encrypt(gusty, 0): %s\n", caesar_encrypt("gusty", "0"));
	printf("ceasar_encrypt(gusty, 26): %s\n", caesar_encrypt("gusty", "26"));
	printf("ceasar_decrypt(ceasar_encrypt(gusty, 1)): %s\n",
	caesar_decrypt(caesar_encrypt("gusty", "1"), "1"));
	printf("ceasar_decrypt(ceasar_encrypt(gusty, 27)): %s\n",
	caesar_decrypt(caesar_encrypt("gusty", "27"), "27"));
	printf("ceasar_decrypt(ceasar_encrypt(gusty, 3)): %s\n",
	caesar_decrypt(caesar_encrypt("gusty", "3"), "3"));
	printf("ceasar_decrypt(ceasar_encrypt(gusty, 29)): %s\n",
	caesar_decrypt(caesar_encrypt("gusty", "29"), "29"));


}
