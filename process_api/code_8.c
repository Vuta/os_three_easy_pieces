#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("in parent\n");
  int pd[2];

  pipe(pd);
  int rc1 = fork();

  if (rc1 < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc1 == 0) {
    printf("in child 1\n");

    close(pd[0]);
    dup2(pd[1], STDOUT_FILENO);

    char str[] = "says hello world to process 2\n";
    write(pd[1], str, sizeof(str));
  } else {
    int rc2 = fork();
    if (rc2 < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc2 == 0) {
      printf("in child 2\n");

      close(pd[1]);
      dup2(pd[0], STDIN_FILENO);

      char buff[512];
      read(STDIN_FILENO, buff, 512);
      printf("%s", buff);
    } else {
      wait(&rc2);
      printf("goodbye\n");
    }
  }

  return 0;
}
