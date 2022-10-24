#include "strings.h"
#include "aes_cbc.h"
#include "caesar.h"
#include "augustus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	char in;
	char ciph;
	printf("Would you like to use (D)efault, (C)ommand, or (F)ile processing? (Q)uit: ");
	while (in!='Q'){
		scanf("%c",&in);
                printf("\n");
		if (in=='D'){
			string *s1 = new_plain("gusty", 0);
                        s1 = s1->encrypt(CAESAR, "gusty", "123");
                        s1->print(s1, CIPHER);
                        string *s2 = encrypt_string(AUGUSTUS, "gusty", "123");
                        s2->print(s2, CIPHER);
                        string *s3 = encrypt_string(AES, "gusty", "1234567890ABCDEF");
                        s3->print(s3, CIPHER);
                        char *a1 = decrypt_string(CAESAR, s1, "123");
                        print_C_string(a1);
                        char *a2 = s2->decrypt(AUGUSTUS, s2, "123");
                        print_C_string(a2);
                        char *a3 = s3->decrypt(AES, s3, "1234567890ABCDEF");
                        print_C_string(a3);
                        string *var = new_plain("Gusty is a teacher!", 1); // C string is 19 chars
                        var->print(var, PLAIN);
                        print_C_string("Gusty is a teacher!");
                        string *t1 = new_cipher("znlmr", 5, 0);
                        char *b1 = t1->decrypt(CAESAR, t1, "123");
                        t1->print(t1, PLAIN);
                        print_C_string(b1);
                        string *t2 = new_cipher("apont", 5, 0);
                        char *b2 = t2->decrypt(AUGUSTUS, t2, "123");
                        t2->print(t2, PLAIN);
                        print_C_string(b2);
                        char buf[] = {0x41, 0x39, 0x71, 0x5d, 0x8f, 0x35, 0x95, 0x51,
                        0x15, 0xfb, 0x7b, 0x5c, 0x9f, 0x1b, 0x59, 0x63, 0};
                        string *t3 = new_cipher(buf, 16, 1);
                        char *b3 = t3->decrypt(AES, t3, "1234567890ABCDEF");
                        t2->print(t2, PLAIN);
                        print_C_string(b2);
		}
		if(in=='C'){
	/*	if(in='F'){
			FILE *fin = fopen("ciphers.txt", "r");
			char cipherLine;
			int key;
			char targetString;
			
			int numberOfLines, count = 0;
*/

			while(ciph!='Q'){
				printf("Default Keys:\nCaesar: 1\nAugustus: 12\nAES: 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6\n     0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c\n\nEnter command - (Q)uit, (C)aesar, A(U)gustus, (A)es: ");
				scanf("%c",&ciph);
				printf("\n");
				char in_s[120];
				cipher cenum;
				if (ciph=='C'){
					cenum=CAESAR;
					printf("\nEnter string: \n");
					fgets(in_s, 120, stdin);
					in_s[strcspn(in_s, "\0")] = '\0';  // replace \n with \0
					if (strlen(in_s) == 0) {
					printf("You must enter a string!");
					}
					char key[64];
					printf("Enter key (Enter for default): ");
					fgets(key,64,stdin);
					if (key[0]=='\n'){
						strcpy(key,"0");
					}
					string *ms = new_plain(in_s, cenum);
					printf("\nPlain text string:\n");
					ms->print(ms, PLAIN);
					string *b = ms->encrypt(cenum, in_s, key);
					printf("\nCipher text string:\n");
					b->print(b, CIPHER);
					char *s = b->decrypt(cenum, b, key);
					printf("\nDecrypted input:\n");
					printf("%s\n", s);
					print_C_string(s);
					b->print(b, PLAIN);
					}
				else
					if (ciph=='U'){
						cenum=AUGUSTUS;
						printf("Enter string:\n ");
						fgets(in_s, 120, stdin);
						in_s[strcspn(in_s, "\0")] = '\0';  // replace \n with \0
						if (strlen(in_s) == 0) {
						printf("You must enter a string!");
						}
						char key[64];
						printf("Enter key (Enter for default): ");
						fgets(key,20,stdin);
						if (key[0]=='\n'){
							strcpy(key,"12");
						}
						string *ms = new_plain(in_s, cenum);
						printf("\nPlain text string:\n");
						ms->print(ms, PLAIN);
						string *b = ms->encrypt(cenum, in_s, key);
						printf("\nCipher text string:\n");
						b->print(b, CIPHER);
						char *s = b->decrypt(cenum, b, key);;
						printf("\nDecrypted input:\n");
						printf("%s\n", s);
						print_C_string(s);
						b->print(b, PLAIN);
                                        }
					else
						if (ciph=='A'){
							cenum=AES;
							printf("\nEnter string: ");
							fgets(in_s, 120, stdin);
							in_s[strcspn(in_s, "\0")] = '\0';  // replace \n with \0
							if (strlen(in_s) == 0) {
							printf("You must enter a string!");
							}
							char key[64];
							printf("Enter key (Enter for default): ");
							fgets(key,20,stdin);
							if (key[0]=='\n'){
								strcpy(key,"2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c");
							}
							string *ms = new_plain(in_s, cenum);
							printf("\nPlain text string:\n");
							ms->print(ms, PLAIN);
							string *b = ms->encrypt(cenum, in_s, key);
							printf("\nCipher text string:\n");
							b->print(b, CIPHER);
							char *s = b->decrypt(cenum, b, key);
							printf("\nDecrypted input:\n");
							printf("%s\n", s);
							print_C_string(s);
							b->print(b, PLAIN);
							}

			}
		}
	}
}
