#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("in parent\n");
  int f = open("code_2_file.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("in child\n");
    char str[] = "child text\n";
    write(f, str, sizeof(str));
    close(f);
  } else {
    printf("in parent\n");
    char str[] = "parent text\n";
    write(f, str, sizeof(str));
    close(f);
  }

  return 0;
}

// 1. Both the child and parent can access the file descriptor returned by open()
// 2. Both can write to the file concurrently.
