#include <stdio.h>
#include <time.h>

#define NUM_TERMS 2000000000

int main(void) {
  double f_pi = 0; 
  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);
  double signal = 1.0;
  for (int k = 0; k < NUM_TERMS; k++) {
    f_pi += signal / (2 * k + 1);
    signal *= -1.0;
  }
  f_pi *= 4;
  clock_gettime(CLOCK_MONOTONIC, &end);

  // Calcula o tempo de execução em segundos
  double total_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
  printf("Tempo Processo (Sequencial): %.2fs\n", total_time);
  printf("pi = %.9f\n", f_pi);

  return 0;
}

