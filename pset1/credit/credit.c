#include <cs50.h>
#include <stdio.h>
int main(void)
{


    //Ask for credit card number
    long input = get_long("Hello! Please, enter your credit card number.\n");

    //VARIABLES
    long Sum = 0;
    long Length = 0;
    bool Switch = false;

    //First Digit of every number combination
    long First = input;
    //Second Digit of AMEX
    long SecondAMEX = input;
    //Second digit of MasterCard or Visa
    long SecondMC = input;
    
    //CHECKSUM

    // This line iterate the number from right to left one by one untill the number is 0
    for (long i = input; i > 0; i /= 10)

        //For every iteration:
    {
        //Switch On
        if (Switch)
        {
            // The Sum is multiplied by two, after that it removes the last number and add the rest
            Sum = Sum + (2 * (i % 10) % 10 + 2 * (i % 10) / 10);
        }
        //Switch Off 
        else
        {
            //It sums the digit (rest) from right to left
            Sum = Sum + (i % 10);
        }
        Length++;

        //This is precisely the switch, as the no of no is yes, so !Switch + !Switch = Switch :)
        //The next iteration it changes again, Switch + !Switch = !Switch
        Switch = !Switch;
    }
    //First digit of every card (Divide by 10 until gets the first number)
    while (First >= 10)
    {
        First = First / 10;
    }

    //Second digit of AMEX = Works for 15 length numbers
    while (SecondAMEX >= 10)
    {
        SecondAMEX = (SecondAMEX / 10) % 10000000000000;
    }
    //Second digit of MasterCard or Visa = Works for 16 length numbers
    while (SecondMC >= 10)
    {
        SecondMC = (SecondMC / 10) % 100000000000000;
    }

    //Validity Check

    //Look for validity of checksum (If the result of total sum ends with 0). Case yes: Nested If to see the first digits.
    if (Sum % 10 == 0)
    {
        //American Express requirements.
        if ((Length == 15 && First == 3) && (SecondAMEX == 4 || SecondAMEX == 7))
        {
            printf("AMEX\n");
        }
        //Master Card requirements
        else if ((Length == 16 && First == 5) && (SecondMC == 1 || SecondMC == 2 || SecondMC == 3 ||
                 SecondMC == 4 || SecondMC == 5))
        {
            printf("MASTERCARD\n");
        }
        //Visa requirements
        else if ((Length == 13 && First == 4) || (Length == 16 && First == 4))
        {
            printf("VISA\n");
        }
        // Failed card requirements
        else
        {
            printf("INVALID\n");
        }
    }
    // The case of the number not passing the Checksum
    else
    {
        printf("INVALID\n");
    }

}

