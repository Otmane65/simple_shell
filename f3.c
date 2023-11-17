#include "shell.h"

/* Modified:*
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
    int i, j, k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == 0)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numwords++;
    if (numwords == 0)
        return (NULL);
    s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return (NULL);
    for (i = 0, j = 0; j < numwords; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;
        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;
        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            s[j][m] = str[i++];
        s[j][m] = 0;
    }
    s[j] = NULL;
    return (s);
}

/* Modified:*
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}

/* Modified:*
 * new_ffree - frees a string of strings
 * @pp: string of strings
 */
void new_ffree(char **pp)
{
    char **a = pp;

    if (!pp)
        return;
    while (*pp)
        free(*pp++);
    free(a);
}

/* Modified:*
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);

    p = malloc(new_size);
    if (!p)
        return (NULL);

    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (p);
}
/* Modified:*
 * new_bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int new_bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}

