#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_alpha(string key);
bool repeatation(string key);
string cipher_text(string key, string text);

int main (int n, string arr[])
{
    //check for the argument
    if(n != 2)
    {
        printf("Error: Only single command line acceptable!\n");
        return 1;
    }
    else
    {
        //check for the 26 characters in argument and check for repeatation
        int l = strlen(arr[1]);
        if(l == 26)
        {
            // check for other than alphabets
            if(check_alpha(arr[1]))
            {
                //check for repeatation
                if(repeatation(arr[1]))
                   {
                        printf("Error: alphabets cannot be repeated!");
                        return 1;
                   }
                   else
                   {
                        // main body operation
                        //printf("Key is accpeted!\n");
                        string plaintext = get_string("plaintext: ");
                        string ciphertext = cipher_text(arr[1], plaintext);
                        printf("ciphertext: %s\n", ciphertext);

                        return 0;
                   }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            printf("Error: 26 characters are required!\n");
            return 1;
        }
    }
}

bool check_alpha(string key)
{
    for(int i = 0; i < 26; i++)
            {
                if(isalpha(key[i]))
                {
                    //
                }
                else
                {
                    printf("Error: Only alphabets are allowed!");
                    return false;
                }
            }
    return true;
}

bool repeatation(string key)
{
    //check alphabets repeatation
    for(int a = 0; a < 26; a++)
    {
        for(int b = a+1; b < 26; b++)
        {
            if( key[a]==key[b] )
            {
                return true;
            }
        }
    }
    return false;
}

string cipher_text(string key, string text)
{
    //rotate text
    for(int x = 0; x < strlen(text); x++)
    {
        if(isalpha(text[x]))
        {
            //map and rotate
            if(islower(text[x]))
            {
                int y = text[x] - 97;
                if (islower(key[y]))
                {
                    text[x] = key[y];
                }
                else
                {
                    text[x] = key[y] + 32;
                }
            }
            else
            {
                int y = text[x] - 65;
                if(islower(key[y]))
                {
                    text[x] = key[y] - 32;
                }
                else
                {
                    text[x] = key[y];
                }
            }
        }
        else
        {
            text[x] = text[x];
        }
    }

    return text;
}
