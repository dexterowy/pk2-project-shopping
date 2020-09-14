#ifndef INTERFACE_H
#define INTERFACE_H

#include "enums.h"
#include "structs.h"

void clearBuffer();

void renderPrompt();

void renderMenu();

void renderTableHeader();

void renderTableEnd();

void renderShoppingListOptions();

void renderShopItem(shop_item* item);

void renderShoppingList(shopping_list_item *pHead);

menuOptions handleMainMenu();

#endif