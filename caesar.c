/*This it the Caesar Cipher
=======
*/
#include <stdlib.h>
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
	char *cipher=malloc((strlen(plain)+1)*4);
	for (int i=0;i<strlen(plain);i++){ 
		char letter=caesar_encrypt_char(plain[i],intkey);
		cipher[i]=letter;
	}
	return cipher;
}

char caesar_encrypt_char(char plain, int key){
	int lcase;
	if (plain<=90 && plain>=65){
		lcase=65;
	}
	else
		if(plain<=122 && plain>=97){
			lcase=97;
		}
	int letmin=plain-lcase;
	int letternumber=(letmin+key)%26;
	char numberletter=letternumber+lcase;
	return numberletter;
}

char *caesar_decrypt(char *cipher, char *key){
	    int intkey = convert_key(key);
        char *orig=malloc((strlen(cipher)+1)*4);
        for (int i=0;i<strlen(cipher);i++){
                char letter=caesar_decrypt_char(cipher[i],intkey);
                orig[i]=letter;
        }
        return orig;
}

char caesar_decrypt_char(char plain, int key){
        int lcase;
        if (plain<=90 && plain>=65){
                lcase=65;
        }
        else
                if(plain<=122 && plain>=97){
                        lcase=97;
                }
        int letmin=plain-lcase;
        int letternumber=(letmin-key+260)%26;
        char numberletter=letternumber+lcase;
        return numberletter;
}
