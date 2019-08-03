#include <stdio.h>
#include <math.h>

typedef struct {
  float x;
  float y;
} point;


void say_hello_n_times(int n) {
  for(int i = 0; i < n; i++) {
    puts("Hello world");
  }
}

int main(int argc, char* argv[]) {
  point p;
  p.x = 0.1;
  p.y = 10.0;

  float len = sqrt(p.x * p.x + p.y * p.y);
  printf("%.4f\n", len);

  puts("Start for loop");
  for(int i = 0; i < 5; i++) {
    puts("Hello world!");
  }

  puts("Start while loop");
  int tmp = 0;
  while (tmp < 5) {
    puts("Hello world!");
    tmp++;
  }

  puts("Call say_hello_n_times");
  say_hello_n_times(3);

  return 0;
}
