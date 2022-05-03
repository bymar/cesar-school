#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t pid;
  pid = fork();

  if (pid > 0) {
    system("ps -l");
    sleep(10);

    printf("Parent -- PID == %d\n", getpid());
    execlp("/bin/ps", "ps", "-l", NULL);

  } else {
    printf("Child -- PID == %d\n", getpid());
  }

  return 0;
}
