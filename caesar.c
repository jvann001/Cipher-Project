<<<<<<< HEAD
char ShuffCapL[]  = {'A','B','C','D','E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }
/*This it the Caesar Cipher
=======


struct *caesar_encrypt


>>>>>>> dba5d972ff54b8e6f35beede664ae79879f4bb84
*/






/*SKELETON FOR SORTING LOOP.
 * 'target' is the String we are shifting the values
 * 'key' is the int value we are using to sort the value*/

void caesar_encrypt(char [] target, int key) {
	for(int i =0; i < target.length; i++){
		int location = (i[i] + key ) % 26;
		i[i] = ShuffCapL[location];
		i++;
	}
}
void caesar_decrypt(char [] target, int key) {
	for( i = 0; i < target.length; i++) {
		int position = (i[i] - key) % 26;
		i[i] = ShuffCapL[location];
		i++;
	}
}


