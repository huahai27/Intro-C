#include "future.h"
#include <stdio.h>
#include <stdlib.h>

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {
  if (index >= fc->n_decks)
    {
      fc->decks = realloc(fc->decks, (index + 1) * sizeof(deck_t));
      for (size_t i = fc->n_decks; i <= index; i++)
        {
	  fc->decks[i].n_cards = 0;
	  fc->decks[i].cards = NULL;  
        }
      fc->n_decks = index + 1;
    }
  
  fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards + 1) * sizeof(card_t*));
  fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
  fc->decks[index].n_cards++;
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {
  if((fc == NULL)||(fc->n_decks == 0))
    {
      // perror(" ERROR! there is no cards in the future deck \n");
      return;
    }
  
  for (int i = 0; i < fc->n_decks; i++)
    {
      if(fc->decks[i].cards != NULL)
        {
	  for (int j = 0; j < fc->decks[i].n_cards; j++)
            {
	      fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
	      fc->decks[i].cards[j]->value = deck->cards[i]->value;
            }   
        }
    }
}
