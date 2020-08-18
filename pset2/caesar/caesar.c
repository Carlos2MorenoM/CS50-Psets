#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //If argument count is not 2 print error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Iterate over argv[1]
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        //If argv have non digit, print error
        if (!(isdigit(argv[1][j])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //Converting argument vector [1] (the key) into an integer
    int k = atoi(argv[1]);
    //If negative number print error
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Ask user for plaintext
        string plain = get_string("Insert your plain text\n");
        //Iterate over the plaintext
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {
            //If it's lowercase, shift plaintext character by key
            if (islower(plain[i]))
            {
                //Converting ASCII to alphabetical index
                int lower = plain[i] + k;
                lower -= 97;
                //Shifting alphabetical index using formula
                lower %= 26;
                //Converting the result back to ASCII
                lower += 97;
                printf("%c", lower);
            }
            //If it's uppercase, shift plaintext character by key
            else if (isupper(plain[i]))
            {
                int upper = plain[i] + k;
                upper -= 65;
                upper %= 26;
                upper += 65;
                printf("%c", upper);
            }
            else
            {
                //If not an alphabetical character, leave the character as-is.
                printf("%c", plain[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
