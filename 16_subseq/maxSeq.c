#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n == 0) {
    return 0;
  }
  size_t longest_streak_length = 1;
  size_t running_streak_length = 1;
  int temp = array[0];

  for (size_t i = 1; i < n; i++) {
    if (array[i] > temp) {
      running_streak_length++;
      if (running_streak_length > longest_streak_length) {
	longest_streak_length = running_streak_length;
      }
    } else {
      running_streak_length = 1;
    }
    temp = array[i];
  }
  return longest_streak_length;
  
}
