#ifndef INTERFACE_H
#define INTERFACE_H

#include "enums.h"
#include "structs.h"

/**
 * Funkcja czyszczaca bufor
 */
void clearBuffer();

/**
 * Funkcja wypisujaca na ekran znak zachety
 */
void renderPrompt();

/**
 * Funkcja wypisujaca na ekran blad
 * dotyczacy nie znalezienia obiektu
 */
void renderErrorNotFound();

/**
 * Funkcja wypisujaca date w formacie (YYYY-MM-DD)
 */
void renderDate(buy_date *pDate);

/**
 * Funkcja wyswietlajaca menu glowne
 */
void renderMenu();

/**
 * Funkcja wyswietlajaca naglowek tabeli
 */
void renderShoppingTableHeader();

/**
 * Funkcja wyswietlajaca znaki konca tabeli
 */
void renderShoppingTableEnd();

/**
 * Funkcja wyswietlajaca placeholder w przypadku pustej tabeli
 */
void renderEmptyShoppingTable();

/**
 * Funkcja wyswietlajaca liste opcji
 */
void renderShoppingListOptions();

/**
 * Funkcja wypisujaca obiekt z listy zakupow
 * @param item wskaznik na strukture przedmiotu 
 */
void renderShopItem(shop_item* item);

/**
 * Funkcja wypisujaca wszystkie elementy listy zakupow
 * @param pHead wskaznik na poczatek listy zakupow
 */
void renderShoppingList(shopping_list_item *pHead);

/**
 * Funkcja obslugujaca menu glowne
 * @return Zwraca enum bedacy wybrana opcja
 */
menuOptions handleMainMenu();

/**
 * Funkcja wyswietlajaca naglowek podczas dodawania przedmiotu do listy
 */
void renderAddShoppingItemHeader();

/**
 * Funkcja wyswitlajaca naglowek podczas usuwania przedmiotu z listy
 */
void renderRemoveShoppingItemHeader();

/**
 * Funkcja wyswietlajaca naglowek tabeli
 */
void renderHistoryTableHeader();

/**
 * Funkcja wypisujaca na ekran wpis z historii zakupow
 * @param item Wskaznik na wpis z historii
 */
void renderHistoryItem(history_list_item *item);

/**
 * Funkcja wypisujaca znaki konca tabeli
 */
void renderHistoryTableEnd();

/**
 * Funkcja wyswietlajaca placeholder w przypadku pustej historii
 */
void renderEmptyHistoryTable();

/**
 * Funkcja wyswietlajaca liste opcji
 */
void renderHistoryListOptions();

/**
 * Funkcja wyswietlajaca historie
 * @param pHead Wskaznik na poczatek listy
 */
void renderHistoryList(history_list_item *pHead) ;

/**
 * Funkcja wyswitlajaca naglowek podczas usuwania przedmiotu z listy
 */
void renderRemoveHistoryItemHeader();

// SUM EXPENSES
/**
 * Funkcja wyswietlajaca zapytanie o rok i miesiac
 */
void renderYearAndMonthPrompt();

/**
 * Funkcja wypisujaca sume wydatkow w danym miesiacu
 * @param sum Suma wydatkow
 */
void renderSumOfExpenese(float sum);

// BUYING
/**
 * Funkcja wypisujaca naglowek podczas oznaczania przedmiotu jako kupiony
 */
void renderBuyItemHeader();

/**
 * Funkcja wypisujaca zapytanie o koszt kupowanego przedmiotu
 */
void renderCostPrompt();

/**
 * Funkcja wypisujaca zapytanie o date kupna przedmiotu
 */
void renderDatePrompt();

#endif