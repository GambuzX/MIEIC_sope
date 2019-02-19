#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_BUFFER_SIZE = 64;

int main() {
    char cmd[MAX_BUFFER_SIZE];
    char delimiter[2] = " ";
    char ** tokens;
    char * decomp;

    int token_number;
    
    printf("Number of tokens = ");
    scanf("%d", &token_number);
    getchar();

    tokens = (char **) malloc(token_number * sizeof(char *));
    for (int i = 0; i < token_number; i++)
        tokens[i] = (char *) malloc(MAX_BUFFER_SIZE * sizeof(char));
    

    fgets(cmd, MAX_BUFFER_SIZE, stdin);

    int curr = 0;
    decomp = strtok(cmd, delimiter);
    while (decomp != NULL && curr < token_number) {
        strcpy(tokens[curr], decomp);
        curr++;
        decomp = strtok(NULL, delimiter);
    }

    for (int i = 0; i < token_number; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}