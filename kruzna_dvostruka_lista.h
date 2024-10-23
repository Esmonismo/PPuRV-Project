#ifndef _KRUZNA_DVOSTRUKA_LISTA_
#define _KRRUZNA_DVOSTRUKA_LISTA_
/*****Potrebne biblioteke*****/
#pragma CHECK_MISRA("none")
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <stdlib.h>
#pragma CHECK_MISRA("all")
/*****Potrebni define-ovi*****/
#define MAX_LIST_SIZE 100
/*****Pragme vezane za MISRA standard*****/
#pragma CHECK_MISRA("-20.9") /*Nema svrhe primeniti jer se u postavci trazi eksplicitno da se korisit funkcije za ispis*/
#pragma CHECK_MISRA("-20.4") /*Za svaki element liste je potrebno zauzeti memoriju*/
/*****Struktura koja predstavlja jedan cvor liste*****/
struct node
{
    uint_least8_t number;
    struct node* head;
    struct node* tail;
};
/*****Funkcije koje se koriste za rad sa listom*****/
struct node* circularInit(uint_least8_t data);
struct node* addAtBeginning(struct node* bNode, uint_least8_t bData);
void addAtEnd(struct node* eNode, uint_least8_t eData);
void addAtPosition(struct node* pNode, uint_least8_t pData, uint_least8_t position);
void print(struct node* printNode);
struct node* deleteFirst(struct node* fNode);
void deleteLast(struct node* lNode);
void deleteAtPosition(struct node* dpNode, uint_least8_t dPosition);

#endif
