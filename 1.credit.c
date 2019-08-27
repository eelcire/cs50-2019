#include <stdio.h>
#include <cs50.h>

int main(void) {
    long input = get_long("Whas dem card numba: ");
    long number = input;
    int i1 = 0;
    int i2 = 0;
    int counter = 0;
    while (input > 0) {
        i2 = i2 + (input % 10);
        input = input / 10;
        if ((input % 10) * 2 > 9) {
            i1 = i1 + ((input % 10) * 2) % 10;
            i1 = i1 + (((input % 10) * 2)/10) % 10;
            input = input / 10;
        } else {
            i1 = i1 + (input % 10) * 2;
            input = input / 10;
        }
    }
    while (number > 99) {
        number = number / 10;
        counter++;
    }
    counter = counter + 2;
    if (((i2 + i1)%10 == 0) && (number == 34 || number == 37) && counter == 15) {
        printf("American Express\n");
    } else if (((i2 + i1)%10 == 0) && number < 56 && number > 50 && counter == 16) {
        printf("Master Card\n");
    } else if (((i2 + i1)%10 == 0) && (number < 50 || number > 39) && (counter < 17 && counter > 12)) {
        printf("Visa\n");
    } else {
        printf("Invalid\n");
    }
    printf("%d, %d\n", i1, i2);
    printf("%d\n", counter);
}
