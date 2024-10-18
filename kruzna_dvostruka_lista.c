#include "kruzna_dvostruka_lista.h"

struct node* circularInit(uint_least8_t data){
    struct node* first = (struct node*)malloc(sizeof(struct node));
    first->number = data;
    first->head = first;
    first->tail = first;
    return first;
}

struct node* addAtBeginning(struct node* node, uint_least8_t data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    assert(node != NULL);
    struct node* temp = node->head;
    newNode->number = data;
    newNode->head = temp;
    newNode->tail = node;
    temp->tail = newNode;
    node->head = newNode;
    return newNode;
}

void addAtEnd(struct node* node, uint_least8_t data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    assert(node != NULL);
    struct node* temp = node->head;
    newNode->number = data;
    newNode->tail = temp->tail;
    newNode->head = temp;
    temp->tail = newNode;
    node->head = newNode; 
}

void addAtPosition(struct node* node, uint_least8_t data, uint_least8_t position){
    assert(node != NULL);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = node;
    while (position > 1)
    {
        temp = temp->tail;
        position--;
    }
    newNode->number = data;
    newNode->head = temp->head;
    newNode->tail = temp;
    temp->head->tail = newNode;
    temp->head = newNode;
}

struct node* deleteFirst(struct node* node){
    assert(node != NULL);
    struct node* temp = node->tail;
    if (temp == node)
    {
        free(node);
        node = NULL;
        return node;
    }
    node->head->tail = temp;
    temp->head = node->head;
    free(node);

    node = NULL;
    return temp;
}

void deleteLast(struct node* node){
    assert(node != NULL);
    struct node* temp = node->head;
    if (temp == node)
    {
        free(node);
        node = NULL;
    }
    node->head = temp->head;
    temp->head->tail = node;
    free(temp);
    temp = NULL;
}

void deleteAtPosition(struct node* node, uint_least8_t position){
    assert(node != NULL);
    struct node* temp = node;
    while (position > 1)
    {
        temp = temp->tail;
        position--;
    }
    temp->head->tail = temp->tail;
    temp->tail->head = temp->head;
    free(temp);
    temp = NULL;
}

void print(struct node* node){
    struct node* pom = node;
    printf("%"PRIdLEAST8"\t",pom->number);
    while (pom != node->head)
    {
        pom = pom->tail;
        printf("%"PRIdLEAST8"\t",pom->number);
    }
        printf("\n");
}