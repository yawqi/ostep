#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
extern int errno;
int main() {
    if (!fork()) {
        printf("This is child %d\n", getpid());
        int ret = wait(-1);
        printf("What will happen? %d errno: %d\n", ret, errno);
    } else {
        int pid = wait(0);
        printf("This is parent %d, waitted for %d", getpid(), pid);
    }
    return 0;
}