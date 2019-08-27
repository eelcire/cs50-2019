#include <stdio.h>
#include <cs50.h>

int main(void) {
    int count = 0;
    float muny = get_float("Muny?\n");
    int munny = muny * 100;
    while (munny/25 >= 1) {
        munny = munny - 25;
        count++;
    }
    while (munny/10 >= 1) {
        munny = munny - 10;
        count++;
    }
    while (munny/5 >= 1) {
        munny = munny - 5;
        count++;
    }
    while (munny/1 >= 1) {
        munny = munny - 1;
        count++;
    }
    printf("%d\n", count);
}
