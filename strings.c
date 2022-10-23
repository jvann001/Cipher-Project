#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
#include "augustus.h"
#include "caesar.h"
#include "aes_cbc.h"


static void print_string(string *str, string_type st) {
        if (st==PLAIN){
                print_C_string(str->plain);
        }
        else{
                print_C_string(str->cipher);
        }
}
                  

string *new_plain(char *c, int roundup){
	int plen= strlen(c);
	roundup= roundup+(plen/16);
	char *plane=malloc((roundup)*16);
	strcpy(plane,c);
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(plane));
	str->cipher=malloc(sizeof(plane));
	strcpy(str->plain, plane);
	str->len=plen;
	str->print = print_string;	// assign print function
	str->encrypt = *encrypt_string;   // assign encrypt function
	str->decrypt = *decrypt_string;   // assign decrypt function
	return str;
}

string *new_cipher(char *c, int len, int roundup){
	string *str = malloc(sizeof(string));
	str->plain=malloc(sizeof(c));
	str->cipher=malloc(sizeof(c));
	strcpy(str->cipher,c);
	str->len=len;
	str->print = print_string;      // assign print function
        str->encrypt = *encrypt_string;   // assign encrypt function
        str->decrypt = *decrypt_string;   // assign decrypt function
}


string *encrypt_string(cipher c, char *s, char *key){
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	str->cipher=malloc(sizeof(s));
	strcpy(str->plain,s);
	str->len=(strlen(s));
	if (c==CAESAR)
		strcpy(str->cipher,caesar_encrypt(s,key));
	else
		if (c==AUGUSTUS)
			strcpy(str->cipher,augustus_encrypt(s,key));
		else
		{
			char *iv;
                        setiv_string(iv);
			struct AES_ctx ctx;
			AES_init_ctx_iv(&ctx, key, iv);
			AES_CBC_encrypt_buffer(&ctx,s,16);
			strcpy(str->cipher,s);
		}
	return str;
}

char *decrypt_string(cipher c, string *str, char *key){
        char *text=malloc(sizeof(str->cipher));
        if (c==CAESAR)
		strcpy(text,caesar_decrypt(str->cipher,key));
	else
		if (c==AUGUSTUS)
			strcpy(text,augustus_decrypt(str->cipher,key));
		else
		{
			char *iv;
			setiv_string(iv);
			struct AES_ctx ctx;
			AES_init_ctx_iv(&ctx, key, iv);
			AES_CBC_decrypt_buffer(&ctx,str->cipher,16);
			strcpy(text,str->cipher);
		}
	return text;
}





void print_C_string(char *s){
	int length=strlen(s);
	int diff=16-(length%16);
	int size=(length+diff);
	printf("len: %d\n",length);
	for (int i=0;i<size;i++){
		if ((i%16)!=15){
			if (i<length)
				printf("%.2x ",s[i]);
			else 
				printf("_0 ");
		}
		if ((i%16)==15){
			printf("  | ");
			for (int j=i-15;j<i;j++){
				if (j<length)
					printf("%c",s[j]);
			}
			printf("\n");
		}
	}
}

//this 
void setiv_string(char *newiv){

}
