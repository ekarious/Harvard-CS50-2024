#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Try something new but to do what I want I will need tuple or pointers...
// So cannot for now.

// For the compiler
bool validateChecksum(long input);
void validateCards(long input);

int main(void)
{
    printf("Welcome to the Credit / Debit card validator !\n");
    printf("Please, only enter numbers without anything else.\n");

    long card_number = get_long("Card number: ");
    int card_length, bool isChecksumValid = validateChecksum(card_number);

    // Verify the checksum
    if (isChecksumValid)
    {
        validateCards(card_number, card_length);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Valide the checksum of a card.
// also save the length of the card number.
bool validateChecksum(long input)
{
    int sum = 0;
    int sum_even = 0;
    int sum_odd = 0;
    int i = 0; // Use to check if we are in an odd or even position (and for length)

    // We will cut the number every loop at the end.
    while (input != 0)
    {
        int digit = input % 10;
        i++;

        // If even number.
        if (i % 2 == 0)
        {
            // Let's multiply it by 2.
            int even = digit * 2;

            // Iterate on the even numbers.
            int j = 0;
            while (even != 0)
            {
                j++;
                sum_even += even % 10;
                even /= 10;
            }
        }
        else
        {
            sum_odd += digit;
        }

        input /= 10;
    }

    card_length = i;

    sum = sum_even + sum_odd;
    return card_length, sum % 10 == 0;
}

// Validate and print the type of card.
// usage of pow from the math.h lib.
void validateCards(long input)
{
    if (card_length != 13 && card_length != 15 && card_length != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        if (card_length == 16)
        {
            if (card_number / (long) (pow(10, card_length - 2)) >= 51 &&
                card_number / (long) (pow(10, card_length - 2)) <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (card_number / (long) (pow(10, card_length - 1)) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        if (card_length == 15)
        {
            if (card_number / (long) (pow(10, card_length - 2)) == 34 ||
                card_number / (long) (pow(10, card_length - 2)) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        if (card_length == 13)
        {
            if (card_number / (long) (pow(10, card_length - 1)) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
