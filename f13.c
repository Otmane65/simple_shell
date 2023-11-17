#include "shell.h"


/* Modified:*
 * new__mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new__mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        new__puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = /* Modified: TODO: what should this be? */
                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (new__strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            new__puts(s);
            new__putchar('\n');
            return (1);
        }
        new__puts(_getenv(info, "OLDPWD=")), new__putchar('\n');
        chdir_ret = /* Modified: TODO: what should this be? */
            chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        new_print_error(info, "can't cd to ");
        new__eputs(info->argv[1]), new__eputchar('\n');
    }
    else
    {
        new__setenv(info, "OLDPWD", _getenv(info, "PWD="));
        new__setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/* Modified:*
 * new__myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new__myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    new__puts("help call works. Function not yet implemented \n");
    if (0)
        new__puts(*arg_array); /* Modified: temp att_unused workaround */
    return (0);
}
/* Modified:*
 * new__myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new__myhistory(info_t *info)
{
    new_print_list(info->history);
    return (0);
}

/* Modified:*
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
    char *p, c;
    int ret;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    ret = new_delete_node_at_index(&(info->alias),
                               new_get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
    *p = c;
    return (ret);
}

/* Modified:*
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unset_alias(info, str));

    unset_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}
