#include <cs50.h>
#include <stdio.h>

// Note: I am sure there is better way to do it but this is where
// my experimentations made me go...

// A reminder for the compiler
void block(int height);

int main(void)
{
    int answer;

    do
    {
        answer = get_int("Height: ");
    }
    while (answer < 1);

    block(answer);
}

// Function to show 'blocks' in the terminal
void block(int height)
{
    const char block = '#';
    const char space = ' ';

    // For each row...
    for (int i = 0; i < height; i++)
    {
        // Manage white space
        int space_counter = height - (i + 1);
        while (space_counter > 0)
        {
            printf("%c", space);
            space_counter--;
        }

        for (int j = 0; j < (i + 1); j++)
        {
            // Print blocks
            printf("%c", block);
        }

        printf("\n");
    }
}
