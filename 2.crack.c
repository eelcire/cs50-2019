#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: crack hash\n");
        return 1;
    }
    const int letter_count = 53;
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    char salt[3];
    salt[0] = hash[0];
    salt[1] = hash[1];
    char pw[5];
    for (int fifth = 0; fifth < letter_count; fifth++) {
        for (int fourth = 0; fourth < letter_count; fourth++) {
            for (int third = 0; third < letter_count; third++) {
                for (int second = 0; second < letter_count; second++) {
                    for (int first = 0; first < letter_count; first++) {
                        printf("%s\n", pw);
                        pw[0] = letters[first];
                        pw[1] = letters[second];
                        pw[2] = letters[third];
                        pw[3] = letters[fourth];
                        pw[4] = letters[fifth];
                        if (strcmp(crypt(pw, salt), hash) == 0) {
                            printf("%s\n", pw);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("No can do monsieur ;D");
}
