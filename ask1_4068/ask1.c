#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include <fcntl.h>

void print_shell()
{
    char dir[1024];
    printf("%s@cs345sh%s$", getlogin(), getcwd(dir, 1024));
}

int main()
{

    char *cmd = read_input();

    return 0;
}
void change_dir(char *cmd)
{
    if ((chdir(cmd) == -1))
    {
        /* code */
        printf("Path not found\n");
    }
}

void exec_fork(char **cmd)
{

    pid = fork();
    if (pid == 0)
    {
        if (execvp(cmd[0], cmd) < 0)
        {
            perror("The commands doesn't exist");
        }
    }
    else if (pid < 0)
    {
        printf("error in fork\n");
    }
    else
    {
        wait(NULL);
    }
}

char *read_input()
{
    char *buff = (char *)malloc(1000 * sizeof(char));
    char *var = (char *)malloc(1000 * sizeof(char));

    while (1)
    {
        print_shell();
        int i = 0;
        int c;
        int flag = 0;
        char **buffer = malloc(sizeof(char *));
        while ((c = getchar()) != '\n')
        {
            if (c == '|')
            {
                flag = 1;
            }
            if (c == '=')
            {
                flag = 2;
            }
            buff[i] = c;
            i++;
        }
        buff[i] = '\0';
        if (strcmp(buff, "exit") == 0)
        {
            break;
        }
        if (flag==1)
        {
            /* code */
            buffer=splitt_token_pipe(buff,buffer);
        }
        
        else if (flag == 2)
        {
            buffer = put_env(buff, buffer);
            flag = 0;
            var = buffer[1];
        }
        else if (flag == 0)
        {
            buffer = splitt_token(buff, buffer);
            if (strcmp("echo", buffer[0]) == 0)
            {
                
                
                if (strncmp("$", buffer[1], 1) == 0)
                {
                    buffer[1] = getenv(var);
                }
            }
            if (strcmp("cd", buffer[0]) == 0)
            {
                change_dir(buffer[1]);
            }
            else
            {
                exec_fork(buffer);
            }
        }
    }
    return buff;
}

char **put_env(char *cmd, char **totalcommand)
{
    int i = 0;
    char *token = strtok(cmd, "=");
    while (token != NULL)
    {
        totalcommand[i] = token;
        i++;
        token = strtok(NULL, "");
    }
    totalcommand[i] = NULL;
  

 

    if (setenv(totalcommand[0], totalcommand[1], 1) == -1)
    {
        printf("error");
    }
    return totalcommand;
}

char **splitt_token(char *cmd, char **fixedsize)
{
    char *fixed;
    int counter = 0;
    fixedsize = (char **)malloc(sizeof(char) * 1000);
    fixed = strtok(cmd, " ");

    while (fixed != NULL)
    {
        /* code */ 
        fixedsize[counter] = fixed;

        counter++;
        fixed = strtok(NULL, " ");
    }
    fixedsize[counter] = NULL;
    return fixedsize;
}

char **splitt_token_pipe(char *cmd, char **buffer)
{

    char *fixed;
    int counter = 0;
    buffer = (char **)malloc(sizeof(char) * 1000);

    fixed = strtok(cmd, "|");

    while (fixed != NULL)
    {
        buffer[counter] = fixed;
        printf("%s\n", buffer[counter]);
        counter++;
        fixed = strtok(NULL, "|");
    }
    buffer[counter] = NULL;
    exev_command_pipes(buffer);
    return buffer;
}


void exev_command_pipes(char **command){
    int fd[2];
    pid=fork();
    pipe(fd);
    printf("MPIKA");
    if (pid<0)
    {

        perror("NO fork problem");
        /* code */
    }
    if (pid==0)
    {
       dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
       
        if (execvp(command[0], command) < 0)
        {
            /* code */
            perror("wrong input\n");
        }
        
        /* code */
    }else{

        wait(NULL);
    }
    
    
}