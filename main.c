#include "shell.h"

/* Modified:*
 * main - e
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = {INFO_INIT};
    int fd = 2;

    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                new__eputs(av[0]);
                new__eputs(": 0: Can't open ");
                new__eputs(av[1]);
                new__eputchar('\n');
                new__eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd;
    }
    new_populate_env_list(info);
    new_read_history(info);
    new_hsh(info, av);
    return (EXIT_SUCCESS);
}
