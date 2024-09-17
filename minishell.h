#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

typedef struct s_ev t_ev;
typedef struct s_ev
{
    char *vars;
    char *content;
    t_ev *next;
} t_ev;

typedef struct s_pipe
{
    char    *comond;
    int     infile;
    int     outfile;
}t_pipe;

// typedef struct s_evr
// {
//     char **env;
//     char **export_arg;
// }t_evr;

typedef struct exec_cmd
{
    char *cmd;
    char **args;
    char **lenv;
    int     infd;
    int     outfd;
    t_ev    *env;


}t_exex_cmd;

// typedef struct comond_s
// {
//     bool    herdoc;
//     int    infile;
//     bool    outfile;
//     char    **env;
//     int     inf_next_pipe;
//     char    
//     t_pipe    pipe;
//     commond_t   *next;
// }   commond_t;

char	**ft_split(char const *s, char c);
t_ev     *env_set(char **envi);
size_t	ft_strlen(const char *str);
size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char  *s1, char const *s2);

#endif