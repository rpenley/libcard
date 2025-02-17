#include <stdio.h>
#include "card.h"

// Print a card in a human-readable format (e.g., "Ace of Spades")
void print_card(Card card) {
    char *rank_names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suit_names[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

// Calculate the total value of a hand
int calculate_hand_value(Card hand[], int n) {
    int total_value = 0;
    int ace_count = 0;

    for (int i = 0; i < n; i++) {
        if (hand[i].rank >= TWO && hand[i].rank <= TEN) {
            total_value += hand[i].rank + 2; // Rank starts at TWO (0), so we add 2 to get the card value
        } else if (hand[i].rank == JACK || hand[i].rank == QUEEN || hand[i].rank == KING) {
            total_value += 10; // Face cards are worth 10
        } else if (hand[i].rank == ACE) {
            total_value += 11; // Initially treat Ace as 11
            ace_count++; // Keep track of the number of Aces
        }
    }

    // Adjust for Aces (if value goes over 21, treat Ace as 1 instead of 11)
    while (total_value > 21 && ace_count > 0) {
        total_value -= 10; // Change Ace from 11 to 1
        ace_count--;
    }

    return total_value;
}

