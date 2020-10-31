#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char encrypt(string text, string key);
int checkKey(string key, int argc);
int main(int argc, string argv[])
{
    string key = argv[1];
    // check if the user didn't enter any command line arguments or enterd an invalid one
    if(checkKey(key, argc) != 0)
    {
        return 1;
    }
    // get the text from the user
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    // encrypt the text with this function
    encrypt(text, key);
    return 0;
}

char encrypt(string text, string key)
{
    // get the length of the string
    int len = strlen(text);
    // a loop through the text and a loop through the key and the letters
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            // check if it's a letter ( j + 65 because upper case letters in ascii start from 65 and ends at 90)
            // check if it's a letter ( j + 65 + 32 because lower case letters in ascii start from 97 and ends at 120)
            if( (text[i] == (char) j + 65 || text[i] == (char) j + 65 + 32) )
            {
                // print the key in lower if the original letter is lower case
                if(islower(text[i]))
                {
                    printf("%c", tolower(key[j]));
                }
                // print the key in upper case if the original letter is upper case
                else
                {
                    printf("%c", toupper(key[j]));
                }
            }
            // if it's not a letter then print it as is (letters in ascii are from 65 to 90 and 97 to 120 otherwise it's something else)
            if ( (65 > text[i] || text[i] > 90 ) && (97 > text[i] || text[i] > 122 ))
            {
                printf("%c", text[i]);
                break;
            }
        }
    }
    
    printf("\n");
    return 0;
}

int checkKey(string key, int argc)
{
    // check if the user enterd one argument only
    if(argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int length = strlen(key);
    // check if the user enterd a key with less than 26 char
    if( (argc == 2 && length != 26 ))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check if the user enterd a key which has an invaild char
    for(int i = 0; i < 26; i++)
    {
        if((65 > key[i] || key[i] > 90 ) && (97 > key[i] || key[i] > 122 ))
        {
            printf("Your key is invalid. Try agian\n");
            return 1;
        }
    }
    // check if the user enterd a key that has the same char twice
    for(int j = 0; j < 26; j++)
    {
        for(int k = j+1; k < 26; k++)
        {
            if(key[j] == key[k])
            {
                printf("Your key is invalid. Try agian\n");
                return 1;
            }
        }
    }
    return 0;
}