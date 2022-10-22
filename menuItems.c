#include <string.h>
#include "meal.h"

Meal MenuItems[] = 
{
    {"Salad", 9.95},
    {"Soup", 4.55},
    {"Sandwich", 13.25},
    {"Pizza", 22.35}
};
const int MenuEntries = sizeof(MenuItems)/sizeof(MenuItems[0]); 