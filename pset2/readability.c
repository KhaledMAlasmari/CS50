#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int avgLetters(string text, int length);
int avgSentences(string text, int length);
int avgWords(string text, int length);
int main(void)
{
    // getting the text and it's length
    string text = get_string("Enter a text: ");
    int length = strlen(text);
    // calculating letters per 100 words (L) and sentences per 100 words (S)
    float L = ( (avgLetters(text,length) * 100.0 )/ avgWords(text, length) );
    float S = ( avgSentences(text, length) * 100.0 / avgWords(text, length));
    // calculating readability and print it
    int readability  =  round((0.0588 * L) - (0.296 * S) - 15.8);
    //printf("%i , %i ,%i\n", avgLetters(text,length) , avgWords(text,length), avgSentences(text,length));
    if(readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(readability < 16)
    {
        printf("Grade %i\n", readability);
    }
    else{
        printf("Grade 16+\n");
    }
}
// this function goes through text and count the letters. things that don't count as letter dosen't count (. , ! ? etc)
int avgLetters(string text, int length)
{
    int avgLetters = 0;
    for(int i = 0; i < length;i++ )
    {
        if(text[i] == ' ' || text[i] == '.' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == '-')
        {
            continue;
        }
        else
        {
            avgLetters++;
        }
    }
    return avgLetters;
}
// this function calculate how many sentences in the text. if it ends with '. ! ? ' then it's a complete sentences
int avgSentences(string text, int length)
{
    int avgSentences = 0;
    for(int i = 0; i < length; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            avgSentences++;
        }
    }
    return avgSentences;
}
// calculate how many words are there in the provided text. if there's a space after the word (32 in ACSII) then it's a word
// note: the last word dosen't have any spaces after it and for that reason I added one to the total!!!
int avgWords(string text, int length)
{
    int avgWords = 0;
    for(int i = 0;i < length; i++)
    {
        if( (int) text[i] == 32)
        {
            avgWords++;
        }
    }
    return avgWords+1;
}