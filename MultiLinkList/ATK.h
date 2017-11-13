#ifndef ATK_H_INCLUDED
#define ATK_H_INCLUDED
#include "cstdlib"
#include <iostream>
#include <conio.h>

using namespace std;

#define nil NULL
#define info(p) p->info
#define first(ListInduk) L.first
#define last(ListInduk)  L.last
#define next(p) p->next
#define prev(p) p->prev
#define first(Lanak) Lanak.first
#define last(Lanak) Lanak.last

typedef struct Fakultas infotype;
typedef struct Dosen infotypeAnak;
typedef struct elmListAnak *adrAnak;
typedef struct elmListInduk *adr;

struct Dosen{
    string NamaDosen, ID_Dosen, PendidikanTerakhir;
    int Umur,Berat, Tinggi;
};

struct Fakultas{
    string NamaFakultas,ID_Fakultas, TahunBerdiri;
};

struct elmListAnak{
    infotypeAnak info;
    adrAnak next;
};

struct ListAnak{
   adrAnak first;
};

struct elmListInduk{
    infotype info;
    adrAnak nextAnak;
    adr next;
    adr prev;
};

struct ListInduk{
   adr first;
   adr last;
};


void createList(ListInduk &L);
void createListAnak(ListAnak &Lanak);

adr alokasi(infotype x);
adrAnak alokasiAnak(infotypeAnak x);

void insertFirst(ListInduk &L, adr p);
void insertFirstAnak(ListAnak &Lanak, adrAnak p,adr &q);

void insertLast(ListInduk &L, adr p);
void insertLastAnak(ListAnak &Lanak, adrAnak p,adr &q);

void insertAfter(ListInduk &L, adr prec, adr p);
void insertAfterAnak(adrAnak prec, adrAnak p);

void deleteFirst(ListInduk &L);
void deleteFirstAnak(ListAnak &Lanak, adrAnak &p, adr q);

void deleteLast(ListInduk &L);
void deleteLastAnak(ListAnak &Lanak, adrAnak &p, adr q);

void deleteAfter(ListInduk &L, adr prec);
void deleteAfterAnak(adrAnak prec, adrAnak &p, adr q);

void dealokasi(adr &p);
void dealokasiAnak(adrAnak &p);

adr findElm(ListInduk L, string x);
adrAnak findElmAnak(adr q, string x);
adrAnak findElmPrecAnak(adr q, string x);

void printInfoInduk(ListInduk L);
void printInfoAnak(ListAnak Lanak);

void insertAscendingInduk(ListInduk &L, adr p);
void insertAscendingAnak(ListAnak &Lanak, adrAnak p, adr q);

void insertDataParent(ListInduk &L);
void insertDataAnak(ListAnak &Lanak, ListInduk L);

void searchViewParent(ListInduk L);
void searchViewAnak(ListAnak Lanak, ListInduk L);

void searchDeleteParent(ListInduk &L);
void searchDeleteAnak(ListAnak Lanak, ListInduk L);

void hitungJumlah(ListInduk L);

void menu();
void inputData(ListInduk &L);
void searchView(ListInduk L);
void searchDelete(ListInduk &L);

#endif // ATK_H_INCLUDED
