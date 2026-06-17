// Implement a program that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for "Player 1" and once for "Player 2". Then, depending on which player scores the most points, your program should either print "Player 1 wins!", "Player 2 wins!", or "Tie!" if the score is the same for both players. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int calculate_score(string player_input);

int main(void)
{
    // Prompt user for input from 2 players
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Use calculate_score to assign scores for both player words
    int player1_score = calculate_score(player1);
    int player2_score = calculate_score(player2);

    // Compare scores and print results
    if (player1_score == player2_score)
    {
        printf("Tie!\n");
    }
    else if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }

    else
    {
        printf("Player 2 wins!\n");
    }
    
    // Successfully runs
    return 0; 
}

// Calculate score for a provided string
int calculate_score(string player_input)
{
    // Scrabble scoring letter values sequentially from A-Z (ASCII values 65 - 90)
    int letter_values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int word_length = strlen(player_input);
    int player_score = 0; 

    // Determines player score by subtracting 65 (ASCII A value) from each provided letter
    for(int i = 0; i<word_length; i++)
    {
        player_score += player_input[i] - 65;
    }
    return player_score;
}

