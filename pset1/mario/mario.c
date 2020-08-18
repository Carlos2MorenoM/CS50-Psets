#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        //Ask fot user input
        n = get_int("Heigh: ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        //First inside loop
        for (int j = 0; j < n; j++)
        {
            // Delete one hash each iteration
            if (i + j < n - 1)
            {
                printf(" ");
            }

            //remove the remaining hashes
            else
            {
                printf("#");
            }
        }

        //add one line
        printf("\n");
    }

}