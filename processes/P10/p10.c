// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
    char * args[] = {"ls", "-laR", argv[1], NULL};
    pid_t pid;
    int status;
    if (argc != 2 && argc != 3) {
        printf("usage: %1$s dirname\nor\nusage: %1$s dirname filename\n",argv[0]);
        exit(1);
    }

    FILE * out;
    if (argc == 3) {
        out = fopen(argv[2], "w");
    }

    pid=fork();
    if (pid > 0) {
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        wait(&status);
        printf("\nChild with pid %d terminated with EXIT CODE %d\n", pid, WEXITSTATUS(status));

        if (WIFEXITED(status)) printf("Child terminated normally\n");
        if (WIFSIGNALED(status)) printf("Child terminated anormally with SIGNAL %d\n", WTERMSIG(status));
    }
    else if (pid == 0){

        if (argc == 3) dup2(fileno(out), STDOUT_FILENO);

        execve("/bin/ls", args, envp);
        printf("Command not executed !\n");
        exit(1);
    }

    if (argc == 3) {
        fclose(out);
    }
    exit(0);
} 