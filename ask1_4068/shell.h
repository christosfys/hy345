char **splitt_token(char *cmd, char **fixedsize);
char **splitt_token_pipe(char *cmd, char **buffer);
pid_t pid;
char *trim_double_quotes(char *buffer);
void print_shell();
char *read_input();
void exec_fork(char **cmd);
void change_dir(char *cmd);
void stop_process(int sig);
void exev_command_pipes(char **cmd);
char **put_env(char*cmd,char **totalcommand);