#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct Text analyzeText(string text);
int calculate_index(struct Text analyzed_text);

struct Text
{
    int letters;
    int words;
    int sentences;
};

int main(void)
{
    // Get a text from a user
    string text = get_string("Text: ");

    // Count letters, words, sentences in the text
    struct Text analyzed_text = analyzeText(text);

    // Caculate the index with Coleman-Liau formula
    int grade = calculate_index(analyzed_text);

    // Print the result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

// For optimiation, we will do all calculation in one loop !
// Letters are calculated discarding the blank ones
// Words are calculated based on blank too
// Sentence ends with a dot (.)
struct Text analyzeText(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // For each letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        if (text[i] == ' ')
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // As we calculate words based on white space, we need to account for the last word.
    struct Text results = {letters, words + 1, sentences};
    return results;
}

int calculate_index(struct Text analyzed_text)
{
    float l = ((float) analyzed_text.letters / (float) analyzed_text.words) * 100;
    float s = ((float) analyzed_text.sentences / (float) analyzed_text.words) * 100;

    return round(0.0588 * l - 0.296 * s - 15.8);
}
