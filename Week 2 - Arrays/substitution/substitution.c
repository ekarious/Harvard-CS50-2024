// A program that enables you to encrypt messages using a substitution cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototype
void cipher_text(string txt, string key);
bool valid_key_26(string s);
bool valid_key_alpha(string s);
bool valid_key_repeat(string s);

// Main program
int main(int argc, string argv[])
{
    // Checks two argument counts
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }

    // Key validation
    if (!valid_key_alpha(argv[1]) || !valid_key_26(argv[1]) || !valid_key_repeat(argv[1]))
    {
        return 1;
    }

    // Prompt for text
    string text = get_string("plaintext:  ");

    // Encrypts text with a key
    cipher_text(text, argv[1]);

    return 0;
}

// Checks 26 characters in the key
bool valid_key_26(string s)
{
    // Key validation
    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return false;
        }
    }

    return true;
}

// Checks non-alphabetic characters in the key
bool valid_key_alpha(string s)
{
    // Key validation
    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        if (!isalpha(s[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    return true;
}

// Checks repeated characters in the key
bool valid_key_repeat(string s)
{
    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            if (s[i] == s[j])
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }

    return true;
}

// Encrypts message
void cipher_text(string txt, string key)
{
    int offset;
    char letter;
    printf("ciphertext: ");

    for (int i = 0, length = strlen(txt); i < length; ++i)
    {
        if (isalpha(txt[i]))
        {
            // Rotate uppercase
            if (isupper(txt[i]))
            {
                // Calculate difference [i]
                offset = (txt[i] - 'A') % 26;
                letter = key[offset];
                printf("%c", toupper(letter));
            }
            // Rotate lowercase
            else
            {
                // Calculate difference for [i]
                offset = (txt[i] - 'a') % 26;
                letter = key[offset];
                printf("%c", tolower(letter));
            }
        }
        else
        {
            printf("%c", txt[i]);
        }
    }

    printf("\n");
}