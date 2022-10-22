#include "meal.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

    extern const Meal MenuItems[];
    extern const int MenuEntries;

    void searchMealName(const Meal table[], int numEntries, char* name);
    double searchMealCost(const Meal table[], int numEntries);
    double calculateTotalBill(double tax, double tip, double mealCost);

    time_t t;

    srand((unsigned)time(&t));

    int selectedMeal = rand() % MenuEntries;
    char mealName[20];

    searchMealName(MenuItems, selectedMeal, mealName);
    double mealCost = searchMealCost(MenuItems, selectedMeal);
    double totalBill = calculateTotalBill(tax, tip, mealCost);

    printf("mealName: %s\n", mealName);
    printf("Meal Cost: $%.2f\n", mealCost);
    printf("Tax: %.2f%%\n", tax);
    printf("Tip: %.2f%%\n", tip);
    printf("Total Bill: $%.2f\n", totalBill);
    //PtrToMeal temp;

    return 0;
}