#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int child_pid = fork();
    if (!child_pid) {
        printf("This is child. And I am going to close the stdout\n");
        // close(STDOUT_FILENO);
        close(1);
        printf("Anyone here?\n");
    } else {
        wait(0);
    }
}