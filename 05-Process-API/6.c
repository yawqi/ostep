#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
extern int errno;
int main() {
    int child = fork();
    if (!child) {
        printf("This is child %d\n", getpid());
        int ret = wait(-1);
        printf("What will happen? %d errno: %d\n", ret, errno);
    } else {
        int pid = waitpid(child, 0, 0);
        printf("This is parent %d, waitted for %d", getpid(), pid);
    }
    return 0;
}