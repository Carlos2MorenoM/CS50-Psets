#include <cs50.h>
#include <stdio.h>

int main(void)
int digitsback (void);
{
    int digit = get_int("Please, insert a digit\n");

    printf("Your last digit is %i\n", digitsback());
    
    int digitsback (void)
    {
        for(digit; digit % 10; digit % 10);
    }


}

