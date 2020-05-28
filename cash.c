#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Initializing the variables
    float dollars;
    int counter = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    do
    {
        //Ask user for a prompt
        dollars = get_float("Change owed: ");
    }
    // Do the loop untill dollars get to 0
    while (dollars < 0);
    // Convert dollars to cents
    int cents = roundf(dollars * 100);
    
    // Quarter loop
    while (cents >= quarter)
    {
        cents = cents - quarter;
        counter++;
    }
    // Dimes loop
    while (cents >= dime)
    {
        cents = cents - dime;
        counter++;
    }
    // Nickels loop
    while (cents >= nickel)
    {
        cents = cents - nickel;
        counter++;
    }
    // Pennies loop
    while (cents >= penny)
    {
        cents = cents - penny;
        counter++;
    }
    // Print the counter
    printf("%i\n", counter);
}

