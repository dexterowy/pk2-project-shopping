#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "interface.h"
#include "helpers.h"

void splitStringToDate(buy_date *pDate, char *line) {
    char *lineCpy = strdup(line);
    strcpy(pDate->year, strsep(&lineCpy, "-"));
    strcpy(pDate->month, strsep(&lineCpy, "-"));
    trimLine(lineCpy);
    strcpy(pDate->day, strsep(&lineCpy, "-"));
}

void splitStringToYearAndMonth(char *year, char *month, char*line) {
    char *lineCpy = strdup(line);
    strcpy(year, strsep(&lineCpy, "-"));
    strcpy(month, strsep(&lineCpy, "-"));
}

history_list_item * getHistoryListFromFile(char *filename) {
    FILE *listFile;

    int id;
    char line[250];
    float price;
    history_list_item *pHead = NULL;
    history_list_item *pPrev = NULL;

    listFile = fopen(filename, "r");

    if(listFile == NULL) {
        // printf("%s", "Nie udalo sie wczytac pliku");
        return NULL;
    }

    while( fgets (line, 250, listFile)!=NULL ) {
        history_list_item *pNode = (history_list_item*)malloc(sizeof(history_list_item));
        if(pHead == NULL) {
            pHead = pPrev = pNode;
        }
        pPrev->pNext = pNode;
        pNode->pNext = NULL;
        id = atoi(line);
        shop_item *item = (shop_item*)malloc(sizeof(shop_item));
        item->id = id;
        fgets (line, 250, listFile);
        trimLine(line);
        strcpy(item->name, line);
        pNode->pItem = item;
        fgets (line, 250, listFile);
        price = atof(line);
        pNode->price = price;
        fgets (line, 250, listFile);
        buy_date *date = (buy_date*)malloc(sizeof(buy_date));
        splitStringToDate(date, line);
        pNode->pDate = date;
        pPrev = pNode;
   }
    // printf("\n%d", pHead);
    fclose(listFile);
    return pHead;
}

void saveHistoryListIntoFile(history_list_item *pHead, char *filename) {
    
    // Open file to write

    FILE *listFile;
    listFile = fopen(filename, "w");

    if(listFile == NULL) {
        printf("%s", "Nie udalo sie otworzyc pliku\n");
        return;
    }
    history_list_item *pNode = pHead;
    if(pHead) {
        while(pNode != NULL) {
            fprintf(listFile, "%d\n", pNode->pItem->id);
            fprintf(listFile, "%s\n", pNode->pItem->name);
            fprintf(listFile, "%.2f\n", pNode->price);
            fprintf(listFile, "%s-%s-%s\n", pNode->pDate->year, pNode->pDate->month, pNode->pDate->day);
            pNode = pNode->pNext;
        }
    }
    fclose(listFile);
    return;
}

void deleteHistoryList(history_list_item **pHead) {
    if(pHead != NULL) {
        history_list_item *pNode = *pHead;
        history_list_item *pNext = (*pHead)->pNext;
        while(pNode) {
            free(pNode->pItem);
            free(pNode->pDate);
            free(pNode);
            pNode = pNext;
            if(pNode) pNext = pNode->pNext;
        }
        *pHead = NULL;
    }
}

history_list_item *removeFromHistoryList(history_list_item *pHead, int id) {
    if(pHead != NULL) {
        if(pHead->pItem->id == id) {
            history_list_item *pNewHead = pHead->pNext;
            free(pHead->pItem);
            free(pHead->pDate);
            free(pHead);
            pHead = NULL;
            return pNewHead;
        }
        history_list_item *pPrev = pHead;
        history_list_item *pNode = pHead->pNext;
        while(pNode != NULL) {
            if(pNode->pItem->id == id) {
                pPrev->pNext = pNode->pNext;
                free(pNode->pItem);
                free(pNode->pDate);
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

history_list_item *addToHistoryList(history_list_item *pHead, shop_item *pItem, float price, buy_date *pDate) {
    history_list_item *pNewListItem = (history_list_item*)malloc(sizeof(history_list_item));
    int id = 0;
    if(pHead != NULL) {
        id = pHead->pItem->id + 1;
    }
    pNewListItem->pNext = pHead;
    pItem->id = id;
    pNewListItem->pItem = pItem;
    pNewListItem->pDate = pDate;
    pNewListItem->price = price;
    return pNewListItem;
}

float sumExpensesInMonth(history_list_item *pHead, char *month, char *year) {
    float sum = 0.0;
    if(pHead) {
        history_list_item *pNode = pHead;
        while(pNode != NULL) {
            if(strcmp(pNode->pDate->year, year) == 0 && strcmp(pNode->pDate->month, month) == 0) {
                sum += (pNode->price);
            }
                pNode = pNode->pNext;
        }
    }
    return sum;
}

history_list_item *handleRemoveFromHistoryList(history_list_item *pHead) {
    renderRemoveHistoryItemHeader();
    int id;
    scanf("%d", &id );
    clearBuffer();
    history_list_item *newHead = removeFromHistoryList(pHead, id);
    return newHead;
}

void handleSumExpensesInMonth(history_list_item *pHead) {
    char month[3];
    char year[5];
    char line[8];
    renderYearAndMonthPrompt();
    scanf("%s", line);
    clearBuffer();
    splitStringToYearAndMonth(year, month, line);
    float sum = sumExpensesInMonth(pHead, month, year);
    renderSumOfExpenese(sum);
}


void historyListHandler(history_list_item **pHead) {
    if(*pHead == NULL){
        *pHead = getHistoryListFromFile("mockup_historia.txt");
    }
    char choice = '\0';
    while(choice != 'q') {
        if(*pHead) {
            renderHistoryList(*pHead);
        }
        else {
            renderEmptyHistoryTable();
        }
        scanf("%c", &choice );
        clearBuffer();
        switch(choice) {
            case 'd':
                // Delete from history list
                *pHead = handleRemoveFromHistoryList(*pHead);
                saveHistoryListIntoFile(*pHead, "mockup_historia.txt");
                break;
            case 's':
                //Calculate sum of expeneses in month
                handleSumExpensesInMonth(*pHead);
                break;
            case 'q':
                deleteHistoryList(pHead);
                break;
            default :
                break;             
        }
    }
    return;
}