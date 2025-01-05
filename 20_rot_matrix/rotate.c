#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10])
{
  char tmp[10][10];
  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  tmp[i][j] = matrix[i][j];
	}
    }

  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  matrix[j][i] = tmp[9 - i][j];
	}
    }
}
