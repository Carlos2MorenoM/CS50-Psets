#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//Custom function to count letters, words, and sentences.
int count_letters(string x);
int count_words(string y);
int count_sentences(string z);

int main(void)
//Readability: The program uses the Coleman-Liau index to compute the approximate level needed to comprehend the input text. (1 to 16+).

{
    //Ask user for text input
    string text = get_string("Text: ");

    //Use of count_letters, count_words, and count_sentences functions to assign them into variables.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // L = Average n° of letters for 100 words.
    float L = ((float)letters / words) * 100;
    // S = Average n° of sentences for 100 words.
    float S = ((float)sentences / words) * 100;

    // Coleman-Lieau Index = (0.0588 * Average n° of Letters - 0.296 * Average n° of Sentences - 15.8).
    float index = round(0.0588 * L - 0.296 * S - 15.8);


    //If index is between 1 and 16, print the respective grade.
    if (index > 0 && index <= 16)
    {
        printf("Grade %1.f\n", index);
    }
    else if (index <= 0)
    {
        //Index being less or equal than 0.
        printf("Before Grade 1\n");
    }
    //The only remaining case is index being greater than 16.
    else
    {
        printf("Grade 16+\n");
    }
}


//This function receives a string and returns the letters count of it.
int count_letters(string x)
{
    int letter = 0;
    //Iterate over the array
    for (int i = 0; i < strlen(x); i++)
    {
        if (islower(x[i]) || isupper(x[i]))
        {
            letter++;
        }
    }
    return letter;
}
//This function receives a string and returns the words count of it.
int count_words(string y)
{
    int word = 1;
    for (int i = 0; i < strlen(y); i++)
    {
        if (isspace(y[i]))
        {
            word++;
        }
    }
    return word;
}
//This function receives a string and returns the sentences count of it.
int count_sentences(string z)
{
    int sentence = 0;
    for (int i = 0; i < strlen(z); i++)
    {
        if (z[i] == ('.') || z[i] == ('!') || z[i] == ('?'))
        {
            sentence++;
        }
    }
    return sentence;
}

