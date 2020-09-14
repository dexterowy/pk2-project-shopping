
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "enums.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void renderPrompt() {
    printf("%s", "INPUT >");
}

// MENU

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
    clearBuffer();
    
    switch(choice) {
        case '1' : return shoppingList;
        case '2' : return shopingHistory;
        case 'q' : 
        default  : return termination;
    }
    
}

// SHOPPING LIST

void renderTableHeader() {
    printf("ID\t|\tNazwa\n");
    printf("-------------------------\n");
}

void renderTableEnd() {
    printf("\n-------------------------\n");
}

void renderShopItem(shop_item* item) {
    printf("%d\t|\t%s", item->id, item->name);
}

void renderShoppingListOptions() {
    printf("\na. Dodaj do listy zakupow\n");
    printf("d. Usun z listy zakupow\n");
    printf("b. Oznacz jako zakupione\n");
    printf("q. Powrot\n");
}

void renderShoppingList(shopping_list_item *pHead) {
    shopping_list_item *pNode = pHead;
    if(pHead) {
        renderTableHeader();
        while(pNode != NULL) {
            renderShopItem(pNode->pItem);
            pNode = pNode->pNext;
        }
        renderTableEnd();
        renderShoppingListOptions();
        renderPrompt();
    }
    
}