#include "shell.h"

/* Modified:*
 * new_interactive - returns true if shell is new_interactive mode
 * @info: struct address
 *
 * Return: 1 if new_interactive mode, 0 otherwise
 */
int new_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/* Modified:*
 * new_is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int new_is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}
/* Modified:*
 *new__puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void new__puts(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        new__putchar(str[i]);
        i++;
    }
}

/* Modified:*
 * new__strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int new__strlen(char *s)
{
    int i = 0;

    if (!s)
        return (0);

    while (*s++)
        i++;
    return (i);
}
