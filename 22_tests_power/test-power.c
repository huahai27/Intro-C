#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main() {
  unsigned x;
  unsigned y;
  unsigned ans;

  x = 2;
  y = 0;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }
  x = 1;
  y = 0;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 1;
  y = 1;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 2;
  y = 1;
  ans = 2;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 2;
  y = 3;
  ans = 8;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 3;
  y = 3;
  ans = 27;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 1;
  y = 3;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 0;
  y = 0;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 3;
  y = 2;
  ans = 9;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = -3;
  y = 2;
  ans = 9;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = -2;
  y = 3;
  ans = -8;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
