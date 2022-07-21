#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    int pipes[2] = {0};
    int ret = pipe(pipes);
    int c1 = fork();
    if (!c1) {
        close(pipes[0]);
        char* message = "Hello, I am child one!\n";
        write(pipes[1], message, strlen(message));
    } else {
        int c2 = fork();
        if (!c2) {
            close(pipes[1]);
            char message[100] = {0};
            int sz = read(pipes[0], message, 100);
            printf("%s", message);
        } else {
            waitpid(c1, 0, 0);
        }
        waitpid(c2, 0, 0);
    }
}