#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}

//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void iodata(FILE* f)
{
  char** lines = NULL;
  char* buffer = NULL;
  size_t sz = 0;
  size_t cnt = 0;

  while (getline(&buffer, &sz, f) > 0)
    {
      lines = realloc(lines, (cnt+1) * sizeof(lines));
      lines[cnt] = buffer;
      buffer = NULL;
      cnt++;
    }
  free(buffer);

  sortData(lines, cnt);
  for (int i = 0; i < cnt; i++)
    {
      printf("%s", lines[i]);
      free(lines[i]);
    }
  free(lines);
}
int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if (argc == 1)
    {
      iodata(stdin);
    }
  if (argc > 1)
    {
      int numFiles = argc - 1;
      for (int i = 0; i < numFiles; i++)
	{
	  FILE* f = fopen(argv[i+1], "r");
	  if (f == NULL)
	    {
	      fprintf(stderr, "Could not open file\n");
	      return EXIT_FAILURE;
	    }
	  iodata(f);
	  if (fclose(f) != 0)
	    {
	      fprintf(stderr, "Could not close file\n");
	      return EXIT_FAILURE;
	    }
	}
    }
  return EXIT_SUCCESS;
}
