#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int count_letters(string x);
bool set_duplicate(string y);

int main(int argc, string argv[])
{
    //If argument count is not 2 print error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    //Checking for non-alphabetic characters
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        //If argv have non alphabetic characters print error
        if (!isalpha((argv[1][j])))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // Custom function to count letters in argv[1]
    int argvletters = count_letters(argv[1]);
    if (argvletters != 26)
    {
        //print error if count isn't 26
        printf("Key must contain 26 characters\n");
        return 1;
    }

    else
    {
        //Checking for duplicate characters using the custom function written below
        bool duplicate_chars = set_duplicate(argv[1]);

        //Print error if there are duplicated characters
        if (duplicate_chars == true)
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }



        //Now I'll keep going with the code...

        else
        {
            //Ask user for plaintext
            string plain = get_string("Insert your plain text\n");
            //Asign argv[1] to variable key, so it's better readable.
            string key = (argv[1]);

            printf("ciphertext: ");
            //Iterate over plain text
            for (int i = 0; i < strlen(plain); i++)
            {
                //Lower case:
                if (islower(plain[i]))
                {
                    //Modulo of 97 because of the ASCII representation of the first lowercase.
                    int lower = plain[i] % 97;
                    printf("%c", tolower(key[lower]));
                }
                //Upper case:
                else if (isupper(plain[i]))
                {
                    //Modulo of 65 because of the ASCII representation of the firs uppercase.
                    int upper = plain[i] % 65;
                    printf("%c", toupper(key[upper]));
                }
                //Special characters case: (leave the character as is)
                else
                {
                    printf("%c", plain[i]);
                }


            }
            //zyxwvutsrqponmlkjihgfedcba
            //abcdefghijklmnopqrstuvwxyz

            //./substitution zyxwvutsrqponmlkjihgfedcba


            printf("\n");
            return 0;
        }
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



//This function return a boolean value of true if there are duplicate chars in an array.
bool set_duplicate(string y)
{
    int counter = 0;
    bool duplicate = false;

    //Iterate over the array
    for (int k = 0; k < strlen(y); k++)
    {
        //Iterate over every iteration, just like mario.
        for (int l = 0; l < strlen(y); l++)
        {
            //add each pair of characters (k and l) to counter. There should be 26 in total.
            //for each duplicate character, it multiply for 2 because of the loop.
            if (y[k] == y[l])
            {
                counter++;
            }

        }
    }
    // If there are more than 26, means that duplicate characters exists.
    if (counter != 26)
    {
        duplicate = true;
    }
    return duplicate;

}





