#include "shell.h"


/* Modified:*
 * new_free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void new_free_info(info_t *info, int all)
{
    new_ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;
    if (all)
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
        new_bfree((void **)info->cmd_buf);
        if (info->readfd > 2)
            close(info->readfd);
        new__putchar(BUF_FLUSH);
    }
}
/* Modified:*
 * new__myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int new__myenv(info_t *info)
{
    new_print_list_str(info->env);
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
 * new__mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new__mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        new__eputs("Incorrect number of arguements\n");
        return (1);
    }
    if (new__setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}

/* Modified:*
 * new__myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new__myunsetenv(info_t *info)
{
    int i;

    if (info->argc == 1)
    {
        new__eputs("Too few arguements.\n");
        return (1);
    }
    for (i = 1; i <= info->argc; i++)
        new__unsetenv(info, info->argv[i]);

    return (0);
}
