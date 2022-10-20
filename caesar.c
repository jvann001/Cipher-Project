/*This it the Caesar Cipher
=======


struct *caesar_encrypt


>>>>>>> dba5d972ff54b8e6f35beede664ae79879f4bb84
*/
#include <stdio.h>
#include <string.h>
#include "strings.h"
#include "caesar.h"
#include <math.h>
int convert_key(char *key){
	int total=0;
	int keysize=strlen(key);
	int power=keysize-1;
	for (int i=0; i<keysize; i++){
		int temp=(key[i]-'0');
		double curs=(temp*pow(10.0,power));
		total=total+curs;
		power--;
	}
	return total;
}
char *caesar_encrypt(char *plain, char *key){
	int intkey = convert_key(key);
	for (int i=0;i<sizeof(plain);i++){		
		char letter=caesar_encrypt_char(plain[i],intkey);
		plain[i]=letter;
	}
}

char caesar_encrypt_char(char plain, int key){
	int lcase;
	if (plain<=90 && plain>=65){
		lcase=64;
	}
	else
		if(plain<=122 && plain>=97){
			lcase=96;
		}
	int letternumber=(plain+key)%26;
	char numberletter=letternumber+lcase;
	return numberletter;
}
