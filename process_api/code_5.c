#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
    wait(NULL);
    printf("%d\n", getpid());
  } else {
    int a = wait(&rc);
    printf("%d\n", a);
    printf("%d\n", getpid());
    printf("goodbye\n");
  }

  return 0;
}

// 1. wait() returns child PID
// 2. the child process won't wait because it doesn't have any children
