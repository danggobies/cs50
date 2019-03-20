#include <stdio.h>
#include <cs50.h>

int main()
{
    long long number;
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    int counter = 0;
    int remain = 0;
    int remainMulti = 0;

    do
    {
        number = get_long_long("Number: ");
        printf("Number: %llu", number);
        while(number > 0)
        {
            remain = number % 10;
            number /= 10;
            counter++;
            if (counter % 2 == 0)
            {
                remainMulti = remain *2;
                while (remainMulti > 0)
                {
                    sum1 += remainMulti % 10;
                    remainMulti /= 10;
                }
            }
            else
                sum2 += remain;
        }

        printf("Sum1: %d\n", sum1);
        printf("Sum2: %d\n", sum2);

        sum = sum1 + sum2;
        printf("Sum: %d", sum);
        if (sum % 10 == 0)
            switch(remain)
            {
                case 3:
                printf("AMEX\n");
                break;
                case 5:
                printf("MASTER\n");
                break;
                case 4:
                printf("VISA\n");
                break;
            }
    }while(number <= 0);
    return 0;
}