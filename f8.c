#include "shell.h"

/* Modified:*
 * new_print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t new_print_list(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        new__puts(convert_number(h->num, 10, 0));
        new__putchar(':');
        new__putchar(' ');
        new__puts(h->str ? h->str : "(nil)");
        new__puts("\n");
        h = h->next;
        i++;
    }
    return (i);
}

/* Modified:*
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
    char *p = NULL;

    while (node)
    {
        p = starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return (node);
        node = node->next;
    }
    return (NULL);
}

/* Modified:*
 * new_get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t new_get_node_index(list_t *head, list_t *node)
{
    size_t i = 0;

    while (head)
    {
        if (head == node)
            return (i);
        head = head->next;
        i++;
    }
    return (-1);
}
/* Modified:*
 *new__eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void new__eputs(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        new__eputchar(str[i]);
        i++;
    }
}
