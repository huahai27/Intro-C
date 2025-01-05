#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t* hand = malloc(sizeof(*hand));
  hand->cards = NULL;
  hand->n_cards = 0;
  
  const char* delim = " ";
  char* input = strdup(str);
  char* word = strtok(input, delim);
  
  while (word != NULL)
    {
      char *end = word + strlen(word) - 1;
      if (*end == '\n') 
        {
	  *end = '\0';
        }
      
      if (word[0] == '?')
	{
	  card_t* empty = add_empty_card(hand);
	  const char* idx = word + 1;
	  size_t index = 0;
	  while (isdigit((unsigned char)*idx))
	    {
	      index = index * 10 + (*idx - '0');
	      idx++;
	    }
	  add_future_card(fc, index, empty);
	  word = strtok(NULL, delim);
	  continue;
	}
      if (strlen(word) == 2)
	{
	  char val = word[0];
	  char suit = word[1];
	  card_t card = card_from_letters(val, suit);
	  add_card_to(hand, card);
	}
      word = strtok(NULL, delim);
      
    }
  
  if (hand->n_cards < 5)
    {
      free_deck(hand);
      fprintf(stderr, "Error: A hand must contain at least 5 cards\n");
      hand = NULL;
    }
  
  free(input);
  return hand;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  if (f == NULL || fc == NULL) 
    {
      fprintf(stderr, "Error: Null pointer passed to read_input\n");
      exit(EXIT_FAILURE);
    }
  
  deck_t** input = malloc(sizeof(deck_t*));
  *(n_hands) = 0;
  char* buffer = NULL;
  size_t sz = 0;
  
  while (getline(&buffer, &sz, f) >= 0)
    {
      input = realloc(input, (*n_hands + 1) * sizeof(deck_t*));
      input[*n_hands] = hand_from_string(buffer, fc);
      (*n_hands)++;
    }
  
  free(buffer);
  return input;
}
