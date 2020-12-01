// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000000;
//initialise postive hash value using unsigned int
unsigned int hash_value;
//initialise positve hash table word count
unsigned int word_count;
// Hash table
node *table[N];

//------------------------------------------------------------------------------------------------------------------

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash the word to get the hash value
    hash_value = hash(word);
    // Acces the linked list
    node *pointer = table[hash_value];

    // Cycle through linked list
    while (pointer != NULL)
    {
        // Check if the word matches
        if (strcasecmp(word, pointer->word) == 0)
        {
            return true;
        }

        //Move pointer to next node
        pointer = pointer->next;

    }

    return false;
}

//------------------------------------------------------------------------------------------------------------------

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Using djb2 algorithm
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c;   /*hash * 33 + c */
    }
    return hash % N;
}

//------------------------------------------------------------------------------------------------------------------

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open File
    FILE *file = fopen(dictionary, "r");

    // If dict not loaded, return false
    if (file == NULL)
    {
        return false;
        // Main block (speller.c) will print error message
    }

    // Storage for word
    char word[LENGTH + 1];

    // Scan dictionary for words that arent the EOF (end of file)
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memorry for new node
        node *n = malloc(sizeof(node));

        // If malloc returns NULL, return false
        if (n == NULL)
        {
            return false;
            // Main block (speller.c) will print error message
        }

        // Pointer to next node and word itself
        strcpy(n->word, word);
        // Hash the word to get hash value
        hash_value = hash(word);
        // Set new pointer
        n->next = table[hash_value];
        // Set head to new pointer
        table[hash_value] = n;
        // Increment word count
        word_count++;
    }

    // Close file
    fclose(file);

    // If dictionary is loaded, return true
    return true;
}

//------------------------------------------------------------------------------------------------------------------

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Check if there are any words
    if (word_count > 0)
    {
        // Return count
        return word_count;
    }
    // Else
    return 0;
}

//------------------------------------------------------------------------------------------------------------------

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through the buckets
    for (int i = 0; i < N; i++)
    {
        // Set pointer to bucket location
        node *pointer = table[i];

        // If pointer i not NULL, free it
        while (pointer)
        {
            // Create temp
            node *tmp = pointer;
            // Move pointer to next node
            pointer = pointer->next;
            // Free up temp
            free(tmp);
        }

        // If pointer is NULL
        if (i == N - 1 && pointer == NULL)
        {
            return true;
        }
    }
    return false;
}
