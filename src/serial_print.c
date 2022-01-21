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
     * Ok, so figure out what io_write is by holding down the ALT key and clicking on the function.
     * You should be able to see all necessary details.
     */

    // TODO: Call io_write with appropriate arguments. Be very careful about the types expected by
    // the arguments!
}

void reverse(char str[], int length)
{
    int start = 0;
    char str_b[length];
    for (int i = length - 1; i >= 0; i--)
    {
        str_b[start] = str[i];
        start++;
    }

    for (int i = 0; i < length; i++)
    {
        str[i] = str_b[i];
        start++;
    }
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