#include "shell.h"


/* Modified:*
 * new_write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int new_write_history(info_t *info)
{
    ssize_t fd;
    char *filename = get_history_file(info);
    list_t *node = NULL;

    if (!filename)
        return (-1);

    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);
    if (fd == -1)
        return (-1);
    for (node = info->history; node; node = node->next)
    {
        new__putsfd(node->str, fd);
        new__putfd('\n', fd);
    }
    new__putfd(BUF_FLUSH, fd);
    close(fd);
    return (1);
}

/* Modified:*
 * new_read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int new_read_history(info_t *info)
{
    int i, last = 0, linecount = 0;
    ssize_t fd, rdlen, fsize = 0;
    struct stat st;
    char *buf = NULL, *filename = get_history_file(info);

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    free(filename);
    if (fd == -1)
        return (0);
    if (!fstat(fd, &st))
        fsize = st.st_size;
    if (fsize < 2)
        return (0);
    buf = malloc(sizeof(char) * (fsize + 1));
    if (!buf)
        return (0);
    rdlen = read(fd, buf, fsize);
    buf[fsize] = 0;
    if (rdlen <= 0)
        return (free(buf), 0);
    close(fd);
    for (i = 0; i < fsize; i++)
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            new_build_history_list(info, buf + last, linecount++);
            last = i + 1;
        }
    if (last != i)
        new_build_history_list(info, buf + last, linecount++);
    free(buf);
    info->histcount = linecount;
    while (info->histcount-- >= HIST_MAX)
        new_delete_node_at_index(&(info->history), 0);
    new_renumber_history(info);
    return (info->histcount);
}

/* Modified:*
 * new_build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int new_build_history_list(info_t *info, char *buf, int linecount)
{
    list_t *node = NULL;

    if (info->history)
        node = info->history;
    add_node_end(&node, buf, linecount);

    if (!info->history)
        info->history = node;
    return (0);
}

/* Modified:*
 * new_renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int new_renumber_history(info_t *info)
{
    list_t *node = info->history;
    int i = 0;

    while (node)
    {
        node->num = i++;
        node = node->next;
    }
    return (info->histcount = i);
}
/* Modified:*
 * new__myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int new__myexit(info_t *info)
{
    int exitcheck;

    if (info->argv[1]) /* Modified: If there is an exit arguement */
    {
        exitcheck = new__erratoi(info->argv[1]);
        if (exitcheck == -1)
        {
            info->status = 2;
            new_print_error(info, "Illegal number: ");
            new__eputs(info->argv[1]);
            new__eputchar('\n');
            return (1);
        }
        info->err_num = new__erratoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}
