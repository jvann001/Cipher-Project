#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
#include "augustus.h"
#include <math.h>


char *augustus_encrypt(char *plain, char *key){

        char *cipher=malloc((strlen(plain)+1)*4);
        for (int i=0;i<strlen(plain);i++){
                char letter=caesar_encrypt_char(plain[i],intkey);
                cipher[i]=letter;
        }
        return cipher;
}

/*
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
*/


