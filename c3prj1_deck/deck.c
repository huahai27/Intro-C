#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for (int i = 0; i < hand->n_cards; i++)
    {
      print_card(*(hand->cards[i]));
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i = 0; i < d->n_cards; i++)
    {
      if (d->cards[i]->suit == c.suit && d->cards[i]->value == c.value)
	{
	  return 1;
	}
    }
  return 0;
}

void shuffle(deck_t * d){
  if (d == NULL || d->n_cards == 0)
    {
      return;
    }
  for (int i = 0; i < d->n_cards; i++)
    {
      int ran = rand() % d->n_cards;
      card_t tmp;
      tmp = *(d->cards[ran]);
      *(d->cards[ran]) = *(d->cards[i]);
      *(d->cards[i]) = tmp;
    }
}

void assert_full_deck(deck_t * d) {
  card_t temp;
  for (int i = 0; i <= 51; i++)
    {
      temp = card_from_num(i);
      assert(deck_contains(d, temp) == 1);
    }
}

void add_card_to(deck_t * deck, card_t c) {
  deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(card_t*));
  deck->cards[deck->n_cards] = malloc(sizeof(card_t));
  deck->cards[deck->n_cards]->value = c.value;
  deck->cards[deck->n_cards]->suit = c.suit;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {
  card_t empty_c = {0,0};
  add_card_to(deck, empty_c);
  return deck->cards [deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t* deck_ex = malloc(sizeof(*deck_ex));
  deck_ex->cards = NULL;
  deck_ex->n_cards = 0;
  size_t cnt = 0;
  
  for (int i = 0 ; i < 52; i++)
    {
      card_t card = card_from_num(i);
      if (deck_contains(excluded_cards, card) == 0)
	{
	  deck_ex->cards = realloc(deck_ex->cards, (cnt+1) * sizeof(card_t*));
	  deck_ex->cards[cnt] = malloc(sizeof(card_t));
	  deck_ex->cards[cnt]->suit = card.suit;
	  deck_ex->cards[cnt]->value = card.value;
	  cnt++;
	}
    }
  deck_ex->n_cards = cnt;
  
  return deck_ex;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t* excluded_cards = malloc(sizeof(*excluded_cards));
  excluded_cards->n_cards = 0;
  excluded_cards->cards = NULL;
  
  for (int i = 0; i < n_hands; i++)
    {
      for (int j = 0; j < hands[i]->n_cards; j++)
	{
	  add_card_to(excluded_cards, *(hands[i]->cards[j]));
	}
    }
  
  deck_t* deck_re = make_deck_exclude(excluded_cards);
  free_deck(excluded_cards);
  return deck_re;
}

void free_deck(deck_t * deck) {
  for (int i = 0; i < deck->n_cards; i++)
    {
      free(deck->cards[i]);
    }
  free(deck->cards);
  free(deck);
}
