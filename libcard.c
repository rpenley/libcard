#include "libcard.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize a typical 52 playing card deck
void initialize_deck(Card deck[52]) {
  int i = 0;
  for (int suit = HEARTS; suit <= SPADES; suit++) {
    for (int rank = TWO; rank <= ACE; rank++) {
      deck[i].rank = rank;
      deck[i].suit = suit;
      i++;
    }
  }
}

// Shuffle the deck using the Fisher-Yates shuffle algorithm
void shuffle_deck(Card deck[52]) {
  srand(time(NULL)); // Seed for randomness
  for (int i = 51; i > 0; i--) {
    int j = rand() % (i + 1); // Random index from 0 to i
    // Swap cards
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

// Print a card in a human-readable format (e.g., "Ace of Spades")
void print_card(Card card) {
  char *rank_names[] = {"2", "3",  "4", "5", "6", "7", "8",
                        "9", "10", "J", "Q", "K", "A"};
  char *suit_names[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

// Deal a hand of n cards to a player
void deal_hand(Card deck[52], Card hand[], int n) {
  for (int i = 0; i < n; i++) {
    hand[i] = draw_card(deck);
  }
}

// Draw a single card from the deck
Card draw_card(Card deck[52]) {
  for (int i = 0; i < 52; i++) {
    if (deck[i].rank != -1) { // Check if card is not discarded
      Card drawn_card = deck[i];
      deck[i].rank = -1; // Mark card as discarded (empty)
      return drawn_card;
    }
  }
  // If no cards are left, return invalid card
  return (Card){-1, -1};
}

// Discard a card (by marking its position in the deck as empty)
void discard_card(Card deck[52], int index) {
  deck[index].rank = -1; // Mark card as discarded (empty)
}

// Calculate the total value of a hand
int calculate_hand_value(Card hand[], int n) {
  int total_value = 0;
  int ace_count = 0;

  for (int i = 0; i < n; i++) {
    if (hand[i].rank >= TWO && hand[i].rank <= TEN) {
      total_value +=
          hand[i].rank +
          2; // Rank starts at TWO (0), so we add 2 to get the card value
    } else if (hand[i].rank == JACK || hand[i].rank == QUEEN ||
               hand[i].rank == KING) {
      total_value += 10; // Face cards are worth 10
    } else if (hand[i].rank == ACE) {
      total_value += 11; // Initially treat Ace as 11
      ace_count++;       // Keep track of the number of Aces
    }
  }

  // Adjust for Aces (if value goes over 21, treat Ace as 1 instead of 11)
  while (total_value > 21 && ace_count > 0) {
    total_value -= 10; // Change Ace from 11 to 1
    ace_count--;
  }

  return total_value;
}
