#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  if (maxSeq(NULL, 0)) {
    return EXIT_FAILURE;
  }

  int array1[] = {1, 2, 3, 2};
  int array2[] = {2, -3, 5, 6, 8};
  int array3[] = {5};
  int array4[] = {2, 4, 3, 6, 10, 15, -1, 7, 8, 2};
  int array5[] = {-2};
  int array6[] = {2,2,2,3};

  if (maxSeq(array1, 0)) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array1, 4) != 3) {    
    return EXIT_FAILURE;
  }
  if (maxSeq(array2, 5) != 4) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array3, 1) != 1) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array4, 10) != 4) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array5, 1) != 1) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array6, 4) != 2) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
