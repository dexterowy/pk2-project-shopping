#ifndef HISTORY_LIST
#define HISTORY_LIST

#include "structs.h"

/**
 * Funkcja separujaca date w formacie YYYY-MM-DD na rok, miesiac i dzien
 * @param pDate wskaznik na strukture daty zakupu
 * @param line wskaznik na poczatek napisu zawierajacego date
 */

void splitStringToDate(buy_date *pDate, char *line);
/**
 * Funkcja separujaca date w formacie YYYY-MM na rok i miesiac
 * @param year wskaznik na poczatek napisu do ktorego bedzie wpisany rok
 * @param month wskaznik na poczatek napisu do ktorego bedzie wpisany miesiac
 * @param line wskaznik na poczatek napisu zawierajacego date
 */
void splitStringToYearAndMonth(char *year, char *month, char*line);

/**
 * Funkcja wczytujaca do programu historie zakupow z pliku
 * @param filename nazwa pliku
 * @return wskaznik na poczatek listy histori zakupow
 */
history_list_item * getHistoryListFromFile(char *filename);

/**
 * Funkcja zapisujaca liste historii zakupow do pliku
 * @param pHead wskaznik na poczatek listy historii zakupow
 * @param filename nazwa pliku
 */
void saveHistoryListIntoFile(history_list_item *pHead, char *filename);

/**
 * Funkcja usuwajaca dynamicznie zaalokowana pamiec historii zakupow
 * @param pHead wskaznik na wskaznik poczatku listy historii zakupow
 */
void deleteHistoryList(history_list_item **pHead);

/**
 * Funkcja usuwajaca element z listy historii zakupow
 * @param pHead wskaznik na poczatek listy zakupow
 * @param id identyfiaktor zakupu
 * @return wskaznik na poczatek listy lub null jesli lista jest pusta
 */
history_list_item *removeFromHistoryList(history_list_item *pHead, int id);

/**
 * Funkcja dodajaca element na pocztek listy historii zakupow
 * @param pHead wskaznik na poczatek listy historii zakupow
 * @param pItem wskaznik na przedmiot ktory zostanie dodany
 * @param price cena zakupu
 * @param pDate wskaznik na strukture daty zakupu
 * @return wskaznik na nowy poczatek listy historii zakupow
 */
history_list_item *addToHistoryList(history_list_item *pHead, shop_item *pItem, float price, buy_date *pDate);

/**
 * Funkcja obslugujaca usuwanie elementow z listy historii zakupow
 * @param pHead wskanznik na poczatek listy historii zakupow
 * @return wskaznik na nowy poczatek listy historii zakupow
 */
history_list_item *handleRemoveFromHistoryList(history_list_item *pHead);

/**
 * Funkcja obslugujaca wyswietlenie listy historii zakupow
 * @param pHead wskaznik na wskaznik poczateu listy historii zakupow
 */
void historyListHandler(history_list_item **pHead);

/**
 * Funkcja sumujaca wydatki w danym miesiacu
 * @param pHead wskaznik na poczatek listy historii zakupow
 * @param month wskaznik na napis zawierajacy miesiac
 * @param year wskaznik na napis zawierajacy rok
 * @return suma wydatkow w podanym miesiacu
 */
float sumExpensesInMonth(history_list_item *pHead, char *month, char *year);

/**
 * Funkcja osblugujaca sumowanie wydatkow w miesiacu
 * @param pHead wskaznik na poczatek listy historii zakupow
 */
void handleSumExpensesInMonth(history_list_item *pHead);

#endif