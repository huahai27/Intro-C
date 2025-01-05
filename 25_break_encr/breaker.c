#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int decrypt(FILE* f);
int findFreAl(int *alCnt, int sizeAl);

int main(int argc, char** argv)
{
  if (argc != 2)
    {
      fprintf(stderr,"Usage: breaker inputFileName\n");
      return EXIT_FAILURE;
    }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    {
      perror("Could not open file");
      return EXIT_FAILURE;
    }

  int key = decrypt(f);

  printf("%d\n", key);

  return EXIT_SUCCESS;
}

int decrypt(FILE* f)
{
  int alCnt[27] = {0};
  int c = 0;

  while ((c = fgetc(f)) != EOF)
    {
      if (isalpha(c))
	{
	  int idx = tolower(c) - 'a';
	  alCnt[idx]++;
	}
    }

  int freal = findFreAl(alCnt, 26);
  int e = 4;
  int key = 0;

  if (freal >= 4)
    {
      key = freal - e;
    }
  else
    {
      key =  26 - (e - freal);
    }
  
  return key;
}

int findFreAl(int *alCnt, int sizeAl)
{
  int freal = alCnt[0];
  int idxAl = 0;

  for (int i = 0; i < sizeAl; i++)
    {
      if (alCnt[i] > freal)
	{
	  freal = alCnt[i];
	  idxAl = i;
	}
    }

  return idxAl;
}
   
