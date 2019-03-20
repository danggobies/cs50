#include <stdio.h>
#include <cs50.h>

int main()
{
    float change;
    int cent_amount;
    int counter = 0;
    do
    {
        counter = 0;
        change = get_float("Change: ");
        cent_amount = (int)(change * 100);
        counter += cent_amount / 25;
        cent_amount %=  25;
        counter += cent_amount / 10;
        cent_amount %= 10;
        counter += cent_amount / 5;
        cent_amount %= 5;
        counter += cent_amount;

        printf("Change counter: %d\n", counter);
    }while(change <= 0);
    return 0;
}