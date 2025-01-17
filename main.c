/*
 *Ime i prezime: Stefan Radovanovic
 *Index: RA 176/2021
 *Zadatak: Implementiranje dvostruko spregnute liste kroz zaseban modul sa svim potrebnim funkcionalnostima koje ukljucuju inicijalizacija prvog elementa,
 * dodavanje na bilo koju poziciju kao i brisanje sa bilo koje pozicije. 
 * Resenje: Zadatak je resen tako sto je su sve funkcionalnosti dvostruko spregnute liste izdvojeni u zaseban modul i napravljena staticka biblioteka, sa prosirenjem
 * za stampanje elemenata liste tj njihovih vrednosti.Izuzev main funkcije svi ostali tipovi su tipovi iz <stdint.h>, za vrednosti elemenata liste se uzima pretpostavka da ce se koristiti
 * celobrojne vrednosti do 255 ili znakovi poput slova iz asci tabele. Koriscena je i biblioteka <assert.h> u svrhe provere da li se pokusava dodati element u listu 
 * koja nema barem jednu vrednost odnosno koja nije "inicijalizovana". Testiranje je odradjeno sa vec unapred pripremljenim vrednostima kao i opciom da korisnik testira
 * uz koriscenje odredjenih ogranicenja i pretpostavke da ce ih korisnik postovati.
 * Sam kod je pisan po standardu iz dokumentacije i po MISRA 2004 standardu.
 */

#include "kruzna_dvostruka_lista.h"

void printAndRemoveNth(struct node** element, uint_least8_t nIter);

/*****Funcija za ispis i izbacivanje elemenata*****/
void printAndRemoveNth(struct node** element, uint_least8_t nIter)
{
    struct node* current = *element;

    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    uint_least8_t count = (uint_least8_t)1;

    while (current != current->tail)
    {
        uint_least8_t cnt = (uint_least8_t)1;
        for (cnt; cnt <= nIter; cnt++)
        {
            if (count % (uint_least8_t)2 == (uint_least8_t)0)
            {
                current = current->head;
            } else 
            {
                current = current->tail;
            }
        }

        struct node* delete = current;
        printf("Printing and removing node with data: %"PRIdLEAST8"\n",delete->number);
        delete->head->tail = current->tail;
        delete->tail->head = current->head;

        current = (count % (uint_least8_t)2 == (uint_least8_t)0) ? delete->head : delete->tail;
        free(delete);

        count++;
    }
    printf("Printing and removing node with data: %"PRIdLEAST8"\n",current->number);
    free(current);
    current = NULL;
    *element = NULL;
}
/*****Main funkcija - testiranje rada modula*****/
int main(void){

    uint_least8_t n = (uint_least8_t)0;
    uint_least8_t i = (uint_least8_t)0;
    uint_least8_t initial = (uint_least8_t)0; 
    uint_least16_t list = (uint_least8_t)0;
    /*Inicijalizacija liste i dodavanje elemenata na pocetku liste i na kraju*/
    struct node* node = circularInit((uint_least8_t)10);
    node = addAtBeginning(node, (uint_least8_t)9);
    addAtEnd(node, (uint_least8_t)11);
    node = addAtBeginning(node, (uint_least8_t)8);
    addAtEnd(node, (uint_least8_t)12);
    addAtEnd(node, (uint_least8_t)'a');
    addAtEnd(node, (uint_least8_t)'f');
    /*Testiranje funkcije za ispis liste ujedno i provera ispravnosti funkcija za dodavanje*/
    print(node);
    printf("\n");
    /*Testiranje dodavanja elemenata liste u sredini tj na konkretnoj poziciji
      kao i testiranje funkcija za brisanje elemenata liste*/
    addAtPosition(node, (uint_least8_t)15, (uint_least8_t)3);
    node = deleteFirst(node);
    deleteLast(node);
    deleteAtPosition(node, (uint_least8_t)3);
    print(node);
    printf("\n");
    /*Testiranje funkcije za ispis i izbacivanje elementa iz liste(staticki unos broja n)*/
    addAtEnd(node, (uint_least8_t)105);
    addAtEnd(node, (uint_least8_t)50);
    addAtEnd(node, (uint_least8_t)110);
    addAtEnd(node, (uint_least8_t)120);
    addAtEnd(node, (uint_least8_t)130);
    addAtEnd(node, (uint_least8_t)37);
    print(node);

    printAndRemoveNth(&node, (uint_least8_t)4);
    /*Testiranje sa unosom korisnika*/
    printf("Uneti pocetni element liste\nMaksimalan broj elemenata je 100(vrednost 0-255)\n");
    scanf("%"SCNdLEAST8,&initial);
    node = circularInit(initial);
    assert(node != NULL);
    printf("Uneti elemente liste(brojevi izvan opsega vrednosi tretirati kao prekid unosa):");
    printf("\n");
    for (; i < (uint_least8_t)MAX_LIST_SIZE; i++)
    {
        scanf("%"SCNdLEAST16,&list);
        if(list >= (uint_least16_t)256)
        {
            break;
        }
        addAtEnd(node, (uint_least8_t)list);
    }
    print(node);
    printf("Uneti broj n radi testiranja funkcije za stampanje i brisanje elemenata liste:");
    scanf("%"SCNdLEAST8,&n);
    printAndRemoveNth(&node, n);
    return 0;
}
