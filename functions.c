#include "shell.h"

/* Modified:*
 * new_new__strlen - returns the length of a string
 *
 * Return: integer length of string
 */
int new_new__strlen(char *s)
{
    int new_i = 0;

    if (!s)
        return (0);

    while (*s++)
        new_i++;
    return (new_i);
}

/* Modified:*
 * new_new__strcmp - performs lexicogarphic comparison of two strangs.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int new_new__strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/* Modified:*
 * starts_with - checks if needle starts with haystack
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);
    return ((char *)haystack);
}

/* Modified:*
 * _strcat - concatenates two strings
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
    char *new_ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (new_ret);
}

/* Modified:*
 * _strcpy - copies a string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
    int new_i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[new_i])
    {
        dest[new_i] = src[new_i];
        new_i++;
    }
    dest[new_i] = 0;
    return (dest);
}

/* Modified:*
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    int length = 0;
    char *new_ret;

    if (str == NULL)
        return (NULL);
    while (*str++)
        length++;
    new_ret = malloc(sizeof(char) * (length + 1));
    if (!new_ret)
        return (NULL);
    for (length++; length--;)
        new_ret[length] = *--str;
    return (new_ret);
}

/* Modified:*
 *new__puts - prints an new_input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void new__puts(char *str)
{
    int new_i = 0;

    if (!str)
        return;
    while (str[new_i] != '\0')
    {
        new_new__putchar(str[new_i]);
        new_i++;
    }
}

/* Modified:*
 * new_new__putchar - writes the character new_c to stdout
 * @new_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int new_new__putchar(char new_c)
{
    static int new_i;
    static char new_buf[WRITE_BUF_SIZE];

    if (new_c == BUF_FLUSH || new_i >= WRITE_BUF_SIZE)
    {
        write(1, new_buf, new_i);
        new_i = 0;
    }
    if (new_c != BUF_FLUSH)
        new_buf[new_i++] = new_c;
    return (1);
}

/* Modified:*
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int new_i, new_j;
    char *s = dest;

    new_i = 0;
    while (src[new_i] != '\0' && new_i < n - 1)
    {
        dest[new_i] = src[new_i];
        new_i++;
    }
    if (new_i < n)
    {
        new_j = new_i;
        while (new_j < n)
        {
            dest[new_j] = '\0';
            new_j++;
        }
    }
    return (s);
}

/* Modified:*
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    int new_i, new_j;
    char *s = dest;

    new_i = 0;
    new_j = 0;
    while (dest[new_i] != '\0')
        new_i++;
    while (src[new_j] != '\0' && new_j < n)
    {
        dest[new_i] = src[new_j];
        new_i++;
        new_j++;
    }
    if (new_j < n)
        dest[new_i] = '\0';
    return (s);
}

/* Modified:*
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@new_c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char new_c)
{
    do
    {
        if (*s == new_c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}

/* Modified:*
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the new_input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
    int new_i, new_j, new_k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == 0)
        return (NULL);
    if (!d)
        d = " ";
    for (new_i = 0; str[new_i] != '\0'; new_i++)
        if (!new_new_is_delim(str[new_i], d) && (new_new_is_delim(str[new_i + 1], d) || !str[new_i + 1]))
            numwords++;

    if (numwords == 0)
        return (NULL);
    s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return (NULL);
    for (new_i = 0, new_j = 0; new_j < numwords; new_j++)
    {
        while (new_new_is_delim(str[new_i], d))
            new_i++;
        new_k = 0;
        while (!new_new_is_delim(str[new_i + new_k], d) && str[new_i + new_k])
            new_k++;
        s[new_j] = malloc((new_k + 1) * sizeof(char));
        if (!s[new_j])
        {
            for (new_k = 0; new_k < new_j; new_k++)
                free(s[new_k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < new_k; m++)
            s[new_j][m] = str[new_i++];
        s[new_j][m] = 0;
    }
    s[new_j] = NULL;
    return (s);
}

/* Modified:*
 * **strtow2 - splits a string into words
 * @str: the new_input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
    int new_i, new_j, new_k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == 0)
        return (NULL);
    for (new_i = 0; str[new_i] != '\0'; new_i++)
        if ((str[new_i] != d && str[new_i + 1] == d) ||
            (str[new_i] != d && !str[new_i + 1]) || str[new_i + 1] == d)
            numwords++;
    if (numwords == 0)
        return (NULL);
    s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return (NULL);
    for (new_i = 0, new_j = 0; new_j < numwords; new_j++)
    {
        while (str[new_i] == d && str[new_i] != d)
            new_i++;
        new_k = 0;
        while (str[new_i + new_k] != d && str[new_i + new_k] && str[new_i + new_k] != d)
            new_k++;
        s[new_j] = malloc((new_k + 1) * sizeof(char));
        if (!s[new_j])
        {
            for (new_k = 0; new_k < new_j; new_k++)
                free(s[new_k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < new_k; m++)
            s[new_j][m] = str[new_i++];
        s[new_j][m] = 0;
    }
    s[new_j] = NULL;
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
    unsigned int new_i;

    for (new_i = 0; new_i < n; new_i++)
        s[new_i] = b;
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
 * new_new_bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int new_new_bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}
/* Modified:*
 * new_new_interactive - returns true if shell is new_new_interactive mode
 * @info: struct address
 *
 * Return: 1 if new_new_interactive mode, 0 otherwise
 */
