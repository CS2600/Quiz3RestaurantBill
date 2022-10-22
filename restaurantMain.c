#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "meal.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Please provide the tax and tip in this form: ie: ./a.out 7.5 10\n");
        return 1;
    }

    double tax = -1;
    double tip = -1;

    for(int i = 1; i < 3; i++) {
        char* end;
        double number;

        number = strtod(argv[i], &end);

        if(!number || number < 0) {
            printf("Please provide valid values\n");
            return 1;
        }
        if(i == 1) {
            tax = number;
        }
        else {
            tip = number;
        }
    }
    time_t t;
    extern const int MenuEntries;

    srand((unsigned)time(&t));

    int meal = rand() % MenuEntries;

    //Display the meal cost, tax amount, tip amount, and total bill on the screen. 

    

    return 0;
}