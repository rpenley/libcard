#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"

// Function declarations

// Start a new game of Blackjack
void start_blackjack_game();

// Print the current hand of a player or dealer
void print_hand(Card hand[], int n);

// Play the dealer's turn (dealer must hit until reaching 17)
void dealer_turn(Card deck[52], Card dealer_hand[], int *dealer_hand_size);

// Play the player's turn (player chooses to hit or stand)
void player_turn(Card deck[52], Card player_hand[], int *player_hand_size);

// Determine the winner of the game
void determine_winner(Card player_hand[], int player_hand_size, Card dealer_hand[], int dealer_hand_size);

#endif // BLACKJACK_H

