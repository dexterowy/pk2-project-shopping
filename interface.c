
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "interface.h"
#include "enums.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void renderPrompt() {
    printf("%s", "INPUT >");
}

void renderDate(buy_date *pDate) {
    printf("%s-%s-%s", pDate->year, pDate->month, pDate->day);
}

void renderErrorNotFound() {
    printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("Nie udalo sie znalezc pozycji o podanym id.\n");
    printf("Upewnij sie ze podane id znajduje sie na liscie.\n\n");
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
        case 'q' : return termination;
        default  : return none;
    }
    
}

// SHOPPING LIST

void renderShoppingTableHeader() {
    printf("ID\t|\tNazwa\n");
    printf("-------------------------\n");
}


void renderShoppingTableEnd() {
    printf("-------------------------\n");
}

void renderShopItem(shop_item* item) {
    printf("%d\t|\t%s\n", item->id, item->name);
}

void renderEmptyShoppingTable() {
    renderShoppingTableHeader();
    printf("BRAK POZYCJI DO WYSWIETLENIA\n");
    renderShoppingTableEnd();
    renderShoppingListOptions();
    renderPrompt();
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
        renderShoppingTableHeader();
        while(pNode != NULL) {
            renderShopItem(pNode->pItem);
            pNode = pNode->pNext;
        }
    }
    renderShoppingTableEnd();
    renderShoppingListOptions();
    renderPrompt();
}

void renderAddShoppingItemHeader() {
    printf("\n=======================\n");
    printf("Dodawanie do listy zakupow");
    printf("\n=======================\n");
    printf("Podaj nazwe produktu\n");
    renderPrompt();
}

void renderRemoveShoppingItemHeader() {
    printf("\n=======================\n");
    printf("Usuwanie z listy zakupow");
    printf("\n=======================\n");
    printf("Podaj id produktu.\n");
    renderPrompt();
}

// HISTORY LIST

void renderHistoryTableHeader() {
    printf("ID\t|\t%20s\t|\tPrice\t|\tDate\n", "Nazwa");
    printf("----------------------------------------------------------------------------\n");
}

void renderHistoryItem(history_list_item *item) {
    printf("%d\t|\t%20s\t|\t%.2f\t|\t%s-%s-%s\n", item->pItem->id, item->pItem->name, item->price, item->pDate->year, item->pDate->month, item->pDate->day);
}

void renderHistoryTableEnd() {
    printf("----------------------------------------------------------------------------\n");
}

void renderHistoryListOptions() {
    printf("d. Usun z historii zakupow\n");
    printf("s. Podlicz wydatki za miesiac\n");
    printf("q. Powrot\n");
}

void renderEmptyHistoryTable() {
    renderHistoryTableHeader();
    printf("BRAK POZYCJI DO WYSWIETLENIA\n");
    renderHistoryTableEnd();
    renderHistoryListOptions();
    renderPrompt();
}

void renderHistoryList(history_list_item *pHead) {
    renderHistoryTableHeader();
    if(pHead) {
        history_list_item *pNode = pHead;
        while(pNode != NULL) {
            renderHistoryItem(pNode);
            pNode = pNode->pNext;
        }
    }
    renderHistoryTableEnd();
    renderHistoryListOptions();
    renderPrompt();
}

void renderRemoveHistoryItemHeader() {
    printf("\n=========================\n");
    printf("Usuwanie z historii zakupow");
    printf("\n=========================\n");
    printf("Podaj id produktu.\n");
    renderPrompt();
}

// SUM EXPENESES

void renderYearAndMonthPrompt() {
    printf("Podaj miesiac w ktorym chcesz podliczyc wydatki (YYYY-MM)\n");
    renderPrompt();
}

void renderSumOfExpenese(float sum) {
    printf("\n\nW podanym miesiacu wydano: %.2f zl\n\n", sum);
}

// BUYING

void renderBuyItemHeader() {
    printf("\n====================\n");
    printf("Oznacz jako zakupiony");
    printf("\n====================\n");
    printf("Podaj id zakupionego produktu.\n");
    renderPrompt(); 
}

void renderCostPrompt() {
    printf("Podaj cene zakupionego produktu.\n");
    renderPrompt(); 
}

void renderDatePrompt() {
    printf("Podaj date zakupu (YYYY-MM-DD).\n");
    renderPrompt(); 
}