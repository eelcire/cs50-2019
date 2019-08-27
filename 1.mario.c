#include <cs50.h>
#include <stdio.h>
void hashes(int x, int y);
int main(void)
{
    int stairs = get_int("Choose a number 1-8\n");
    if (stairs <= 8 && stairs >= 1) {
        for (int i = 1; i <= stairs; i++) {
            for (int k = stairs; k > i; k--) {
                printf(" ");
            }
            for (int j = 1; j <= i; j++) {
                printf("#");
                
            }
            printf("  ");
            for (int k = 1; k <= i; k++) {
                printf("#");
            }
            printf("\n");
        }
    } else {
        main();
    }
}   
