#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct timeval start;
  struct timeval end;
  char buff[512];

  gettimeofday(&start, NULL);

  for(int i = 0; i <= 10000000; i++) {
    read(STDIN_FILENO, buff, 0);
  }

  gettimeofday(&end, NULL);

  printf("Start time: %ld\n", start.tv_sec);
  printf("End time: %ld\n", end.tv_sec);
  printf("Diff: %ld\n", end.tv_sec - start.tv_sec);
  
  return 0;
}
