#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigint(int sig) { //will execute this function instead of killing the parent process
    printf("\n");
}

int main() {
    char command[1024];
    pid_t pid;
    int status;
    
    signal(SIGINT, handle_sigint); //to not exit when user Cntrl+C  and only will exit the current shell but not the parent process 
    
    while (1) {
        printf("hello: ");
        fgets(command, 1024, stdin);

        command[strlen(command) - 1] = '\0'; // replace \n with \0
        //to exit when the user enters exit
        if (strcmp(command, "exit") == 0) {
            printf("Goodbye...\n");
            exit(0);
        }
        
        pid = fork();
		//execute the user command
        if (pid < 0) { // if fork fails
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // if fork sucessed , and we are in the child process
            execl("/bin/sh", "sh", "-c", command, (char*)NULL); // excute command
            perror("exec failed");
            exit(EXIT_FAILURE);
        } else { // fork successed, and we are at the parent proccess
            do {
                waitpid(pid, &status, WUNTRACED); //wait child proccess to end
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        if (feof(stdin)) {
            printf("Goodbye!\n");
            exit(0);
        }
    }
    return 0;
}