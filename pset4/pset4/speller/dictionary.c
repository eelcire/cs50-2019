// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

//global dictionary counting variable and temporary node for traversal
int count = 0;
// Represents number of children for each node in a trie
//#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

// Represents a trie
node *root;

node *new_node;

bool checkunl = true;

node *getNode(void);

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //make a variables for letters
    int letter;



    // Initialize trie
    root = getNode();
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];
    memset(word, '\0', LENGTH + 1);
    rewind(file);

    node *temp;
    
    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        temp = root;

        //iterate over letters
        for (int i = 0; word[i] != '\0'; i++)
        {
            letter = word[i];
            if (letter == '\'')
            {
                letter = 123;
            }

            //create new node if children[current letter] is NULL
            if (temp->children[abs(letter - 'a')] == NULL)
            {
                temp->children[letter - 'a'] = getNode();
                temp = temp->children[letter - 'a'];

            }
            else
            {
                temp = temp->children[letter - 'a'];
            }
        }
        temp->is_word = true;
        count++;
        memset(word, '\0', LENGTH + 1);
    }

    // Close dictionary
    fclose(file);

    temp = NULL;
    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return count;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *temp = root;
    int letter;
    for (int i = 0; i < (sizeof(word) / sizeof(char)); i++)
    {
        letter = word[i];
        if (letter == '\'')
        {
            letter = 123;
        }
        letter = tolower(letter);

        if (temp->children[letter - 'a'] == NULL)
        {
            memset(temp, '\0', sizeof(node));
            return false;
        }
        temp = temp->children[letter - 'a'];
    }
    if (temp->is_word == true)
    {
        temp = NULL;
        return true;
        memset(temp, '\0', sizeof(node));
    }
    else
    {
        temp = NULL;
        return false;
        memset(temp, '\0', sizeof(node));
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *temp;
    if (checkunl == true)
    {
        temp = root;
        checkunl = false;
    }
    for (int i = 0; i < 27; i++)
    {
        if (temp->children[i] != NULL)
        {
            temp = temp->children[i];
            unload();
            return 0;
        }
    }
    if (temp != root)
    {
        free(temp);
        checkunl = true;
    }
    if (temp == root)
    {
        free(temp);
        return true;
    }
    return false;
}

node *getNode(void)
{
    node *pNode = NULL;

    pNode = (node *)calloc(1, sizeof(node));

    if (pNode == NULL)
    {
        return false;
    }

    pNode->is_word = false;
    for (int i = 0; i < 27; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}