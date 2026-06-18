// Implement a program that calculates the approximate grade level needed to comprehend some text.
// Your program should print as output “Grade X” where “X” is the grade level computed, rounded to
// the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior
// undergraduate reading level), your program should output “Grade 16+” instead of giving the exact
// index number. If the grade level is less than 1, your program should output “Before Grade 1”.

// index = 0.0588 * L - 0.296 * S - 15.8 (L = average number of letters per word and S = average
// number of sentences per 100 words

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some reading text
    string text = get_string("Please provide some text: ");

    // Initialize letter, word, and sentence variables
    int text_length = strlen(text);
    float letters = 0;
    float words = 1;
    float sentences = 0;

    for (int i = 0; i < text_length; i++)
    {
        // Count the number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Count the number of words
        else if (isblank(text[i]))
        {
            words++;
        }
        // Count the number of sentences
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Compute the Coleman-Liau Index (0.0588 * L - 0.296 * S - 15.8)
    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    printf("letters=%f words=%f sentences=%f L=%f S=%f\n", letters, words, sentences, L, S);
    float cl_index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_level = round(cl_index);

    // Print grade level to the terminal
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}
