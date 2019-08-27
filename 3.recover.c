#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *inptr = fopen("card.raw", "r");
    {
        if (inptr == NULL) {
            fprintf(stderr, "Nah bruh");
            fclose(inptr);
        }
    }
    unsigned char things[512];
    char tittles[10];
    int thong = 0;
    FILE *thang;
    int thoong = 0;
    while(fread(&things, 512, 1, inptr)) {
        if (things[0] == 0xff && things[1] == 0xd8 && things[2] == 0xff && things[3] >= 0xe) {
            thong++;
            if (thong > 1) {
                fclose(thang);
            }
            sprintf(tittles, "%d.jpg", thoong++);
            thang = fopen(tittles, "a");
        }
        if (thong > 0) {
            fwrite(&things, 512, 1, thang);
        }
    }
    fclose(thang);
    fclose(inptr);
}