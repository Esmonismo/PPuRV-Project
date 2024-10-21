#ifndef _KRUZNA_DVOSTRUKA_LISTA_
#define _KRRUZNA_DVOSTRUKA_LISTA_
/*****Potrebne biblioteke*****/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <stdlib.h>
/*****Potrebni define-ovi*****/
#define MAX_LIST_SIZE 100
/*****Pragme vezane za MISRA standard*****/
#pragma CHECK_MISRA("-5.4") /*Nema svrhe primeniti u ovom zadatku*/
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
struct node* addAtBeginning(struct node* node, uint_least8_t data);
void addAtEnd(struct node* node, uint_least8_t data);
void addAtPosition(struct node* node, uint_least8_t data, uint_least8_t position);
void print(struct node* node);
struct node* deleteFirst(struct node* node);
void deleteLast(struct node* node);
void deleteAtPosition(struct node* node, uint_least8_t position);

#endif