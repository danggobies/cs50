#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const int letters_count = 53;

    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_candidate[6] = "\0\0\0\0\0\0";

    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {
                    for (int first = 0; first < letters_count; first++)
                    {
                        key_candidate[0] = letters[first];
                        key_candidate[1] = letters[second];
                        key_candidate[2] = letters[third];
                        key_candidate[3] = letters[fourth];
                        key_candidate[4] = letters[fifth];
                        if (strcmp(crypt(key_candidate, salt), hash) == 0)
                        {
                            printf("%s\n", key_candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}