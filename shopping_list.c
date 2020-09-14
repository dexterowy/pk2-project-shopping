#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "interface.h"





shopping_list_item * getShoppingListFromFile(char *filename) {
    FILE *listFile;

    int id;
    char name[250];
    shopping_list_item *pHead = NULL;
    shopping_list_item *pPrev = NULL;

    listFile = fopen(filename, "r");

    if(listFile == NULL) {
        printf("%s", "Nie udalo sie wczytac pliku");
        return NULL;
    }

    while( fgets (name, 250, listFile)!=NULL ) {
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
        strcpy(item->name, name);
        pNode->pItem = item;
        // renderShopItem(pNode->pItem);
        pPrev = pNode;
   }
    // printf("\n%d", pHead);
    fclose(listFile);
    return pHead;
}

void shoppingListHandler() {
    shopping_list_item *pShoppingListHead = getShoppingListFromFile("mockup_lista.txt");
    char choice;
    renderShoppingList(pShoppingListHead);
    while(choice != 'q') {
        scanf("%c", &choice );
        clearBuffer();
        switch(choice) {
            case 'a': 
                // Add to shopping list
                break;
            case 'd':
                // Delete from shopping list
                break;
            case 'b':
                //Mark as bought
                break;
            case 'q':
            default :
                break;             
        }
    }
    return;
}