int new_new_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/* Modified:*
 * new_new_is_delim - checks if character is a delimeter
 * @new_c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int new_new_is_delim(char new_c, char *delim)
{
    while (*delim)
        if (*delim++ == new_c)
            return (1);
    return (0);
}

/* Modified:*
 *new_new__isalpha - checks for alphabetic character
 *@new_c: The character to new_input
 *Return: 1 if new_c is alphabetic, 0 otherwise
 */

int new_new__isalpha(int new_c)
{
    if ((new_c >= 'a' && new_c <= 'z') || (new_c >= 'A' && new_c <= 'Z'))
        return (1);
    else
        return (0);
}

/* Modified:*
 *new_new__atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int new_new__atoi(char *s)
{
    int new_i, sign = 1, flag = 0, output;
    unsigned int new_result = 0;

    for (new_i = 0; s[new_i] != '\0' && flag != 2; new_i++)
    {
        if (s[new_i] == '-')
            sign *= -1;

        if (s[new_i] >= '0' && s[new_i] <= '9')
        {
            flag = 1;
            new_result *= 10;
            new_result += (s[new_i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -new_result;
    else
        output = new_result;

    return (output);
}
/* Modified:*
 * new_new__erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int new_new__erratoi(char *s)
{
    int new_i = 0;
    unsigned long int new_result = 0;

    if (*s == '+')
        s++; /* Modified: TODO: why does this make main return 255? */
    for (new_i = 0; s[new_i] != '\0'; new_i++)
    {
        if (s[new_i] >= '0' && s[new_i] <= '9')
        {
            new_result *= 10;
            new_result += (s[new_i] - '0');
            if (new_result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }
    return (new_result);
}

/* Modified:*
 * new_print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void new_print_error(info_t *info, char *estr)
{
    new__eputs(info->fname);
    new__eputs(": ");
    new_new_print_d(info->line_count, STDERR_FILENO);
    new__eputs(": ");
    new__eputs(info->argv[0]);
    new__eputs(": ");
    new__eputs(estr);
}

/* Modified:*
 * new_new_print_d - function prints a decimal (integer) number (base 10)
 * @new_input: the new_input
 * @new_fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int new_new_print_d(int new_input, int new_fd)
{
    int (*__putchar)(char) = new_new__putchar;
    int new_i, count = 0;
    unsigned int new__abs_, current;

    if (new_fd == STDERR_FILENO)
        __putchar = new_new__eputchar;
    if (new_input < 0)
    {
        new__abs_ = -new_input;
        __putchar('-');
        count++;
    }
    else
        new__abs_ = new_input;
    current = new__abs_;
    for (new_i = 1000000000; new_i > 1; new_i /= 10)
    {
        if (new__abs_ / new_i)
        {
            __putchar('0' + current / new_i);
            count++;
        }
        current %= new_i;
    }
    __putchar('0' + current);
    count++;

    return (count);
}

/* Modified:*
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return (ptr);
}

/* Modified:*
 * new_remove_comments - function replaces first instance of '#' with '\0'
 * @new_buf: address of the string to modify
 *
 * Return: Always 0;
 */
void new_remove_comments(char *new_buf)
{
    int new_i;

    for (new_i = 0; new_buf[new_i] != '\0'; new_i++)
        if (new_buf[new_i] == '#' && (!new_i || new_buf[new_i - 1] == ' '))
        {
            new_buf[new_i] = '\0';
            break;
        }
}
/* Modified:*
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node new_index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return (NULL);
    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);
    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = num;
    if (str)
    {
        new_head->str = _strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }
    new_head->next = *head;
    *head = new_head;
    return (new_head);
}

/* Modified:*
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node new_index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);

    node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);
    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;
    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
        *head = new_node;
    return (new_node);
}

/* Modified:*
 * new_new_print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t new_new_print_list_str(const list_t *h)
{
    size_t new_i = 0;

    while (h)
    {
        new__puts(h->str ? h->str : "(nil)");
        new__puts("\n");
        h = h->next;
        new_i++;
    }
    return (new_i);
}

/* Modified:*
 * new_new_delete_node_at_index - deletes node at given new_index
 * @head: address of pointer to first node
 * @new_index: new_index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int new_new_delete_node_at_index(list_t **head, unsigned int new_index)
{
    list_t *node, *prev_node;
    unsigned int new_i = 0;

    if (!head || !*head)
        return (0);

    if (!new_index)
    {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1);
    }
    node = *head;
    while (node)
    {
        if (new_i == new_index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }
        new_i++;
        prev_node = node;
        node = node->next;
    }
    return (0);
}

/* Modified:*
 * new_free_list - frees new_all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void new_free_list(list_t **head_ptr)
{
    list_t *node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;
    head = *head_ptr;
    node = head;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }
    *head_ptr = NULL;
}
/* Modified:*
 * new_new_list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t new_new_list_len(const list_t *h)
{
    size_t new_i = 0;

    while (h)
    {
        h = h->next;
        new_i++;
    }
    return (new_i);
}

/* Modified:*
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
    list_t *node = head;
    size_t new_i = new_new_list_len(head), new_j;
    char **strs;
    char *str;

    if (!head || !new_i)
        return (NULL);
    strs = malloc(sizeof(char *) * (new_i + 1));
    if (!strs)
        return (NULL);
    for (new_i = 0; node; node = node->next, new_i++)
    {
        str = malloc(new_new__strlen(node->str) + 1);
        if (!str)
        {
            for (new_j = 0; new_j < new_i; new_j++)
                free(strs[new_j]);
            free(strs);
            return (NULL);
        }

        str = _strcpy(str, node->str);
        strs[new_i] = str;
    }
    strs[new_i] = NULL;
    return (strs);
}

/* Modified:*
 * new_new_print_list - prints new_all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t new_new_print_list(const list_t *h)
{
    size_t new_i = 0;

    while (h)
    {
        new__puts(convert_number(h->num, 10, 0));
        new_new__putchar(':');
        new_new__putchar(' ');
        new__puts(h->str ? h->str : "(nil)");
        new__puts("\n");
        h = h->next;
        new_i++;
    }
    return (new_i);
}

/* Modified:*
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @new_c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char new_c)
{
    char *p = NULL;

    while (node)
    {
        p = starts_with(node->str, prefix);
        if (p && ((new_c == -1) || (*p == new_c)))
            return (node);
        node = node->next;
    }
    return (NULL);
}

/* Modified:*
 * new_new_get_node_index - gets the new_index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: new_index of node or -1
 */
ssize_t new_new_get_node_index(list_t *head, list_t *node)
{
    size_t new_i = 0;

    while (head)
    {
        if (head == node)
            return (new_i);
        head = head->next;
        new_i++;
    }
    return (-1);
}
/* Modified:*
 *new__eputs - prints an new_input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void new__eputs(char *str)
{
    int new_i = 0;

    if (!str)
        return;
    while (str[new_i] != '\0')
    {
        new_new__eputchar(str[new_i]);
        new_i++;
    }
}

/* Modified:*
 * new_new__eputchar - writes the character new_c to stderr
 * @new_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int new_new__eputchar(char new_c)
{
    static int new_i;
    static char new_buf[WRITE_BUF_SIZE];

    if (new_c == BUF_FLUSH || new_i >= WRITE_BUF_SIZE)
    {
        write(2, new_buf, new_i);
        new_i = 0;
    }
    if (new_c != BUF_FLUSH)
        new_buf[new_i++] = new_c;
    return (1);
}

/* Modified:*
 * new_new__putfd - writes the character new_c to given new_fd
 * @new_c: The character to print
 * @new_fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int new_new__putfd(char new_c, int new_fd)
{
    static int new_i;
    static char new_buf[WRITE_BUF_SIZE];

    if (new_c == BUF_FLUSH || new_i >= WRITE_BUF_SIZE)
    {
        write(new_fd, new_buf, new_i);
        new_i = 0;
    }
    if (new_c != BUF_FLUSH)
        new_buf[new_i++] = new_c;
    return (1);
}

/* Modified:*
 *new_new__putsfd - prints an new_input string
 * @str: the string to be printed
 * @new_fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int new_new__putsfd(char *str, int new_fd)
{
    int new_i = 0;

    if (!str)
        return (0);
    while (*str)
    {
        new_i += new_new__putfd(*str++, new_fd);
    }
    return (new_i);
}
/* Modified:*
 * new_clear_info - initializes info_t struct
 * @info: struct address
 */
void new_clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}

