#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv) {
  FILE * f = fopen(argv[1], "r");
  if(f == NULL){
    fprintf(stderr, "can't open the file\n");
  }
  size_t sz = 0;
  future_cards_t * fc = malloc(sizeof(future_cards_t));
  fc->n_decks = 0;
  fc->decks = NULL;
  deck_t ** input = read_input(f, &sz, fc);
  deck_t * d = build_remaining_deck(input, sz);
  size_t n_input = sz;
  unsigned array[n_input+1];
  for(int n = 0; n < n_input+1; n++){
    array[n] = 0;
  }
  unsigned n_sim = 10000;
  if(argc == 3){
    n_sim = atoi(argv[2]);
  }
  int c;
  size_t win = 0;
  for(unsigned int m = 1; m < n_sim+1; m++){
    shuffle(d);
    future_cards_from_deck(d,fc);
    deck_t * winning = input[win];
    for(int j = 1; j < n_input; j++){
      c = compare_hands(winning,input[j]);
      if(c < 0){
	win = j;
	winning = input[win];
      }
      else if(c == 0){
	win = n_input;
      }
    }
    array[win] += 1;
    win = 0;
    /*    if(win == 4){
      print_hand(input[3]);
      printf(";");                                                                                                           print_hand(input[4]);                                                                                                  printf(";");                                                                                                           print_hand(input[5]);                                                                                                  printf("\n");                                                                                                        }*/
  }
  for(size_t x = 0; x < n_input; x++){
    double k = 100.0*array[x]/(double)n_sim;
    printf("Hand %zu won %u / %u times (%.2f%%)\n", x, array[x], n_sim, k);
  }
  printf("And there were %u ties\n", array[n_input]);
  for(int n = 0; n < n_input ; n++){
    free_deck(input[n]);
  }  
  free(input);
  for(int y = 0; y < fc->n_decks; y++){
    if(fc->decks[y].n_cards != 0){
      free(fc->decks[y].cards);
    }
  }
  free(fc->decks);
  free(fc);
  free_deck(d);
  fclose(f);
  return EXIT_SUCCESS;
}
  
    
  
