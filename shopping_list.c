#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "interface.h"
#include "helpers.h"
#include "history_list.h"

shopping_list_item * getShoppingListFromFile(char *filename) {
    FILE *listFile;

    int id;
    char name[250];
    shopping_list_item *pHead = NULL;
    shopping_list_item *pPrev = NULL;

    listFile = fopen(filename, "r");

    if(listFile == NULL) {
        printf("%s", "Nie udalo sie otworzyc pliku\n");
        return NULL;
    }

    while( fgets (name, 250, listFile)!=NULL && strlen(name)) {
        shopping_list_item *pNode = (shopping_list_item*)malloc(sizeof(shopping_list_item));
        if(pHead == NULL) {
            pHead = pPrev = pNode;
        }
        pPrev->pNext = pNode;
        pNode->pNext = NULL;
        id = atoi(name);
        fgets (name, 250, listFile);
        shop_item *item = (shop_item*)malloc(sizeof(shop_item));
        item->id = id;
        trimLine(name);
        strcpy(item->name, name);
        pNode->pItem = item;
        pPrev = pNode;
   }
    fclose(listFile);
    return pHead;
}

void saveShoppingListIntoFile(shopping_list_item *pHead, char *filename) {
    
    // Open file to write

    FILE *listFile;
    listFile = fopen(filename, "w");

    if(listFile == NULL) {
        printf("%s", "Nie udalo sie otworzyc pliku\n");
        return;
    }
    shopping_list_item *pNode = pHead;
    if(pHead) {
        while(pNode != NULL) {
            fprintf(listFile, "%d\n", pNode->pItem->id);
            fprintf(listFile, "%s\n", pNode->pItem->name);
            pNode = pNode->pNext;
        }
    }
    fclose(listFile);
    return;
}

void deleteShoppingList(shopping_list_item **pHead) {
    if(*pHead) {
        shopping_list_item *pNode = *pHead;
        shopping_list_item *pNext = (*pHead)->pNext;
        while(pNode) {
            free(pNode->pItem);
            free(pNode);
            pNode = pNext;
            if(pNode) pNext = pNode->pNext;
        }
        *pHead = NULL;
    }
}

shopping_list_item *addShopingItemToList(shopping_list_item *pHead, shop_item *pItem) {
    shopping_list_item *pNewListItem = (shopping_list_item*)malloc(sizeof(shopping_list_item));
    pNewListItem->pNext = pHead;
    pNewListItem->pItem = pItem;
    return pNewListItem;
}

shopping_list_item *removeFromShoppingList(shopping_list_item *pHead, int id) {
    if(pHead != NULL) {
        if(pHead->pItem->id == id) {
            shopping_list_item *pNewHead = pHead->pNext;
            free(pHead->pItem);
            free(pHead);
            pHead = NULL;
            return pNewHead;
        }
        shopping_list_item *pPrev = pHead;
        shopping_list_item *pNode = pHead->pNext;
        while(pNode != NULL) {
            if(pNode->pItem->id == id) {
                pPrev->pNext = pNode->pNext;
                free(pNode->pItem);
                free(pNode);
                return pHead;
            }
            pPrev = pNode;
            pNode = pPrev->pNext;
        }
        renderErrorNotFound();
        return pHead;
    }
    renderErrorNotFound();
    return pHead;
}

shop_item *detachItemFromShoppingList(shopping_list_item **pHead, int id) {
    shop_item *pItem;
    if(pHead != NULL) {
        if((*pHead)->pItem->id == id) {
            shopping_list_item *pNewHead = (*pHead)->pNext;
            pItem = (*pHead)->pItem;
            free(*pHead);
            *pHead = pNewHead;
            return pItem;
        }
        shopping_list_item *pPrev = *pHead;
        shopping_list_item *pNode = (*pHead)->pNext;
        while(pNode != NULL) {
            if(pNode->pItem->id == id) {
                pPrev->pNext = pNode->pNext;
                pItem = pNode->pItem;
                free(pNode);
                return pItem;
            }
            pPrev = pNode;
            pNode = pPrev->pNext;
        }
        renderErrorNotFound();
        return NULL;
    }
    renderErrorNotFound();
    return NULL;
}

// SHOPPING HANDLERS

shopping_list_item *handleCreateShoppingItem(shopping_list_item *pHead) {
    renderAddShoppingItemHeader();
    // Create new item
    int newId = 0;
    if(pHead) {
        newId = pHead->pItem->id + 1;
    }
    char name[250];
    fgets(name, 250, stdin);
    trimLine(name);
    if(strlen(name) == 0) {
        printf("Nazwa nie moze byc pusta\n");
        return pHead;
    }
    shop_item *pItem = (shop_item*)malloc(sizeof(shop_item));
    pItem->id = newId;
    strcpy(pItem->name, name);
    // Add new item to list
    shopping_list_item *newHead = addShopingItemToList(pHead, pItem);
    return newHead;
}

shopping_list_item *handleRemoveFromShoppingList(shopping_list_item *pHead) {
    renderRemoveShoppingItemHeader();
    int id;
    scanf("%d", &id );
    clearBuffer();
    shopping_list_item *newHead = removeFromShoppingList(pHead, id);
    return newHead;
}

void handleMarkAsBought(shopping_list_item **pShoppingList, history_list_item **pHistoryList) {
    renderBuyItemHeader();
    int id;
    scanf("%d", &id );
    clearBuffer();
    shop_item *detachedItem = detachItemFromShoppingList(pShoppingList, id);
    if(detachedItem != NULL) {
        float price;
        char date[11];
        renderCostPrompt();
        scanf("%f", &price);
        clearBuffer();
        renderDatePrompt();
        scanf("%s", date);
        clearBuffer();
        buy_date *pDate = (buy_date*)malloc(sizeof(buy_date));
        splitStringToDate(pDate, date);
        *pHistoryList = addToHistoryList(*pHistoryList, detachedItem, price, pDate);
    }
}

// MAIN SHOPPING LIST HANDLER

void shoppingListHandler(shopping_list_item **pHead, history_list_item **pHistoryList) {
    if(*pHead == NULL) {
        *pHead = getShoppingListFromFile("mockup_lista.txt");
    }
    if(*pHistoryList == NULL) {
        *pHistoryList = getHistoryListFromFile("mockup_historia.txt");
    }
    char choice = '\0';
    while(choice != 'q') {
        if(*pHead) {
            renderShoppingList(*pHead);
        }
        else {
            renderEmptyShoppingTable();
        }
        scanf("%c", &choice );
        clearBuffer();
        switch(choice) {
            case 'a': 
                // Add to shopping list
                *pHead = handleCreateShoppingItem(*pHead);
                saveShoppingListIntoFile(*pHead, "mockup_lista.txt");
                break;
            case 'd':
                // Delete from shopping list
                *pHead = handleRemoveFromShoppingList(*pHead);
                saveShoppingListIntoFile(*pHead, "mockup_lista.txt");
                break;
            case 'b':
                //Mark as bought
                handleMarkAsBought(pHead, pHistoryList);
                saveShoppingListIntoFile(*pHead, "mockup_lista.txt");
                saveHistoryListIntoFile(*pHistoryList, "mockup_historia.txt");
                break;
            case 'q':
            default :
                break;             
        }
    }
    deleteShoppingList(pHead);
    deleteHistoryList(pHistoryList);
    *pHead = NULL;
    *pHistoryList = NULL;
    return;
}
