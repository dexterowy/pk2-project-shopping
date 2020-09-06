#include <stdlib.h>
#include  <stdio.h>
#include "interface.h"
#include "enums.h"

int main(int argc, char const *argv[])
{
    menuOptions choice = handleMainMenu();
    switch(choice) {
        case shoppingList:
            printf("%s\n", "LISTA ZAKUPOW");
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
