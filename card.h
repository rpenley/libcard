#ifndef CARD_H
#define CARD_H

// Enum for suits
typedef enum {
    HEARTS, DIAMONDS, CLUBS, SPADES
} Suit;

// Enum for ranks
typedef enum {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} Rank;

// Struct for a card
typedef struct {
    Rank rank;
    Suit suit;
} Card;

// Function declarations

// Print a card in a human-readable format (e.g., "Ace of Spades")
void print_card(Card card);

// Calculate the total value of a hand (for card game logic)
int calculate_hand_value(Card hand[], int n);

#endif // CARD_H

