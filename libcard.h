#ifndef LIBCARD_H
#define LIBCARD_H

// Define macros and constants
#define MAX_BUFFER_SIZE 1024

// Enum for suits
typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } Suit;

// Enum for ranks
typedef enum {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
} Rank;

// Struct for a card
typedef struct {
  Rank rank;
  Suit suit;
} Card;

// Function declarations

// Initialize a new deck of 52 cards
void initialize_deck(Card deck[52]);

// Shuffle the deck using a simple algorithm
void shuffle_deck(Card deck[52]);

// Draw a single card from the deck
Card draw_card(Card deck[52]);

// Discard a card by marking it as "empty"
void discard_card(Card deck[52], int index);

// Print a card in a human-readable format (e.g., "Ace of Spades")
void print_card(Card card);

// Calculate the total value of a hand (for card game logic)
int calculate_hand_value(Card hand[], int n);

#endif // LIBCARD_H
