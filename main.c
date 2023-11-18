#include "disk.h"

int main() {
  int request[SIZE];
  srand(time(NULL));

  for (int i = 0; i < SIZE; i++) {
    int random_number = rand() % CYLINDER;
    request[i] = random_number;
    printf("%d\n", random_number);
  }

  fcfs(request, 30);
  sstf(request, 30);
  scan(request, 30);
  
  return 0;
}
