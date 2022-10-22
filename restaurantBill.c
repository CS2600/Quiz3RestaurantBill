#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *name;
    double cost;
} Meal, *PtrToMeal;
typedef const Meal *PtrToConstMeal; 

const Meal MenuItems[] = 
{
    {"Salad", 9.95},
    {"Soup", 4.55},
    {"Sandwich", 13.25},
    {"Pizza", 22.35}
};
const int MenuEntries = sizeof(MenuItems)/sizeof(MenuItems[0]); 

void getMealName(PtrToMeal ptr, int selectedMeal, char *mealName) {
    ptr += selectedMeal;
    strcpy(mealName, ptr->name);
}

double getMealCost(PtrToMeal ptr, int selectedMeal) {
    ptr += selectedMeal;
    return ptr->cost;
}

double calculateTotalBill(double tax, double tip, double mealCost) {
    return mealCost + mealCost * (tax/100) + mealCost * (tip/100);
}

int main(int argc, char *argv[]) {

    //Checks whether or not exactly 2 arguments are provided
    if(argc != 3) {
        printf("Please provide the tax and tip in this form: ie: ./a.out 7.5 10\n");
        return 1;
    }

    double tax;
    double tip;

    for(int i = 1; i < 3; i++) {
        char* end;
        double number = -1;

        number = strtod(argv[i], &end);

        //Validate input
        if(number == -1 || number < 0) {
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

    //Pick random meal
    time_t t;
    srand((unsigned)time(&t));
    int selectedMeal = rand() % MenuEntries;

    char mealName[20];

    //Get Meal Data
    getMealName(MenuItems, selectedMeal, mealName);
    double mealCost = getMealCost(MenuItems, selectedMeal);
    double totalBill = calculateTotalBill(tax, tip, mealCost);

    //Print Meal Data
    printf("Meal Name: %s\n", mealName);
    printf("Meal Cost: $%.2f\n", mealCost);
    printf("Tax: %.2f%%\n", tax);
    printf("Tip: %.2f%%\n", tip);
    printf("Total Bill: $%.2f\n", totalBill);

    return 0;
}