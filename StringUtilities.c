#include <stdio.h>
#include <stdlib.h>
size_t my_strlen(const char *s)
{
    size_t i;
    for (i = 0; *(s + i) != '\0'; i++)
        ;
    return i;
}
char *my_strcpy(char *dest, const char *src)
{
    size_t srcLen = my_strlen(src);

    for (size_t i = 0; i <= srcLen; i++)
    {
        *(dest + i) = *(src + i);
    }

    return dest;
}
int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (*(s1 + i) != '\0' && *(s1 + i) == *(s2 + i))
    {
        i++;
    }

    return *(const unsigned char *)(s1 + i) - *(const unsigned char *)(s2 + i);
}

int main()
{

    char str1[10] = "hello";
    char str2[] = "bro";

    printf("str1 length = %zu\n", my_strlen(str1));
    printf("Before copy -> str1: %s, str2: %s\n", str1, str2);

    my_strcpy(str1, str2);
    printf("After copy  -> str1: %s, str2: %s\n", str1, str2);

    if (my_strcmp(str1, str2) == 0)
    {
        printf("ARE EQUAL\n");
    }
    else
    {
        printf("ARE NOT EQUAL\n");
    }

    return 0;
}