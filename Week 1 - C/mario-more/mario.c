#include <cs50.h>
#include <stdio.h>

// Note: I decided to do the mario more and revamp the whole files with functions.
// Just to have some fun and to simplify it.

const char block_char = '#';
const char space_char = ' ';

// A reminder for the compiler
void pyramid(int height);
void blocks(int n);
void spaces(int n);

int main(void)
{
    int pyramid_height;

    do
    {
        pyramid_height = get_int("Height: ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    pyramid(pyramid_height);
}

void pyramid(int height)
{
    // For each row...
    for (int i = 0; i < height; i++)
    {
        spaces(height - (i + 1));
        blocks(i + 1);
        spaces(2);
        blocks(i + 1);

        printf("\n");
    }
}

// Create 'n' number of blocks
void blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", block_char);
    }
}

// Create 'n' number of spaces
void spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", space_char);
    }
}
