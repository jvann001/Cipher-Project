
string_tester: strings.o augustus.o caesar.o aes_cbc.o 
	gcc -o string_tester string_tester.c strings.o augustus.o aes_cbc.o caesar.o -lm
