#include "minishell.h"

char	*ft_strjoin(char  *s1, char const *s2)
{
	size_t	lp;
	size_t	lc;
	char	*p;

	if (s1 && !s2)
		return ((char *) s1);
	if (!s1 && s2)
		return ((char *) s2);
	if (!s1 || !s2)
		return (NULL);
	lc = ft_strlen(s2);
	lp = ft_strlen(s1);
	p = (char *)malloc(lp + lc + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy (p, s1, lp +1);
	ft_strlcat (p, s2, (lc + lp +1));
    // free(s1);
	return (p);
}

void    free_string(char **s,char*s1)
{
    if(!s && !s1)
        return ;
    if(s)
    {
        while(*s != NULL)
        {
            free(*s);
            s++;
        }
            free(s);
    }
    if(s1)
        free(s1);
}
char    *find_comond(t_exex_cmd **main)
{
    t_exex_cmd *cmd =  *main;
    int i = 0;
    t_ev    *tmp = cmd->env;
    char    *path;
    char    *add;
    char    **fullpath;
    // if(!tmp)
    //     printf("1\n");
    // printf("1\n");
    
    while(tmp !=   NULL && (ft_strncmp(tmp->vars,"PATH",4)) != 0)
    {
        if((ft_strncmp(tmp->vars,"PATH",4)) == 0)
            break;
        else
            tmp = tmp->next;
    }
    if(tmp ==   NULL)
        return(NULL);
    if((ft_strncmp(tmp->vars, "PATH", 4)) == 0)
    {
        // printf("%s\n",tmp->content);
        fullpath = ft_split(tmp->content, ':');
        while(fullpath[i] != NULL)
        {
            add = fullpath[i];
            fullpath[i] =  ft_strjoin(fullpath[i],"/");
            free(add);
            if(!fullpath[i])
                return NULL;
            path = ft_strjoin(fullpath[i],cmd->args[0]);
            if(!path[i])
                return NULL;
            if(!access(path, X_OK))
            {

                // printf("lololo %s\n",path);
                return(path);
            }
            i++;
        }
        // free_string(fullpath,path);
    }
    return (NULL);

}
int    pars(char *s,t_exex_cmd *cmd,char **env)
{
    cmd->args = ft_split(s,' ');
    cmd->cmd = find_comond(&cmd);
    if(!cmd->cmd)
        return 1;
    cmd->infd = 0;
    cmd->outfd = 1;
    return 0;
    // free_string(all,NULL);
}
void    child(t_exex_cmd *s,char **env)
{
    execve(s->cmd , s->args,env);
}

void     exic(t_exex_cmd *s,char **env)
{
    
    pid_t pid  = fork();

    if(pid == 0)
    {
        child(s,env);
        return ;

    }
    else 
        waitpid(pid,0,0);
    
}
void    init(t_exex_cmd *st)
{
    st = malloc(sizeof(t_exex_cmd));

}
int main(int ac,char **av ,char **env)
{
    t_exex_cmd data;
    // if(!data)
    //     return;
    init(&data);
    data.env = env_set(env);
    if(!data.env)
        return 1;
    // printf("%s\n",data.env->content);
    char *cmn;
    while (1)
    {

        cmn = readline("my shell : ");
        pars(cmn,&data,env);
            // printf("wa3\n");
        // printf("_________%p___________\n",data.cmd);
        // free(cmn);
        exic(&data,env);
        // printf("%s\n",cmn);
        free(cmn);
    }
    

    
    


}
// bool    setenv()
// void my_export(const char *name, const char *value) {
//     if (setenv(name, value, 1) != 0) {
//         perror("setenv");
//     } else {
//         printf("Exported: %s=%s\n", name, value);
//     }
// }

// void my_unset(const char *name) {
//     if (unsetenv(name) != 0) {
//         perror("unsetenv");
//     } else {
//         printf("Unset: %s\n", name);
//     }
// }

// void my_env() {
//     char **env = environ;
//     while (*env) {
//         printf("%s\n", *env);
//         env++;
//     }
// }