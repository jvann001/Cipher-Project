#ifndef _MY_STRING_H_
#define _MY_STRING_H_

typedef enum cipher { CAESAR, AUGUSTUS, AES } cipher;
typedef enum string_type { PLAIN, CIPHER } string_type;
typedef struct string string;

typedef struct string {
char *plain;
char *cipher;
int len;
void    (*print)(string *, string_type);
string* (*encrypt)(cipher c, char *s, char *key);
char *  (*decrypt)(cipher c, string *s, char *key);
} string;


//functions...
string *new_plain(char *c, int roundup);
string *new_cipher(char *c, int len, int roundup);
string *encrypt_string(cipher c, char *s, char *key);
char *decrypt_string(cipher c, string *str, char *key);
void setiv_string(char *newiv);
void print_C_string(char *s);

#endif // _MY_STRING_H_
