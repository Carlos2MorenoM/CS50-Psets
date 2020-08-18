#include <stdio.h>
#include <cs50.h>

int main(void)
{


    //Ask for credit card number
    long input = get_long("Hello! Please, enter your credit card number.\n");


    //Defining the variable to take second to last nunmber
    long SecondToLast = input;
    while(SecondToLast >= 10)
    {
        SecondToLast = (SecondToLast / 10) % 10000000000
        for (ReversedList=0)

    }
    printf("%li\n", SecondToLast);


}
4111111111111111
381449635398441
371449635398431
1234567891234

1234567891234567

1234567891234567

    //Ask for credit card number
    long input = get_long("Hello! Please, enter your credit card number.\n");



    //Defining the variable to take the first number
    long firstN = input;
    while(firstN >= 10)
    {
        firstN = firstN / 10;
    }

    //Defining the variable to take the second number
    long secondN = input;
    while(secondN >=10)
    {
        secondN = (secondN / 10) % 10000000000000;
    }

    //American Express card type
    char AmericanExpress = input;


    if(firstN == 3 && secondN == 4)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if(firstN == 3 && secondN == 7)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else
        printf("Invalid card number\n");

    printf("%li\n",firstN);
    printf("%li\n",secondN);

}

    //American Express card type
    char AmericanExpress = input;


    if(digit1 == 3 && digit2 == 4)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if(digit1 == 3 && digit2 == 7)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else
        printf("Invalid card number\n");






    //Taking every digit and storing them in each variable
    long digit1 = input;
    int digit1x2 = digit1;
    long SumOfDigits;
    int digit2 =0;

    bool Double = 0;
    for (long i = input; i > 0; i = i / 10 )
    {
        if (!Double)
        {
        SumOfDigits = (i %10) + SumOfDigits;
        }
        else
        SumOfDigits += (2* (i%10) % 10 + 2 * (i%10) / 10);

    }

    printf("%li\n",SumOfDigits);




(i %10) + SumOfDigits; SumOfDigits += (2* (i%10) % 10 + 2 * (i%10) / 10) )


(i %10) + SumOfDigits

for (long i = input; i > 0; i = (i / 10) % 10 )



       if (SecondAMEX == 4 && SecondAMEX == 7)
            {
                printf("AMEX");
            }
