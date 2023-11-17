#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singl
 */
typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;

/**
 *struct passinfo - cont
 */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf;   /* pointer to cmd ; chain buffer, for memory mangement */
    int cmd_buf_type; /* CMD_type ||, &&, ; */
    int readfd;
    int histcount;
} info_t;

#define INFO_INIT                                                               \
    {                                                                           \
        NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
            0, 0, 0                                                             \
    }

/**
 *struct builtin - contain
 */
typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;
int new_hsh(info_t *, char **);
int new_find_builtin(info_t *);
void new_find_cmd(info_t *);
void new_fork_cmd(info_t *);
int new_is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int new_loophsh(char **);
void new__eputs(char *);
int new__eputchar(char);
int new__putfd(char c, int fd);
int new__putsfd(char *str, int fd);
int new__strlen(char *);
int new__strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void new__puts(char *);
int new__putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void new_ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int new_bfree(void **);
int new_interactive(info_t *);
int new_is_delim(char, char *);
int new__isalpha(int);
int new__atoi(char *);
int new__erratoi(char *);
void new_print_error(info_t *, char *);
int new_print_d(int, int);
char *convert_number(long int, int, int);
void new_remove_comments(char *);
int new__myexit(info_t *);
int new__mycd(info_t *);
int new__myhelp(info_t *);
int new__myhistory(info_t *);
int new__myalias(info_t *);
ssize_t new_get_input(info_t *);
int new__getline(info_t *, char **, size_t *);
void new_sigintHandler(int);
void new_clear_info(info_t *);
void new_set_info(info_t *, char **);
void new_free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int new__myenv(info_t *);
int new__mysetenv(info_t *);
int new__myunsetenv(info_t *);
int new_populate_env_list(info_t *);
char **get_environ(info_t *);
int new__unsetenv(info_t *, char *);
int new__setenv(info_t *, char *, char *);
char *get_history_file(info_t *info);
int new_write_history(info_t *info);
int new_read_history(info_t *info);
int new_build_history_list(info_t *info, char *buf, int linecount);
int new_renumber_history(info_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t new_print_list_str(const list_t *);
int new_delete_node_at_index(list_t **, unsigned int);
void new_free_list(list_t **);
size_t new_list_len(const list_t *);
char **list_to_strings(list_t *);
size_t new_print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t new_get_node_index(list_t *, list_t *);
int new_is_chain(info_t *, char *, size_t *);
void new_check_chain(info_t *, char *, size_t *, size_t, size_t);
int new_replace_alias(info_t *);
int new_replace_vars(info_t *);
int new_replace_string(char **, char *);

#endif
