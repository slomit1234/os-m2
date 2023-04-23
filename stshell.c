#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("\n");
}

int main() {
    char command[1024];
    pid_t pid;
    int status;
    
    signal(SIGINT, handle_sigint);
    
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        if (command[0] == '\n') {
            continue;
        }
        command[strcspn(command, "\n")] = 0; // remove trailing newline
        
        if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        }
        
        pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execl("/bin/sh", "sh", "-c", command, (char*)NULL);
            perror("exec failed");
            exit(EXIT_FAILURE);
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        if (feof(stdin)) {
            printf("Exiting...\n");
            exit(0);
        }
    }
    return 0;
}