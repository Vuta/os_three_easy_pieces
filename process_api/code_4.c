#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("in child");

    //execl("/bin/ls", ".");
    //execle("/bin/ls", "."); 
    //execlp("/bin/ls", "."); 
    char *str[] = {".", NULL};
    execv("/bin/ls", str);
  } else {
    printf("in parent\n");
  }

  return 0;
}