/* Modified:*
 * new_set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void new_set_info(info_t *info, char **av)
{
    int new_i = 0;

    info->fname = av[0];
    if (info->arg)
    {
        info->argv = strtow(info->arg, " \t");
        if (!info->argv)
        {

            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv)
            {
                info->argv[0] = _strdup(info->arg);
                info->argv[1] = NULL;
            }
        }
        for (new_i = 0; info->argv && info->argv[new_i]; new_i++)
            ;
        info->argc = new_i;

        new_new_replace_alias(info);
        new_new_replace_vars(info);
    }
}

/* Modified:*
 * new_free_info - frees info_t struct fields
 * @info: struct address
 * @new_all: true if freeing new_all fields
 */
void new_free_info(info_t *info, int new_all)
{
    new_ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;
    if (new_all)
    {
        if (!info->cmd_buf)
            free(info->arg);
        if (info->env)
            new_free_list(&(info->env));
        if (info->history)
            new_free_list(&(info->history));
        if (info->alias)
            new_free_list(&(info->alias));
        new_ffree(info->environ);
        info->environ = NULL;
        new_new_bfree((void **)info->cmd_buf);
        if (info->readfd > 2)
            close(info->readfd);
        new_new__putchar(BUF_FLUSH);
    }
}
/* Modified:*
 * new_new__myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int new_new__myenv(info_t *info)
{
    new_new_print_list_str(info->env);
    return (0);
}

/* Modified:*
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}

/* Modified:*
 * new_new__mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new_new__mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        new__eputs("Incorrect number of arguements\n");
        return (1);
    }
    if (new_new__setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}

/* Modified:*
 * new_new__myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new_new__myunsetenv(info_t *info)
{
    int new_i;

    if (info->argc == 1)
    {
        new__eputs("Too few arguements.\n");
        return (1);
    }
    for (new_i = 1; new_i <= info->argc; new_i++)
        new_new__unsetenv(info, info->argv[new_i]);

    return (0);
}

/* Modified:*
 * new_new_populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int new_new_populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t new_i;

    for (new_i = 0; environ[new_i]; new_i++)
        add_node_end(&node, environ[new_i], 0);
    info->env = node;
    return (0);
}
/* Modified:*
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
    if (!info->environ || info->env_changed)
    {
        info->environ = list_to_strings(info->env);
        info->env_changed = 0;
    }

    return (info->environ);
}

/* Modified:*
 * new_new__unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int new_new__unsetenv(info_t *info, char *var)
{
    list_t *node = info->env;
    size_t new_i = 0;
    char *p;

    if (!node || !var)
        return (0);

    while (node)
    {
        p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            info->env_changed = new_new_delete_node_at_index(&(info->env), new_i);
            new_i = 0;
            node = info->env;
            continue;
        }
        node = node->next;
        new_i++;
    }
    return (info->env_changed);
}

/* Modified:*
 * new_new__setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int new_new__setenv(info_t *info, char *var, char *value)
{
    char *new_buf = NULL;
    list_t *node;
    char *p;

    if (!var || !value)
        return (0);

    new_buf = malloc(new_new__strlen(var) + new_new__strlen(value) + 2);
    if (!new_buf)
        return (1);
    _strcpy(new_buf, var);
    _strcat(new_buf, "=");
    _strcat(new_buf, value);
    node = info->env;
    while (node)
    {
        p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            free(node->str);
            node->str = new_buf;
            info->env_changed = 1;
            return (0);
        }
        node = node->next;
    }
    add_node_end(&(info->env), new_buf, 0);
    free(new_buf);
    info->env_changed = 1;
    return (0);
}
/* Modified:*
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
    char *new_buf, *dir;

    dir = _getenv(info, "HOME=");
    if (!dir)
        return (NULL);
    new_buf = malloc(sizeof(char) * (new_new__strlen(dir) + new_new__strlen(HIST_FILE) + 2));
    if (!new_buf)
        return (NULL);
    new_buf[0] = 0;
    _strcpy(new_buf, dir);
    _strcat(new_buf, "/");
    _strcat(new_buf, HIST_FILE);
    return (new_buf);
}

/* Modified:*
 * new_new_write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int new_new_write_history(info_t *info)
{
    ssize_t new_fd;
    char *filename = get_history_file(info);
    list_t *node = NULL;

    if (!filename)
        return (-1);

    new_fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);
    if (new_fd == -1)
        return (-1);
    for (node = info->history; node; node = node->next)
    {
        new_new__putsfd(node->str, new_fd);
        new_new__putfd('\n', new_fd);
    }
    new_new__putfd(BUF_FLUSH, new_fd);
    close(new_fd);
    return (1);
}

/* Modified:*
 * new_new_read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int new_new_read_history(info_t *info)
{
    int new_i, last = 0, new_linecount = 0;
    ssize_t new_fd, rdlen, fsize = 0;
    struct stat st;
    char *new_buf = NULL, *filename = get_history_file(info);

    if (!filename)
        return (0);

    new_fd = open(filename, O_RDONLY);
    free(filename);
    if (new_fd == -1)
        return (0);
    if (!fstat(new_fd, &st))
        fsize = st.st_size;
    if (fsize < 2)
        return (0);
    new_buf = malloc(sizeof(char) * (fsize + 1));
    if (!new_buf)
        return (0);
    rdlen = read(new_fd, new_buf, fsize);
    new_buf[fsize] = 0;
    if (rdlen <= 0)
        return (free(new_buf), 0);
    close(new_fd);
    for (new_i = 0; new_i < fsize; new_i++)
        if (new_buf[new_i] == '\n')
        {
            new_buf[new_i] = 0;
            new_new_build_history_list(info, new_buf + last, new_linecount++);
            last = new_i + 1;
        }
    if (last != new_i)
        new_new_build_history_list(info, new_buf + last, new_linecount++);
    free(new_buf);
    info->histcount = new_linecount;
    while (info->histcount-- >= HIST_MAX)
        new_new_delete_node_at_index(&(info->history), 0);
    new_new_renumber_history(info);
    return (info->histcount);
}

/* Modified:*
 * new_new_build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @new_buf: buffer
 * @new_linecount: the history new_linecount, histcount
 *
 * Return: Always 0
 */
