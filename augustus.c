#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
#include "augustus.h"
#include <math.h>
#include "caesar.h"


char *augustus_encrypt(char *plain, char *key){
	char *keylist=malloc((strlen(plain)+1)*4);
        char *ccipher=malloc((strlen(plain)+1)*4);
	char *acipher=malloc((strlen(plain)+1)*4);
	int keycounter=0;
	ccipher=caesar_encrypt(plain,key);
	for (int i=0; i<strlen(ccipher);i++){
		keylist[i]=key[keycounter]-'0';
		if (keycounter<strlen(key)-1)
			keycounter++;
		else
			keycounter=0;
		acipher[i]=caesar_encrypt_char(ccipher[i],keylist[i]);
	}
	return acipher;
}

char *augustus_decrypt(char *cipher, char *key){
        char *keylist=malloc((strlen(cipher)+1)*4);
        char *cdecrypt=malloc((strlen(cipher)+1)*4);
        char *adecrypt=malloc((strlen(cipher)+1)*4);
        int keycounter=0;
        cdecrypt=caesar_decrypt(cipher,key);
        for (int i=0; i<strlen(cdecrypt);i++){
                keylist[i]=key[keycounter]-'0';
                if (keycounter<strlen(key)-1)
                        keycounter++;
                else
                        keycounter=0;
                adecrypt[i]=caesar_decrypt_char(cdecrypt[i],keylist[i]);
        }
        return adecrypt;
}

