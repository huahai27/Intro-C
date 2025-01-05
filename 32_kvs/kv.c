#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE* f = fopen(fname, "r");
  if (f == NULL)
    {
      fprintf(stderr, "Could not open file\n");
      return NULL;
    }
  
  char* buffer = NULL;
  size_t sz = 0;
  size_t i = 0;
  kvarray_t* pairs = malloc(sizeof(*pairs));
  pairs->kvarray = NULL;
  pairs->numArr = 0;
  
  while (getline(&buffer, &sz, f) >= 0)
    {
      kvpair_t* kv_curr = malloc(sizeof(*kv_curr));
      kv_curr->key = NULL;
      kv_curr->value = NULL;
      
      char* ptr_eq = strchr(buffer, '=');
      *ptr_eq = '\0';
      ptr_eq++;
      strtok(ptr_eq, "\n");

      kv_curr->key = malloc((strlen(buffer)) * sizeof(kv_curr->key));
      strcpy(kv_curr->key, buffer);
      kv_curr->value = malloc((strlen(ptr_eq)) * sizeof(kv_curr->value));
      strcpy(kv_curr->value, ptr_eq);
      
      pairs->kvarray = realloc(pairs->kvarray, (i + 1) * sizeof(kvpair_t));
      pairs->kvarray[i] = *kv_curr;
      
      free(kv_curr);
      i++;
    }
  pairs->numArr = i;
  free(buffer);
  
  if (fclose(f) != 0)
    {
      fprintf(stderr, "Could not close file\n");
      return NULL;
    }
  
  return pairs;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->numArr; i++)
    {
      free(pairs->kvarray[i].key);
      free(pairs->kvarray[i].value);
    }
  free(pairs->kvarray);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->numArr; i++)
    { 
      printf("key = '%s' value = '%s'\n", pairs->kvarray[i].key, pairs->kvarray[i].value);
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0; i < pairs->numArr; i++)
    {
      if (strcmp(pairs->kvarray[i].key, key) == 0)
	{
	  return pairs->kvarray[i].value;
	}
    }
  
  return NULL;
}
