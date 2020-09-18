#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "enums.h"
#include "structs.h"
#include "helpers.h"
#include "shopping_list.h"
#include "history_list.h"

int main(int argc, char const *argv[])
{
    menuOptions choice = '\0';
    history_list_item *pHistoryList = NULL;
    shopping_list_item *pShoppingList = NULL;
    while (choice != termination) {
        choice = handleMainMenu();
        switch(choice) {
            case shoppingList:
                shoppingListHandler(&pShoppingList, &pHistoryList);
                break;
            case shopingHistory:
                historyListHandler(&pHistoryList);
                break;
            case termination:
                break;
            default:
                printf("%s\n", "Wprowadzono nie prawidlowy znak!\n");
        }
    }
     
    return 0;
}
