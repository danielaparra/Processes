// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    pid_t pid = fork();

    // Child process
    if (pid == 0) {
        printf("%d\n", x);
        x = 50;
        printf("%d\n", x);
    // Parent process
    } else {
        printf("%d\n", x);
        x = 200;
        printf("%d\n", x);
    }

    return 0;
}