int new_new_build_history_list(info_t *info, char *new_buf, int new_linecount)
{
    list_t *node = NULL;

    if (info->history)
        node = info->history;
    add_node_end(&node, new_buf, new_linecount);

    if (!info->history)
        info->history = node;
    return (0);
}

/* Modified:*
 * new_new_renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int new_new_renumber_history(info_t *info)
{
    list_t *node = info->history;
    int new_i = 0;

    while (node)
    {
        node->num = new_i++;
        node = node->next;
    }
    return (info->histcount = new_i);
}
/* Modified:*
 * new_new__myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int new_new__myexit(info_t *info)
{
    int new_exitcheck;

    if (info->argv[1]) /* Modified: If there is an exit arguement */
    {
        new_exitcheck = new_new__erratoi(info->argv[1]);
        if (new_exitcheck == -1)
        {
            info->status = 2;
            new_print_error(info, "Illegal number: ");
            new__eputs(info->argv[1]);
            new_new__eputchar('\n');
            return (1);
        }
        info->err_num = new_new__erratoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/* Modified:*
 * new_new__mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new_new__mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int new_chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        new__puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            new_chdir_ret = /* Modified: TODO: what should this be? */
                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            new_chdir_ret = chdir(dir);
    }
    else if (new_new__strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            new__puts(s);
            new_new__putchar('\n');
            return (1);
        }
        new__puts(_getenv(info, "OLDPWD=")), new_new__putchar('\n');
        new_chdir_ret = /* Modified: TODO: what should this be? */
            chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        new_chdir_ret = chdir(info->argv[1]);
    if (new_chdir_ret == -1)
    {
        new_print_error(info, "can't cd to ");
        new__eputs(info->argv[1]), new_new__eputchar('\n');
    }
    else
    {
        new_new__setenv(info, "OLDPWD", _getenv(info, "PWD="));
        new_new__setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/* Modified:*
 * new_new__myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new_new__myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    new__puts("help call works. Function not yet implemented \n");
    if (0)
        new__puts(*arg_array); /* Modified: temp att_unused workaround */
    return (0);
}
/* Modified:*
 * new_new__myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new_new__myhistory(info_t *info)
{
    new_new_print_list(info->history);
    return (0);
}

/* Modified:*
 * new_unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int new_unset_alias(info_t *info, char *str)
{
    char *p, new_c;
    int new_ret;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    new_c = *p;
    *p = 0;
    new_ret = new_new_delete_node_at_index(&(info->alias),
                                           new_new_get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
    *p = new_c;
    return (new_ret);
}

/* Modified:*
 * new_set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int new_set_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (new_unset_alias(info, str));

    new_unset_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}

/* Modified:*
 * new_print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int new_print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            new_new__putchar(*a);
        new_new__putchar('\'');
        new__puts(p + 1);
        new__puts("'\n");
        return (0);
    }
    return (1);
}

/* Modified:*
 * new_new__myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new_new__myalias(info_t *info)
{
    int new_i = 0;
    char *p = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            new_print_alias(node);
            node = node->next;
        }
        return (0);
    }
    for (new_i = 1; info->argv[new_i]; new_i++)
    {
        p = _strchr(info->argv[new_i], '=');
        if (p)
            new_set_alias(info, info->argv[new_i]);
        else
            new_print_alias(node_starts_with(info->alias, info->argv[new_i], '='));
    }

    return (0);
}
/* Modified:*
 * new_new_is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int new_new_is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/* Modified:*
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting new_index
 * @stop: stopping new_index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char new_buf[1024];
    int new_i = 0, new_k = 0;

    for (new_k = 0, new_i = start; new_i < stop; new_i++)
        if (pathstr[new_i] != ':')
            new_buf[new_k++] = pathstr[new_i];
    new_buf[new_k] = 0;
    return (new_buf);
}

/* Modified:*
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int new_i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);
    if ((new_new__strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (new_new_is_cmd(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[new_i] || pathstr[new_i] == ':')
        {
            path = dup_chars(pathstr, curr_pos, new_i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (new_new_is_cmd(info, path))
                return (path);
            if (!pathstr[new_i])
                break;
            curr_pos = new_i;
        }
        new_i++;
    }
    return (NULL);
}
/* Modified:*
 * new_new_is_chain - test if current char in buffer is a chain delimeter
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int new_new_is_chain(info_t *info, char *new_buf, size_t *p)
{
    size_t new_j = *p;

    if (new_buf[new_j] == '|' && new_buf[new_j + 1] == '|')
    {
        new_buf[new_j] = 0;
        new_j++;
        info->cmd_buf_type = CMD_OR;
    }
    else if (new_buf[new_j] == '&' && new_buf[new_j + 1] == '&')
    {
        new_buf[new_j] = 0;
        new_j++;
        info->cmd_buf_type = CMD_AND;
    }
    else if (new_buf[new_j] == ';') /* Modified: found end of this command */
    {
        new_buf[new_j] = 0; /* Modified: replace semicolon with null */
        info->cmd_buf_type = CMD_CHAIN;
    }
    else
        return (0);
    *p = new_j;
    return (1);
}

