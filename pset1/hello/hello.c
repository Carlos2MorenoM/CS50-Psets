#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask for user name
    string name = get_string("Hello! please, enter your name\n");
    //Print hello + name
    printf("hello, %s! \n", name);
}