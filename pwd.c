// #include <unistd.h>
// #include <stdio.h>

// Have you had a look at getcwd()?

// #include <unistd.h>
// char *getcwd(char *buf, size_t size);
// Simple example:
// #include "libft.h"
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// int    my_pwd()    
// {
//    char cwd[PATH_MAX];

//     if (getcwd(cwd, sizeof(cwd)) != NULL)
//        printf("%s\n", cwd);
//     else
//        return (perror("getcwd() error"),1);
//    return 0;
// }
#include <libc.h>
#include "minishell.h"
t_ev     *env_set(char **envi)
{
    t_ev    *env = NULL;
    t_ev    *new_env = NULL;
    t_ev    *tmp = NULL;

    int i = 0;
    int j;
    if(!envi)
        return NULL;
    while(envi[i])
    {
        j = 0;
        while(envi[i][j])
        {
            if(envi[i][j] == '=')
            {
                new_env = malloc(sizeof(t_ev));
                if(!new_env)
                    return NULL;
                envi[i][j] = '\0';
                new_env->vars= strdup(&envi[i][0]);
                new_env->content= strdup(&envi[i][j + 1]);
                new_env->next = NULL;
                if(tmp == NULL)
                    env = new_env;
                else
                    tmp->next = new_env;
                tmp = new_env;
                break;

            }
            j++;
        }
        i++;
    }
//     tmp = env;
//  while (env != NULL) {
//         printf("var = %s  || content = %s\n", env->vars, env->content);
//         env = env->next;
    // }
    return (env);


}
// int     get_cmd_path()
// {


// }
// void    place_it(t_exex_cmd *main)
// {
//     int i = 0;
//     int j ;
//     if(-1 == get_cmd_path())
//         return;
//     while(main->args[i] != NULL)
//     {
        
//         j = 0;
//         while(main->args[i][j] != '\0')
//         {
//             if(main->args[i][j] == '>' || main->args[i][j] == '<' && j == 0)
//             {
//                 if(main->args[i][j] == '>')
//                     redirect(main->args[++i]);
//                 else
//                 {
//                     redirect(main->args[--i]);
//                     i +=2;
//                 }
//             }
//             if()
//         }
        

//     }

// }
// void    pars(char *s,char **env)
// {
//     t_exex_cmd *main;
//     main->args = ft_split(s,' ');
//     main->env = env;
//     place_it(main);
    


// }
// int main(int ac, char **av,char **env)
// {
//     char *line;

//     if(!env)
//         return 1;
//     while(1)
//     {
//         line = readline("minishell :");
//         pars(line,env);
//         printf("%s\n",line);
//         free(line);
//     }
//     env_set(env);
// }