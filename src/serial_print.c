#include "serial_print.h"

void s_print(char *buf)
{
    char *s;
    for (s = buf; *s; ++s)
        ;
    unsigned int size = (unsigned int)(s - buf);

    /**
     * Look into the io_write function. Well, if this were regular C, you would find out what the
     * arguments mean and so on by looking at MAN pages online.
     *
     * But here, since we're dealing with Embedded C in an embedded system, we can't rely on C's
     * libraries.
     *
     * Nevertheless, the reason we have access to io_write is because it's one of the functions
     * provided by the ASF SAM D21 microchip. By the way, ASF stands for Atmel Software Framework.
     * 'Atmel' should ring some bells - it's the chip!
     *
     * Ok, so figure out what io_write is by hovering over the function name. Alternatively, you can
     * see the implementation of the function by holding down the ALT key and clicking on the
     * function name.
     */

    // TODO: Call io_write with appropriate arguments. Be very careful about the types expected by
    // the arguments!
}

// reverses a list of characters inplace. How do we know inplace? Look at the function return type!
void reverse(char str[], int length)
{
    /**
     * There are two approaches to this. The first is to use some temporary storage (temp) and swap
     * characters on opposite ends of the list. For this, you'll need to maintain two pointers.
     *
     * The alternate approach is to first copy the list, then override the list using the copied list
     * iterated in reverse order. Again, you need two pointers here, but you don't update them
     * concurrently as you would in the first approach.
     */
}

// converts integer to string
/**
 * Yes, this is a weird name but that's only because itoa is what C's defualt library calls this
 * function. Why does C do it? Well... idk.
 */
char *itoa(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}