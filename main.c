#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "enums.h"
#include "structs.h"

int main(int argc, char const *argv[])
{
    menuOptions choice = handleMainMenu();
    switch(choice) {
        case shoppingList:
            printf("%s\n", "LISTA ZAKUPOW");
            shop_item item;
            item.id = 0;
            strcpy(item.name, "Produkt testowy");
            printf("ID: %d | %s \n", item.id, item.name);
            break;
        case shopingHistory:
            printf("%s\n", "HISTORIA ZAKUPOW");
            break;
        case termination:
            printf("%s\n", "WYJSCIE");
            break;
        default:
            printf("%s\n", "Wprowadzono nie prawidlowy znak!");
    }
    return 0;
}
