#ifndef SHOPPING_LIST
#define SHOPPING_LIST

/**
 * Funkcja obslugujaca modul listy zakupow
 * @param pHead wskaznik na wskaznik pierwszego elementu listy zakupow
 * @param pHistoryList wskaznik na wskaznik pierwszego elementu historii
 */
void shoppingListHandler(shopping_list_item **pHead, history_list_item **pHistoryList);

/**
 * Funkcja wczytujaca do programu liste zakupow z pliku
 * @param filename nazwa pliku
 * @return wskaznik na pierwszy element listy
 */
shopping_list_item * getShoppingListFromFile(char *filename);

/**
 * Funkcja zapisujaca do pliku liste zakupow
 * @param pHead wskaznik na pierwszy element listy zakupow
 * @param filename nazwa pliku
 */
void saveShoppingListIntoFile(shopping_list_item *pHead, char *filename);

/**
 * Funkcja dodajaca przedmiot na poczatek listy zakupow
 * @param pHead wskaznik na poczatek listy zakupow
 * @param pItem wskaznik na przedmiot
 * @return wskaznik na nowy poczatek listy zakupow
 */
shopping_list_item *addShopingItemToList(shopping_list_item *pHead, shop_item *pItem);

/**
 * Funkcja obslugujaca dodawanie przedmiotu do listy
 * @param pHead wskaznik na pierwszy element listy zakupow
 * @return wskaznik na nowy poczatek listy zakupow
 */
shopping_list_item *handleCreateShoppingItem(shopping_list_item *pHead);

/**
 * Funkcja usuwajaca element z listy zakupow
 * @param pHead wskaznik na poczatek listy zakupow
 * @param id identyfikator elementu
 * @return wskaznik na nowy poczatek listy zakupow
 */
shopping_list_item *removeFromShoppingList(shopping_list_item *pHead, int id);

/**
 * Funkcja obslugujaca usuwanie przedmiotu z listy zakupow
 * @param pHead wskaznik na pierwszy element listy
 * @return wskaznik na nowy poczatek listy zakupow
 */
shopping_list_item *handleRemoveFromShoppingList(shopping_list_item *pHead);

/**
 * Funkcja usuwajaca element z listy bez usuwania przedmiotu
 * @param pHead wskaznik na wskaznik poczatku listy zakupow
 * @param id identyfikator przedmiotu
 * @return wskaznik na przedmiot z usunietego elementu
 */
shop_item *detachItemFromShoppingList(shopping_list_item **pHead, int id);

/**
 * Funkcja obslugujaca oznaczanie przedmiotu jako zakupiony
 */
void handleMarkAsBought(shopping_list_item **pShoppingList, history_list_item **pHistoryList);

/**
 * Funkcja usuwajaca dynamicznie zaalokowana pamiec
 * @param pHead wskaznik na wskaznik poczatku listy zakupow
 */
void deleteShoppingList(shopping_list_item **pHead);
#endif