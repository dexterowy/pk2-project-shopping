

#include <stdio.h>
#include "enums.h"

void renderPrompt() {
    printf("%s", "INPUT >");
}

void renderMenu() {
    printf("%s", "============\n");
    printf("%s", "=   MENU   =\n");
    printf("%s", "============\n");
    printf("%s", "1. Lista zakupow\n");
    printf("%s", "2. Historia zakupow\n");
    printf("%s", "q. Wyjscie\n");
    renderPrompt();
}

menuOptions handleMainMenu() {
    char choice = 'n';
    
    renderMenu();
    scanf("%c", &choice );
    
    switch(choice) {
        case '1' : return shoppingList;
        case '2' : return shopingHistory;
        default: return termination;
    }
    
}

