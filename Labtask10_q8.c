#include <stdio.h>

int main() {
    // Categories
    char categories[3][20] = {
        "Appetizers",
        "Main Course",
        "Desserts"
    };

    // Menu items (3 items per category)
    char items[3][3][30] = {
        {"Spring Rolls", "Garlic Bread", "Soup"},
        {"Grilled Chicken", "Pasta Alfredo", "Beef Burger"},
        {"Ice Cream", "Brownie", "Fruit Salad"}
    };

    // Prices of items
    float prices[3][3] = {
        {6.50, 8.00, 5.75},      // Appetizers
        {15.99, 12.50, 9.50},    // Main Course
        {4.99, 6.25, 7.00}       // Desserts
    };

    int i, j;

    // 1. Display complete menu
    printf("========= RESTAURANT MENU =========\n\n");

    for (i = 0; i < 3; i++) {
        printf("%s:\n", categories[i]);
        printf("-------------------------\n");

        for (j = 0; j < 3; j++) {
            printf("%-20s  $%.2f\n", items[i][j], prices[i][j]);
        }

        printf("\n");
    }

    // 2. Show budget-friendly items (< $10)
    printf("========= BUDGET-FRIENDLY OPTIONS (< $10) =========\n\n");

    int found = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (prices[i][j] < 10.00) {
                printf("%-20s  $%.2f  (%s)\n",
                       items[i][j], prices[i][j], categories[i]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No budget-friendly items available.\n");
    }

    return 0;
}

