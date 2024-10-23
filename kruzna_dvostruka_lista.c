#include "kruzna_dvostruka_lista.h"

struct node* circularInit(uint_least8_t data)
{
    struct node* first = (struct node*)malloc(sizeof(struct node));
    first->number = data;
    first->head = first;
    first->tail = first;
    return first;
}

struct node* addAtBeginning(struct node* bNode, uint_least8_t bData)
{
    assert(bNode != NULL);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("No memory for element: %"PRIdLEAST8, bData);
    }
    struct node* temp = bNode->head;
    newNode->number = bData;
    newNode->head = temp;
    newNode->tail = bNode;
    temp->tail = newNode;
    bNode->head = newNode;
    return newNode;
}

void addAtEnd(struct node* eNode, uint_least8_t eData)
{
    assert(eNode != NULL);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("No memory for element: %"PRIdLEAST8, eData);
    }
    struct node* temp = eNode->head;
    newNode->number = eData;
    newNode->tail = temp->tail;
    newNode->head = temp;
    temp->tail = newNode;
    eNode->head = newNode; 
}

void addAtPosition(struct node* pNode, uint_least8_t pData, uint_least8_t position)
{
    assert(pNode != NULL);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("No memory for element: %"PRIdLEAST8, pData);
    }
    struct node* temp = pNode;
    while (position > 1)
    {
        temp = temp->tail;
        position--;
    }
    newNode->number = pData;
    newNode->head = temp->head;
    newNode->tail = temp;
    temp->head->tail = newNode;
    temp->head = newNode;
}

struct node* deleteFirst(struct node* fNode)
{
    assert(fNode != NULL);
    struct node* temp = fNode->tail;
    if (temp == fNode)
    {
        free(fNode);
        fNode = NULL;
        return fNode;
    }
    fNode->head->tail = temp;
    temp->head = fNode->head;
    free(fNode);

    fNode = NULL;
    return temp;
}

void deleteLast(struct node* lNode)
{
    assert(lNode != NULL);
    struct node* temp = lNode->head;
    if (temp == lNode)
    {
        free(lNode);
        lNode = NULL;
    }
    lNode->head = temp->head;
    temp->head->tail = lNode;
    free(temp);
    temp = NULL;
}

void deleteAtPosition(struct node* dpNode, uint_least8_t dPosition)
{
    assert(dpNode != NULL);
    struct node* temp = dpNode;
    while (dPosition > 1)
    {
        temp = temp->tail;
        dPosition--;
    }
    temp->head->tail = temp->tail;
    temp->tail->head = temp->head;
    free(temp);
    temp = NULL;
}

void print(struct node* printNode)
{
    struct node* pom = printNode;
    printf("%"PRIdLEAST8"\t",pom->number);
    while (pom != printNode->head)
    {
        pom = pom->tail;
        printf("%"PRIdLEAST8"\t",pom->number);
    }
        printf("\n");
}
