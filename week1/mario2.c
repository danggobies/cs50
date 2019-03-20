#include <stdio.h>
#include <cs50.h>

int main()
{
    int h;
    do
    {
        h = get_int("Height: ");
        //print space
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h - i - 1; j++)
                printf(" ");
            //print #
            for (int k = 0; k <= i; k++)
                printf("#");
            //print 2 spaces
            printf("  ");
            //print #
            for (int k = 0; k <= i; k++)
                printf("#");
            //print end line
            printf("\n");
        }
    }while(h < 0 || h > 23);

    return 0;
}