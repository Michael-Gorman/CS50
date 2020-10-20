#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Hail Caesar!
 * A program that encrypts messages using Caesar’s cipher.
 * The program must accept a single command-line argument: a non-negative integer. (The Key)
 * It should then ask the user to input the message.
 * it should then encrypt the message and output the encrypted maessage (Ciphertext).
 * */

int check_digit(string s);

//main to accept a single command line argument, a non negative integer.
int main(int argc, string argv[])
{
    //if the user inputs too many or too few arguments, return 1 and print error message. ("./caesar" counts as one argument so argc should equal 2)
    if (argc == 2)
    {
        //Check if argument is a digit
        string s = argv[1];
        if (check_digit(s))
        {
            //Cast string argv to an int k to make it easier to deal with.
            int k = atoi(argv[1]);

            //print 'k' for troubleshooting - will be removed later.
            //printf("k: %i\n", k);

            //if k is negative, return error 1 and print a error message.
            if (k >= 0)
            {
                //Get user input message
                string t = get_string("plaintext: ");

                //encrypt message
                printf("ciphertext: ");

                //loop through message letters
                for (int i = 0, n = strlen(t); i < n; i++)
                {
                    if (isupper(t[i]))
                    {
                        //apply encrypting formula for upper (using ASCII coversion(65)
                        printf("%c", ((((t[i] + k) - 65) % 26) + 65));
                    }
                    else if (islower(t[i]))
                    {
                        //apply encrypting formula for lower (using ASCII coversion(95))
                        printf("%c", ((((t[i] + k) - 97) % 26) + 97));
                    }
                    else
                    {
                        printf("%c", t[i]);
                    }
                }
                printf("\n");
                return 0;
            }
            else
            {
                //Print error message
                printf("Error: Non positive input.\n");
                //Reurn '1' to main to exit program with error
                return 1;
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Error: Incorrect amount of arguments entered.\n");
        return 1;
    }
}


//Function to check every character in a string is a digit
int check_digit(string s)
{
    int length = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            length++;
        }
    }
    if (length == strlen(s))
    {
        return true;
    }
    else
    {
        return false;
    }
}