/* Modified:*
 * new_check_chain - checks we should continue chaining based on last status
 * @new_len: length of new_buf
 *
 * Return: Void
 */
void new_check_chain(info_t *info, char *new_buf, size_t *p, size_t new_i, size_t new_len)
{
    size_t new_j = *p;

    if (info->cmd_buf_type == CMD_AND)
    {
        if (info->status)
        {
            new_buf[new_i] = 0;
            new_j = new_len;
        }
    }
    if (info->cmd_buf_type == CMD_OR)
    {
        if (!info->status)
        {
            new_buf[new_i] = 0;
            new_j = new_len;
        }
    }

    *p = new_j;
}

/* Modified:*
 * new_new_replace_alias - replaces an aliases in the tokenized string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int new_new_replace_alias(info_t *info)
{
    int new_i;
    list_t *node;
    char *p;

    for (new_i = 0; new_i < 10; new_i++)
    {
        node = node_starts_with(info->alias, info->argv[0], '=');
        if (!node)
            return (0);
        free(info->argv[0]);
        p = _strchr(node->str, '=');
        if (!p)
            return (0);
        p = _strdup(p + 1);
        if (!p)
            return (0);
        info->argv[0] = p;
    }
    return (1);
}

/* Modified:*
 * new_new_replace_vars - r
 *
 * Return: 1 if replaced, 0 otherwise
 */
