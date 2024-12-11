#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_number(string key);

int main(int argc, string argv[])
{
    // Do not accept more than 1 arguments and we want only digits
    if (argv[1] == NULL || argv[2] != NULL || !is_number(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Convert argv[1] from a 'string' to an 'int'
    int key = atoi(argv[1]);

    // Prompt the user for a sentence (plain text)
    string sentence = get_string("plaintext:  ");

    printf("ciphertext: ");
    // Cypher the text sent by the user
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalpha(sentence[i]))
        {
            // Manage uppercase characters
            if (isupper(sentence[i]))
            {
                printf("%c", ((((sentence[i] - 'A') + key) % 26) + 'A'));
            }
            else
            {
                // Lowercase characters
                printf("%c", ((((sentence[i] - 'a') + key) % 26) + 'a'));
            }
        }
        else
        {
            // Print other characters
            printf("%c", sentence[i]);
        }
    }

    printf("\n");

    return 0;
}

// Check if the string has only digits
bool is_number(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    return true;
}
