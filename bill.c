#include "meal.h"
#include <stdlib.h>
#include <string.h>


//Display the meal cost, tax amount, tip amount, and total bill on the screen. 

void searchMealName(PtrToMeal ptr, int selectedMeal, char *mealName) {
    ptr += selectedMeal;
    strcpy(mealName, ptr->name);
}

double searchMealCost(PtrToMeal ptr, int selectedMeal) {
    ptr += selectedMeal;
    return ptr->cost;
}

double calculateTotalBill(double tax, double tip, double mealCost) {
    return mealCost + mealCost * (tax/100) + mealCost * (tip/100);
}
