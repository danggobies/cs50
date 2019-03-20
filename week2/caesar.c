#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("You enter miss parameter\n");
        return 1;
    }
    int key = atoi(argv[1]);

    if (key < 0)
    {
        printf("Key isn't negative\n");
        return 1;
    }

    //get plaintext
    string plaintext = get_string("Enter plaintext: ");
    int length = strlen(plaintext);
    char enciphtext[length];

    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {

        if (islower(plaintext[i]))
        {
            enciphtext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else if (isupper(plaintext[i]))
        {
            enciphtext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else
        {
            enciphtext[i] = plaintext[i];
        }

        printf("%c", enciphtext[i]);
    }
    printf("\n");

    return 0;
}