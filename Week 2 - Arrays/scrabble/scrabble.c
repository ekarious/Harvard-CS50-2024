#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ALPHA_POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculateScore(string word);

int main(void)
{
    // Ask for users' words
    string player1_word = get_string("Player 1: ");
    string player2_word = get_string("Player 2: ");

    // Calutation of scores for each player
    int player1_score = calculateScore(player1_word);
    int player2_score = calculateScore(player2_word);

    // Print the winner
    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Let's calculate the score based on a word
int calculateScore(string word)
{
    int sum = 0;

    // strings are just big list of characters...
    // So we need a loop !
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // manage for Uppercase and lowercase
        if (isupper(word[i]))
        {
            sum += ALPHA_POINTS[word[i] - 'A'];
        }
        else
        {
            sum += ALPHA_POINTS[word[i] - 'a'];
        }
    }

    return sum;
}
