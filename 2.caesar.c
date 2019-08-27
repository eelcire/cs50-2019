#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key < 0) {
        printf("Key must be positive\n");
        return 1;
    } else if (key > 0) {
        printf("Aite fam\n");
    } else {
        return 1;
    }
    string plaintext = get_string("Plaintext: \n");
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isupper(plaintext[i])) {
            printf("%c", (plaintext[i]-'A'+ key) % 26 + 'A');
        } else if (islower(plaintext[i])) {
            printf("%c", (plaintext[i]-'a'+ key) % 26 + 'a');
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
