#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_BUFFER_SIZE = 64;

int main() {
    char cmd[MAX_BUFFER_SIZE];
    char ** sub_cmds;
    
    char * seq_decomp;
    char seq_delimiter[2] = ";";

    char * pipe_decomp;
    char pipe_delimiter[2] = "|";

    int sub_cmd_number;
    
    printf("Number of sub_cmds = ");
    scanf("%d", &sub_cmd_number);
    getchar();

    sub_cmds = (char **) malloc(sub_cmd_number * sizeof(char *));
    for (int i = 0; i < sub_cmd_number; i++)
        sub_cmds[i] = (char *) malloc(MAX_BUFFER_SIZE * sizeof(char));
    

    fgets(cmd, MAX_BUFFER_SIZE, stdin);

    int curr = 0;
    seq_decomp = strtok(cmd, seq_delimiter);
    while (seq_decomp != NULL && curr < sub_cmd_number) {
        strcpy(sub_cmds[curr], seq_decomp);
        curr++;
        seq_decomp = strtok(NULL, seq_delimiter);
    }

    printf("Sequence commands decomposition\n");
    for (int i = 0; i < sub_cmd_number; i++) {
        printf("%s\n", sub_cmds[i]);
    }

    for (int i = 0; i < sub_cmd_number; i++) {
        strcpy(sub_cmds[i], "");
    }

    curr = 0;
    pipe_decomp = strtok(cmd, pipe_delimiter);
    while (pipe_decomp != NULL && curr < sub_cmd_number) {
        strcpy(sub_cmds[curr], pipe_decomp);
        curr++;
        pipe_decomp = strtok(NULL, pipe_delimiter);
    }

    printf("Pipeline commands decomposition\n");
    for (int i = 0; i < sub_cmd_number; i++) {
        printf("%s\n", sub_cmds[i]);
    }


    for (int i = 0; i < sub_cmd_number; i++) {
        free(sub_cmds[i]);
    }
    free(sub_cmds);

    return 0;
}