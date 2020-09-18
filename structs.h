#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * Struktura przedmiotu
 */
typedef struct {
    int id; ///< Identyfikator
    char name[255]; ///< Nazwa
} shop_item;

/**
 * Struktura elementu listy zakupow
 */
typedef struct shopping_list_item{
    shop_item* pItem ; ///< Wskaznik na przedmiot
    struct shopping_list_item* pNext; ///< Wskaznik na nastepny element listy
} shopping_list_item;

/**
 * Struktura daty zakupu
 */
typedef struct {
    char year[5]; ///< Rok (YYYY)
    char month[3]; ///< Miesiac (MM)
    char day[3]; ///< Dzien (DD)
} buy_date;

/**
 * Struktura elementu histori zakupow
 */
typedef struct history_list_item{
    shop_item* pItem; ///< Wskaznik na przedmiot
    buy_date* pDate; ///< Wskaznik na strukture daty zakupu
    float price; ///< Cena kupna
    struct history_list_item* pNext; ///< Wskaznik na nastepny element listy
} history_list_item;

#endif