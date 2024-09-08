#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digit (int n, string input);
char rotate (int a, char text);

int main (int n, string arr[])
{
    //take plain text input
    //no command line or more than one command-line argument return error message
    if (n < 2 || n > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digit(strlen(arr[1]), arr[1]))
    {
        //key check
        int a = atoi(arr[1]);
        printf("Key is: %i\n", a);

        //get the plaintext
        string text = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (int j = 0; j < strlen(text); j++)
        {
            if(isalpha(text[j]))
            {
                char ct = rotate(a, text[j]);
                printf("%c", ct);
            }
            else if(isspace(text[j]))
            {
                printf(" ");
            }
            else
            {
                printf("%c", text[j]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


bool only_digit (int n, string input)
{
    //check if the given input is digit or not
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(isdigit(input[i]))
        {
            temp++;
        }
    }
    if(temp == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char rotate (int a, char txt)
{
    //rotate the text
    //65-90 & 97-122
    int xt, temp;

    if(a >= 26 || a <= -26)
    {
        a = a % 26;
    }

    if(isupper(txt))
    {
        xt = txt + a;
        if(xt > 90)
        {
            xt = xt - 26;
        }
        return xt;
    }
    else
    {
        xt = txt + a;
        if(xt > 122)
        {
            xt = xt - 26;
        }
        return xt;
    }
}
