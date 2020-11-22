// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int fileSize = 0;
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool compare(const char *word, node *temp)
{
    while(temp != NULL)
    {
        if((strcasecmp(temp->word, word) == 0))
        {
            return true;
            break;
        }
        temp = temp -> next;
    }
    return false;
}
bool check(const char *word)
{
    int hashedWord = hash(word);
    bool equals = false;
    if(table[hashedWord] == NULL)
    {
        return equals;
    }
    equals = compare(word, table[hashedWord]);
    return equals;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int num = tolower(word[0]) - 97;
    return num;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    // the file is empty lmao
    if(file == NULL)
    {
        return 1;
    }
    char word[LENGTH+1];
    while(fscanf(file, "%s", word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if(temp == NULL)
        {
            return 1;
        }
        int hashedWord = hash(word);
        if(table[hashedWord] == NULL)
        {
            strcpy(temp->word, word);
            temp -> next = NULL;
            table[hashedWord] = temp;
            fileSize++;
            continue;
        }
        fileSize++;
        strcpy(temp->word, word);
        temp -> next = table[hashedWord] -> next;
        table[hashedWord] -> next = temp;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return fileSize;
}


void freeMemory(node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    freeMemory(temp -> next);
    free(temp);
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            freeMemory(table[i]);
        }
    }
    return true;

}