int new_new_replace_vars(info_t *info)
{
    int new_i = 0;
    list_t *node;

    for (new_i = 0; info->argv[new_i]; new_i++)
    {
        if (info->argv[new_i][0] != '$' || !info->argv[new_i][1])
            continue;

        if (!new_new__strcmp(info->argv[new_i], "$?"))
        {
            new_new_replace_string(&(info->argv[new_i]),
                                   _strdup(convert_number(info->status, 10, 0)));
            continue;
        }
        if (!new_new__strcmp(info->argv[new_i], "$$"))
        {
            new_new_replace_string(&(info->argv[new_i]),
                                   _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = node_starts_with(info->env, &info->argv[new_i][1], '=');
        if (node)
        {
            new_new_replace_string(&(info->argv[new_i]),
                                   _strdup(_strchr(node->str, '=') + 1));
            continue;
        }
        new_new_replace_string(&info->argv[new_i], _strdup(""));
    }
    return (0);
}

/* Modified:*
 * new_new_replace_string - re
 *
 * Return: 1 if replaced, 0 otherwise
 */
int new_new_replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
    return (1);
}
/* Modified:*
 * new_input_buf - buffers chained c
 *
 * Return: bytes read
 */
ssize_t new_input_buf(info_t *info, char **new_buf, size_t *new_len)
{
    ssize_t new_r = 0;
    size_t new_len_p = 0;

    if (!*new_len) /* Modified: if nothing left in the buffer, fill it */
    {

        free(*new_buf);
        *new_buf = NULL;
        signal(SIGINT, new_sigintHandler);
#if USE_GETLINE
        new_r = getline(new_buf, &new_len_p, stdin);
#else
        new_r = new_new__getline(info, new_buf, &new_len_p);
#endif
        if (new_r > 0)
        {
            if ((*new_buf)[new_r - 1] == '\n')
            {
                (*new_buf)[new_r - 1] = '\0';
                new_r--;
            }
            info->linecount_flag = 1;
            new_remove_comments(*new_buf);
            new_new_build_history_list(info, *new_buf, info->histcount++);
            /* Modified: if (_strchr(*new_buf, ';')) is this a command chain? */
            {
                *new_len = new_r;
                info->cmd_buf = new_buf;
            }
        }
    }
    return (new_r);
}

/* Modified:*
 * new_new_get_input - gets
 *
 * Return: bytes read
 */
ssize_t new_new_get_input(info_t *info)
{
    static char *new_buf; /* Modified: the ';' command chain buffer */
    static size_t new_i, new_j, new_len;
    ssize_t new_r = 0;
    char **buf_p = &(info->arg), *p;

    new_new__putchar(BUF_FLUSH);
    new_r = new_input_buf(info, &new_buf, &new_len);
    if (new_r == -1) /* Modified: EOF */
        return (-1);
    if (new_len) /* Modified: we have commands left in the chain buffer */
    {
        new_j = new_i;       /* Modified: init new iterator to current new_buf position */
        p = new_buf + new_i; /* Modified: get pointer for return */

        new_check_chain(info, new_buf, &new_j, new_i, new_len);
        while (new_j < new_len) /* Modified: iterate to semicolon or end */
        {
            if (new_new_is_chain(info, new_buf, &new_j))
                break;
            new_j++;
        }

        new_i = new_j + 1; /* Modified: increment past nulled ';'' */
        if (new_i >= new_len)
        {
            new_i = new_len = 0; /* Modified: reset position and length */
            info->cmd_buf_type = CMD_NORM;
        }

        *buf_p = p;                  /* Modified: pass back pointer to current command position */
        return (new_new__strlen(p)); /* Modified: return length of current command */
    }

    *buf_p = new_buf; /* Modified: else not a chain, pass back buffer from new_new__getline() */
    return (new_r);   /* Modified: return length of buffer from new_new__getline() */
}

/* Modified:*
 * new_read_buf - r
 *
 * Return: new_r
 */
ssize_t new_read_buf(info_t *info, char *new_buf, size_t *new_i)
{
    ssize_t new_r = 0;

    if (*new_i)
        return (0);
    new_r = read(info->readfd, new_buf, READ_BUF_SIZE);
    if (new_r >= 0)
        *new_i = new_r;
    return (new_r);
}

/* Modified:*
 * new_new__getline - gets the next line of new_input f
 *
 * Return: s
 */
int new_new__getline(info_t *info, char **ptr, size_t *length)
{
    static char new_buf[READ_BUF_SIZE];
    static size_t new_i, new_len;
    size_t new_k;
    ssize_t new_r = 0, s = 0;
    char *p = NULL, *new_p = NULL, *new_c;

    p = *ptr;
    if (p && length)
        s = *length;
    if (new_i == new_len)
        new_i = new_len = 0;

    new_r = new_read_buf(info, new_buf, &new_len);
    if (new_r == -1 || (new_r == 0 && new_len == 0))
        return (-1);

    new_c = _strchr(new_buf + new_i, '\n');
    new_k = new_c ? 1 + (unsigned int)(new_c - new_buf) : new_len;
    new_p = _realloc(p, s, s ? s + new_k : new_k + 1);
    if (!new_p) /* Modified: MALLOC FAILURE! */
        return (p ? free(p), -1 : -1);

    if (s)
        _strncat(new_p, new_buf + new_i, new_k - new_i);
    else
        _strncpy(new_p, new_buf + new_i, new_k - new_i + 1);

    s += new_k - new_i;
    new_i = new_k;
    p = new_p;

    if (length)
        *length = s;
    *ptr = p;
    return (s);
}

/* Modified:*
 * new_sigintHandler - blocks
 *
 * Return: void
 */
void new_sigintHandler(__attribute__((unused)) int sig_num)
{
    new__puts("\n");
    new__puts("$ ");
    new_new__putchar(BUF_FLUSH);
}
/* Modified:*
 * new_new_hsh - main shell loop
 *
 * Return: 0 on success, 1 on error, or error code
 */
int new_new_hsh(info_t *info, char **av)
{
    ssize_t new_r = 0;
    int new_builtin_ret = 0;

    while (new_r != -1 && new_builtin_ret != -2)
    {
        new_clear_info(info);
        if (new_new_interactive(info))
            new__puts("$ ");
        new_new__eputchar(BUF_FLUSH);
        new_r = new_new_get_input(info);
        if (new_r != -1)
        {
            new_set_info(info, av);
            new_builtin_ret = new_new_find_builtin(info);
            if (new_builtin_ret == -1)
                new_find_cmd(info);
        }
        else if (new_new_interactive(info))
            new_new__putchar('\n');
        new_free_info(info, 0);
    }
    new_new_write_history(info);
    new_free_info(info, 1);
    if (!new_new_interactive(info) && info->status)
        exit(info->status);
    if (new_builtin_ret == -2)
    {
        if (info->err_num == -1)
            exit(info->status);
        exit(info->err_num);
    }
    return (new_builtin_ret);
}

/* Modified:*
 * new_new_find_builtin - finds a
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int new_new_find_builtin(info_t *info)
{
    int new_i, built_in_ret = -1;
    builtin_table builtintbl[] = {
        {"exit", new_new__myexit},
        {"env", new_new__myenv},
        {"help", new_new__myhelp},
        {"history", new_new__myhistory},
        {"setenv", new_new__mysetenv},
        {"unsetenv", new_new__myunsetenv},
        {"cd", new_new__mycd},
        {"alias", new_new__myalias},
        {NULL, NULL}};

    for (new_i = 0; builtintbl[new_i].type; new_i++)
        if (new_new__strcmp(info->argv[0], builtintbl[new_i].type) == 0)
        {
            info->line_count++;
            built_in_ret = builtintbl[new_i].func(info);
            break;
        }
    return (built_in_ret);
}

/* Modified:*
 * new_find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void new_find_cmd(info_t *info)
{
    char *path = NULL;
    int new_i, new_k;

    info->path = info->argv[0];
    if (info->linecount_flag == 1)
    {
        info->line_count++;
        info->linecount_flag = 0;
    }
    for (new_i = 0, new_k = 0; info->arg[new_i]; new_i++)
        if (!new_new_is_delim(info->arg[new_i], " \t\n"))
            new_k++;
    if (!new_k)
        return;

    path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
    if (path)
    {
        info->path = path;
        new_fork_cmd(info);
    }
    else
    {
        if ((new_new_interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/') && new_new_is_cmd(info, info->argv[0]))
            new_fork_cmd(info);
        else if (*(info->arg) != '\n')
        {
            info->status = 127;
            new_print_error(info, "not found\n");
        }
    }
}

/* Modified:*
 * new_fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void new_fork_cmd(info_t *info)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        /* Modified: TODO: PUT ERROR FUNCTION */
        perror("Error:");
        return;
    }
    if (child_pid == 0)
    {
        if (execve(info->path, info->argv, get_environ(info)) == -1)
        {
            new_free_info(info, 1);
            if (errno == EACCES)
                exit(126);
            exit(1);
        }
        /* Modified: TODO: PUT ERROR FUNCTION */
    }
    else
    {
        wait(&(info->status));
        if (WIFEXITED(info->status))
        {
            info->status = WEXITSTATUS(info->status);
            if (info->status == 126)
                new_print_error(info, "Permission denied\n");
        }
    }
}
