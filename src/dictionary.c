#include "dictionary.h"

/**
 * Dictionary lookup table to translate between alphanumeric characters and their morse code
 * representations
 * **/

/**
 * Why're we even working with hashes? Well, here's the idea:
 *
 * Now, We're trying to map each alphabet to its more code representation.
 *
 * But, when you have a lot of things to map, it becomes very inefficient to store the actual strings
 * representing, in this case, the alphabets and their morse counterparts.
 *
 * It would be more efficient to map a numeric representation of each alphabet to a numeric
 * representation of each morse character.
 *
 * We find these numeric codes by hashing the alphabets or morse.
 *
 * The interesting thing is that if these hashes are always non-negative integers, then we can
 * essentially make our hashes out of lists, where the hash of a morse character is stored in the list
 * at the index corresponding to the hash of the alphabet.
 *
 */

/**
 * Also, this solution is super inefficient space wise, mostly done as a proof of concept of very
 * simple hash map in C
 *
 * A simple 2d array with no hash function would work perfectly fine with such a small set of items
 */

// Store encoded (morse-equivalent) alphanumeric strings
/**
 * Notice that this is a list of chars. Recall why it's ok to have a hash made out of a list as long
 * as our hashes are non negative integers.
 */
char *lookup_enc[TABLE_SIZE];

// Store decoded alphanumeric character (treated as strings) (plain text)
char *lookup_dec[TABLE_SIZE];

// Hash function to get index of plain character in table using encoded character
unsigned hashEnc(char *s)
{
    unsigned hashval;
    // Reminder: 0 is the same as NULL in C.
    for (hashval = 0; *s != 0; s++)
    {
        // wait a second, did we just add a char to a number? Well, remember that in C, chars are
        // inherently represented as numbers. Different chars are different numbers. Think unicode!
        hashval = *s + 31 * hashval;
    }
    return hashval % TABLE_SIZE;
}

// Hash function to get index of encoded character in table using plain character
unsigned hashDec(char s)
{
    // what you're seeing here is called casting. Normally, chars can store values b/w -128 and 127
    // but unsigned chars can store from 0 to 255.
    return (((unsigned)s) - 48) % TABLE_SIZE;
}

// Return pointer to table
char **getDecTable()
{
    return lookup_dec;
}

// initialize encoded and decoded tables
void create_table()
{
    lookup_enc[hashDec('A')] = ".-";
    lookup_dec[hashEnc(".-")] = "A";

    // TODO: Do this for the rest of the alphabets and for all digits
}

// Get encoded value of alphanumeric character provided in argument
char *getEncoded(char dec)
{
    // TODO: Return the hash if it exists else an error message
}

// Get decoded value of morse encoded string in argument
char *getDecoded(char *enc)
{
    // TODO: Return the hash if it exists else an error message
}