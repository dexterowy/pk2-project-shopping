#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int id;
    char name[255];
} shop_item;

typedef struct shopping_list_item{
    shop_item* pItem ;
    struct shopping_list_item* pNext;
} shopping_list_item;

typedef struct {
    char year[4];
    char month[2];
    char day[2];
} buy_date;

typedef struct buy_price{
    float value;
    char currency [10];
} buy_price;

typedef struct history_list_item{
    shop_item* pItem;
    buy_date* pDate;
    buy_price* pPrice;
    struct history_list_item* pNext;
} history_list_item;

#endif