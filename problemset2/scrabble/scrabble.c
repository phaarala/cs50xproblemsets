// Implement a program that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for "Player 1" and once for "Player 2". Then, depending on which player scores the most points, your program should either print "Player 1 wins!", "Player 2 wins!", or "Tie!" if the score is the same for both players. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    
}

// Prompt user for input twice
string get_user_input(string input)
{
    player1 = get_string("Player 1: ");
    printf("\n");
    player2 = get_string("Player 2: ");
}

// Calculate score for each player, then compare