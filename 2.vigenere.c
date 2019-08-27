#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } else {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) {
            if (!isalpha(argv[1][i])) {
                printf("Key must be alphabetic chars only.");
                return 1;
            }    
        }
    }
    string key = argv[1];
    string plaintext = get_string("Plaintext: \n");
    for (int i = 0, j = 0; i < strlen(plaintext); i++) {
        int keyletter = tolower(key[j % strlen(key)])-'a';
        if (isupper(plaintext[i])) {
            printf("%c", (plaintext[i]-'A'+ keyletter) % 26 + 'A');
            j++;
        } else if (islower(plaintext[i])) {
            printf("%c", (plaintext[i]-'a'+ keyletter) % 26 + 'a');
            j++;
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
