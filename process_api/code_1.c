#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("in parent\n");
  int x = 100;

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("in child\n");
    printf("x = %d\n", x);
    x = 50;
    printf("x = %d\n", x);
  } else {
    printf("in parent\n");
    printf("x = %d\n", x);
    x = 10;
    printf("x = %d\n", x);
  }

  return 0;
}

// 1. What value is the variable in the child process?
// Answer: 100
// 2. What happens to the variable when both the child and parent change the value of x?
// Answer: Parent and child process have their own value of x
