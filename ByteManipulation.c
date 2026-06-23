#include <stdio.h>
void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;
    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dest;
}
void *my_memset(void *src, int c, size_t n)
{
    char *s = (char *)src;
    for (size_t i = 0; i < n; i++)
    {
        s[i] = c;
    }

    return src;
}

int main()
{
    char str1[] = {"hello"};
    char str2[10];
    my_memcpy(str2, str1, 6);
    printf("%s\n", str2);
    my_memset(str2, 'A', 3);
    printf("%s\n", str2);

    return 0;
}