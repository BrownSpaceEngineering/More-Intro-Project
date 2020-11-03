#include "dictionary.h"

char *lookup_enc[TABLE_SIZE];

char lookup_dec[TABLE_SIZE];

// translation* get_table(){
//     return lookup;
// }

unsigned hashEnc(char* s){
    unsigned hashval;
    for (hashval = 0; *s != 0; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % TABLE_SIZE;
}



unsigned hashDec(char s){
    return (((unsigned) s) - 48) % TABLE_SIZE;
}

char* getDecTable(){
    return lookup_dec;
}

void create_table(){
	lookup_enc[hashDec('A')] = ".-";
    lookup_dec[hashEnc(".-")] = 'A';

	lookup_enc[hashDec('B')] = "-...";
    lookup_dec[hashEnc("-...")] = 'B';

    lookup_enc[hashDec('C')] = "-.-.";
    lookup_dec[hashEnc("-.-.")] = 'C';

	lookup_enc[hashDec('D')] = "-..";
    lookup_dec[hashEnc("-..")] = 'D';
    
    lookup_enc[hashDec('E')] = ".";
    lookup_dec[hashEnc(".")] = 'E';
    
    lookup_enc[hashDec('F')] = "..-.";
    lookup_dec[hashEnc("..-.")] = 'F';
    
    lookup_enc[hashDec('G')] = "--.";
    lookup_dec[hashEnc("--.")] = 'G';
    
    lookup_enc[hashDec('H')] = "....";
    lookup_dec[hashEnc("....")] = 'H';

    lookup_enc[hashDec('I')] = "..";
    lookup_dec[hashEnc("..")] = 'I';

    lookup_enc[hashDec('J')] = ".---";
    lookup_dec[hashEnc(".---")] = 'J';

    lookup_enc[hashDec('K')] = "-.-";
    lookup_dec[hashEnc("-.-")] = 'K';

    lookup_enc[hashDec('L')] = ".-..";
    lookup_dec[hashEnc(".-..")] = 'L';

    lookup_enc[hashDec('M')] = "--";
    lookup_dec[hashEnc("--")] = 'M';

    lookup_enc[hashDec('N')] = "-.";
    lookup_dec[hashEnc("-.")] = 'N';

    lookup_enc[hashDec('O')] = "---";
    lookup_dec[hashEnc("---")] = 'O';

    lookup_enc[hashDec('P')] = ".--.";
    lookup_dec[hashEnc(".--.")] = 'P';

    lookup_enc[hashDec('Q')] = "--.-";
    lookup_dec[hashEnc("--.-")] = 'Q';

    lookup_enc[hashDec('R')] = ".-.";
    lookup_dec[hashEnc(".-.")] = 'R';

    lookup_enc[hashDec('S')] = "...";
    lookup_dec[hashEnc("...")] = 'S';

    lookup_enc[hashDec('T')] = "-";
    lookup_dec[hashEnc("-")] = 'T';

    lookup_enc[hashDec('U')] = "..-";
    lookup_dec[hashEnc("..-")] = 'U';

    lookup_enc[hashDec('V')] = "...-";
    lookup_dec[hashEnc("...-")] = 'V';
    
    lookup_enc[hashDec('W')] = ".--";
    lookup_dec[hashEnc(".--")] = 'W';

    lookup_enc[hashDec('X')] = "-..-";
    lookup_dec[hashEnc("-..-")] = 'X';
    
    lookup_enc[hashDec('Y')] = "-.--";
    lookup_dec[hashEnc("-.--")] = 'Y';
    
    lookup_enc[hashDec('Z')] = "--..";
    lookup_dec[hashEnc("--..")] = 'Z';

    lookup_enc[hashDec('1')] = ".----";
    lookup_dec[hashEnc(".----")] = '1';

	lookup_enc[hashDec('2')] = "..---";
    lookup_dec[hashEnc("..---")] = '2';

    lookup_enc[hashDec('3')] = "...--";
    lookup_dec[hashEnc("...--")] = '3';

	lookup_enc[hashDec('4')] = "....-";
    lookup_dec[hashEnc("....-")] = '4';

    lookup_enc[hashDec('5')] = ".....";
    lookup_dec[hashEnc(".....")] = '5';

	lookup_enc[hashDec('6')] = "-....";
    lookup_dec[hashEnc("-....")] = '6';

    lookup_enc[hashDec('7')] = "--...";
    lookup_dec[hashEnc("--...")] = '7';

	lookup_enc[hashDec('8')] = "---..";
    lookup_dec[hashEnc("---..")] = '8';

    lookup_enc[hashDec('9')] = "----.";
    lookup_dec[hashEnc("----.")] = '9';

	lookup_enc[hashDec('0')] = "-----";
    lookup_dec[hashEnc("-----")] = '0'; 
}

char* getEncoded(char dec){
	if (lookup_enc[hashDec(dec)] != NULL){
        return lookup_enc[hashDec(dec)];
    }
	return "Not Found";
}

char getDecoded(char* enc){
    if(lookup_dec[hashEnc(enc)] != 0){
        return lookup_dec[hashEnc(enc)];
    }
    return '!';
}