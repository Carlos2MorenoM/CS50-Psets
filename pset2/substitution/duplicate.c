#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    int counter = 0;
    bool duplcate = false;

    string str = "aacc";
    for (int k = 0; k < strlen(str); k++)
    {
        for (int l = 0; l < strlen(str); l++)
        {
            if (str[k] == str[l])
            {
                counter++;
            }
        }
    }
    printf("%i\n", counter);
}