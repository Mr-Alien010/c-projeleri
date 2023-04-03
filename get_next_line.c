

char *get_next_line(int fd)
{
    char *str;
    int i = 0;
    char tmp;
    int rd = 0;
    str = malloc(sizeof(char) * 1000);

    while ((rd = read(fd, &tmp, 1)) > 0)
    {
        str[i] = tmp;
        i++;
        if (tmp == '\n')
            break;
    }
    if ((!str[i - 1] && !rd) || rd == -1)
    {
        free(str);
        return (NULL);
    }
    str[i]= '\0';
    return (str);
}


int main()
{
    int sayac = 0;
    char *str;
    int i = 0;
    int fd;
    fd = open("deneme.txt",O_RDONLY);

    str = get_next_line(fd);
    printf("%s", str);
    
    while (str != NULL)
    {
        while (str[i] != '\n' && str[i] != '\0')
        {
            if(str[i] == 'a')
                sayac++;
            i++;
        }
        i = 0;

        free(str);
        str = get_next_line(fd);
        printf("%s", str);
        
        
    }
    printf("\n%d", sayac);
}