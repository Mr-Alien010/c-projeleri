
#include "canavar.h"

char *ft_itoa(int n)
{
    int i = 0;
    int a = n;
    char *str;
    
    if (a <= 0)
        i++;
    
    while (a)
    {
        a /= 10;
        i++;
    }

    str = (char *) malloc(sizeof(char) * (i + 1));
    
    str[i--] = '\0';
    

    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    while (n)
    {
        str[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return (str);
}
