#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t* counts = malloc(sizeof(*counts));
  counts->cnts = NULL;
  counts->szCnts = 0;
  counts->numUnknowns = 0;

  return counts;  
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL)
    {
      c->numUnknowns++;
      return;
    }

  for (int i = 0; i < c->szCnts; i++)
    {
      if (strcmp(name, c->cnts[i].value) == 0)
	{
	  c->cnts[i].numVal++;
	  return;
	}
    }
  
  c->cnts = realloc(c->cnts, (c->szCnts + 1) * sizeof(one_count_t));
  c->cnts[c->szCnts].value = malloc((strlen(name) + 1) * sizeof(char));
  strcpy(c->cnts[c->szCnts].value, name);
  c->cnts[c->szCnts].numVal = 1;
  c->szCnts++;  
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c->szCnts; i++)
    {
      fprintf(outFile, "%s: %d\n", c->cnts[i].value, c->cnts[i].numVal);
    }
  if (c->numUnknowns > 0)
    {
      fprintf(outFile, "%s: %d\n", "<unknown> ", c->numUnknowns);
    }
  if (fclose(outFile) != 0)
    {
      fprintf(stderr, "Couldn't close the file!\n");
    }  
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->szCnts; i++)
    {
      free(c->cnts[i].value);
    }
  free(c->cnts);
  free(c);  
}

