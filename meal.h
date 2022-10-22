#include <stdio.h>
#include <stddef.h>

typedef struct {
    char *name;
    double cost;
} Meal, *PtrToMeal;
typedef const Meal *PtrToConstMeal; 