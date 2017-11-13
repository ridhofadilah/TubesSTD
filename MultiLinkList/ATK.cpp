#include "ATK.h"

void createList(ListInduk &L){
        L.first = NULL;
        L.last = NULL;
    }                                           //MEMBUAT LIST INDUK DAN LIST ANAK
void createListAnak(ListAnak &Lanak){
        Lanak.first = NULL;
}

adr alokasi(infotype x){
        adr p = new elmListInduk;
        p->nextAnak = NULL;
        p->info = x;
        p->next = NULL;
        p->prev = NULL;
        return p;
    }                                           //ALOKASI LIST INDUK DAN LIST ANAK
adrAnak alokasiAnak(infotypeAnak x){
    adrAnak p = new elmListAnak;
    p->info = x;
    p->next = NULL;
    return p;
}

void dealokasi(adr &p){
    delete p;
}
                                                //MENDELETE SUATU ADDRESS
void dealokasiAnak(adrAnak &p){
    delete p;
}

void insertFirst(ListInduk &L, adr p){
        if (L.first == NULL){
            L.first = p;
            L.last = p;
        }                                       //INSERT FIRST BIASA PADA DOUBLE LINKED LIST
        else {
            p ->next = L.first;
            L.first->prev = p;
            L.first = p;
        }
}
void insertFirstAnak(ListAnak &Lanak, adrAnak p, adr &q){
    if (Lanak.first==NULL){
        q->nextAnak = p;
        Lanak.first = q->nextAnak;

    }                                           //DI ASUMSIKAN INDUK SUDAH KETEMU
    else{
        p->next = q->nextAnak;
        q->nextAnak = p;
        Lanak.first = q->nextAnak;
    }
}

void insertLast(ListInduk &L, adr p){
        if(L.first ==NULL){
            L.first = p;
            L.last = p;
        }                                       //INSERTLAST BIASA PADA DOUBLE LINKED LIST
        else{
            L.last ->next = p;
            p->prev = L.last;
            L.last = p;
        }
     }

void insertLastAnak(ListAnak &Lanak, adrAnak p,adr &q){
    if (q->nextAnak==NULL){
        q->nextAnak = p;
        Lanak.first = q->nextAnak;
    }                                           //DI ASUMSIKAN INDUK SUDAH PASTI KETEMU
    else{
        adrAnak s = q->nextAnak;
        while (s->next != NULL){
            s = s->next;
        }
        s->next = p;
    }
}

void insertAfter(ListInduk &L, adr prec, adr p){
    // ASUMSI PREC PASTI KETEMU
    if (L.first == NULL){
        L.first = p;
        L.last = p;
    }
    else if (prec == L.last){
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
    else{
        p->next = (prec->next);
        p->prev = prec;
        prec->next = p;
        (prec->next)->prev = p;
    }
}

void insertAfterAnak(adrAnak prec, adrAnak p){
    // ASUMSI CHILD TIDAK KOSONG DAN SUDAH PREC KETEMU
    if (prec->next == NULL){
        prec->next = p;
    }
    else{
        p->next = prec->next;
        prec->next = p;
    }
}

adr findElm(ListInduk L, string x){
    adr p = L.first;
    if (p == NULL)
        return NULL;
    else {
        while (p != NULL){
            if (p->info.ID_Fakultas == x)                   //FINDELM BERDASARKAN ID INDUK
                return p;
            else
                p = p->next;
    }
    return NULL;
    }
}

adrAnak findElmAnak(adr q, string x){
    adrAnak p = q->nextAnak;
    if (p == NULL)
        return NULL;
    else {
        while (p != NULL){
            if (p->info.ID_Dosen == x)                      //FINDELM BERDASARKAN ID IN
                return p;
            else
                p = p->next;
    }
    return NULL;
    }
}

void printInfoInduk(ListInduk L){
        adr p = L.first;
        ListAnak Lanak;
        int i = 0;
        if (p==NULL){
            cout << "Tidak Ada Data" << endl;
        }
        else{
            while (p != NULL ){
                i++;
                cout << i ;
                cout << ". Nama Fakultas : " << p->info.NamaFakultas << endl;
                cout << "   ID Fakultas   : " << p->info.ID_Fakultas << endl;
                //cout << "   Tahun Berdiri : " << p->info.TahunBerdiri << endl;
                cout << endl;
                Lanak.first = p->nextAnak;
                printInfoAnak(Lanak);
                p=p->next;
            }
        }
        getch();
        system("cls");
}

void printInfoAnak(ListAnak Lanak){
        adrAnak p = Lanak.first;
        while (p != NULL ){
            cout << "~  Nama Dosen           : " << p->info.NamaDosen << endl;
            cout << "   ID Dosen             : " << p->info.ID_Dosen << endl;
            //cout << "   Pendidikan Terakhir  : " << p->info.PendidikanTerakhir << endl;
            //cout << "   Umur                 : " << p->info.Umur << endl;
            //cout << "   Berat                : " << p->info.Berat << endl;
            //cout << "   Tinggi               : " << p->info.Tinggi << endl;
            cout << endl;
            p=p->next;
        }
}

void deleteFirstAnak(ListAnak &Lanak, adrAnak &p, adr q){
    if (Lanak.first==NULL)
        p = NULL;
    else if (Lanak.first->next == NULL){
        p = Lanak.first;
        q->nextAnak = NULL;
        Lanak.first = NULL;

    }
    else {
        p = Lanak.first;
        q->nextAnak = p->next;
        Lanak.first = p->next;
        p->next = NULL;

    }
    dealokasiAnak(p);
}

void deleteFirst(ListInduk &L){
    adr s;
    if (L.first == NULL)
        s= NULL;
    else if (L.first->next == NULL){
        s = L.first;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        L.first = NULL;
        L.last = NULL;
    }
    else{
        s = L.first;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        L.first = s->next;
        s->next = NULL;
        L.first->prev = NULL;
    }
    dealokasi(s);
}

void deleteLastAnak(ListAnak &Lanak, adrAnak &p, adr q){
    if (q->nextAnak == NULL)
        p=NULL;
    else if (q->nextAnak->next == NULL){
        p = q->nextAnak;
        Lanak.first = NULL;
        q->nextAnak = NULL;
    }
    else{
        adrAnak s = q->nextAnak;
        p = s->next;
        while (p->next != NULL){
            s = p;
            p = p->next;
        }
        p = s->next;
        s->next = NULL;
    }
    dealokasiAnak(p);
}

void deleteLast(ListInduk &L){
    adr s;
    if (L.first == NULL)
        s=NULL;
    else if (L.first == L.last) {
        s = L.first;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first->next !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        L.first = NULL;
        L.last = NULL;
    }
    else {
        s = L.last;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        L.last = s->prev;
        s->prev = NULL;
        L.last->next = NULL;
    }
    dealokasi(s);
}

void deleteAfter(ListInduk &L, adr prec){
    adr s;
    if (L.first == NULL) {
        s=NULL;
    }
    else if (prec->next == L.last){
        s=L.last;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        L.last = prec;
        s->prev = NULL;
        prec->next = NULL;
    }
    else if (prec->next == NULL)
        s=NULL;
    else{
        s = prec->next;
        adrAnak p;
        ListAnak Lanak;
        Lanak.first = s->nextAnak;
        if (Lanak.first !=NULL){
            do{
                deleteFirstAnak(Lanak,p,s);
            }while(Lanak.first->next != NULL);
            deleteLastAnak(Lanak,p,s);
        }
        prec->next = s->next;
        (prec->next)->prev = prec;
        s->prev = NULL;
        s->next = NULL;
    }
    dealokasi(s);
}


void deleteAfterAnak(adrAnak prec, adr q){
    adrAnak p;
    if (prec->next == NULL)
        p = NULL;
    else if (prec->next->next == NULL){
        p = prec->next;
        prec->next = NULL;
    }
    else {
        p=prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
    dealokasiAnak(p);
}

void insertAscendingInduk(ListInduk &L, adr p){
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    }
    else{
        adr q = L.first;
        if (p->info.ID_Fakultas < q->info.ID_Fakultas)
            insertFirst(L,p);
        else{
            while (q != NULL){
                if (p->info.ID_Fakultas < q->info.ID_Fakultas)
                    break;
                else
                    q = q->next;
            }
            if (q != NULL){
                adr prec = q->prev;
                insertAfter(L,prec,p);
            }
            else
                insertLast(L,p);
        }
    }
}

void insertAscendingAnak(ListAnak &Lanak, adrAnak p, adr q){
    Lanak.first = q->nextAnak;
    if (Lanak.first == NULL) {
        q->nextAnak = p;
        Lanak.first = q->nextAnak;
    }
    else{
        adrAnak r = Lanak.first;
        if (p->info.ID_Dosen < r->info.ID_Dosen)
            insertFirstAnak(Lanak,p,q);
        else{
            adrAnak o = r;
            while (r != NULL){
                if (p->info.ID_Dosen < r->info.ID_Dosen)
                    break;
                else{
                    o = r;
                    r = r->next;
                }
            }
            if (r != NULL){
                insertAfterAnak(o,p);
            }
            else
                insertLastAnak(Lanak,p,q);
        }
    }
}

void insertDataParent(ListInduk &L){
    infotype a;
    cout << "Selamat Datang Di Menu Input Fakultas" << endl;
    cout << "ID Fakultas    :   " ; cin >> a.ID_Fakultas;
    cout << "Nama Fakultas  :   " ; cin >> a.NamaFakultas;
    cout << "Tahun Berdiri  :   " ; cin >> a.TahunBerdiri;
    system("cls");
    adr p = alokasi(a);
    insertAscendingInduk(L,p);
}

void insertDataAnak(ListAnak &Lanak, ListInduk L){
    infotypeAnak a;
    string b;
    cout << "Selamat Datang Di Menu Input Dosen" << endl;
    cout << "ID Dosen               :   " ; cin >> a.ID_Dosen;
    cout << "Nama Dosen             :   " ; cin >> a.NamaDosen;
    cout << "Pendidikan Terakhir    :   " ; cin >> a.PendidikanTerakhir;
    cout << "Umur                   :   " ; cin >> a.Umur;
    cout << "Berat                  :   " ; cin >> a.Berat;
    cout << "Tinggi                 :   " ; cin >> a.Tinggi;
    cout << endl << "Dosen akan di masukan pada fakultas dengan ID : "; cin >> b ;
    system("cls");
    adrAnak p = alokasiAnak(a);
    adr q = findElm(L,b);
    if (q!=NULL){
        insertAscendingAnak(Lanak,p,q);
    }
    if (q==NULL){
        cout << "Maaf tidak ada Fakultas dengan ID yang anda Inputkan" << endl;
        getch();
        system("cls");
    }
}

void searchViewParent(ListInduk L){
    string a;
    cout << "Masukkan ID Fakultas yang ingin dicari : " ; cin >> a;
    system("cls");
    adr p = findElm(L,a);
    if (p == NULL){
        cout << "Data tidak ditemukan" << endl;
    }
    else{
            cout << "Nama Fakultas : " << p->info.NamaFakultas << endl;
            cout << "ID Fakultas   : " << p->info.ID_Fakultas << endl;
            cout << "Tahun Berdiri : " << p->info.TahunBerdiri << endl;
            cout << endl;

    }
    getch();
    system("cls");
}

void searchViewAnak(ListInduk L){
    string a,b;
    cout << "Masukkan ID Dosen yang ingin dicari    : " ; cin >> a;
    cout << "ID Dosen akan dicari pada ID Fakultas  : " ; cin >> b;
    system("cls");
    adr p = findElm(L,b);
    if (p != NULL){
        adrAnak q = findElmAnak(p,a);
        if (q == NULL){
            cout << "Data tidak ditemukan" << endl;
            getch();
            system("cls");
        }
        else{
            cout << "Nama Dosen           : " << q->info.NamaDosen << endl;
            cout << "ID Dosen             : " << q->info.ID_Dosen << endl;
            cout << "Pendidikan Terakhir  : " << q->info.PendidikanTerakhir << endl;
            cout << "Umur                 : " << q->info.Umur << endl;
            cout << "Berat                : " << q->info.Berat << endl;
            cout << "Tinggi               : " << q->info.Tinggi << endl;
            cout << endl;
            getch();
            system("cls");
        }
    }
    else{
        cout << "Tidak ada Fakultas dengan ID ini " << b << endl;
        getch();
        system("cls");
    }

}

void searchDeleteParent(ListInduk &L){
    string a;
    cout << "Masukkan ID Fakultas yang ingin di hapus   :   " ; cin >> a;
    system("cls");
    adr p = findElm(L,a);
    if (p==NULL){
        cout << "Data Tidak Ditemukan" << endl;
        getch();
        system("cls");
    }
    else{
        if (p==L.first){
            deleteFirst(L);
        }
        else if (p==L.last){
            deleteLast(L);
        }
        else{
            adr prec = p->prev;
            deleteAfter(L,prec);
        }

    }
}

adrAnak findElmPrecAnak(adr q, string x){
    adrAnak p = q->nextAnak;
    if (p == NULL)
        return NULL;
    else {
        adrAnak r = p;
        while (p != NULL){
            if (p->info.ID_Dosen == x)
                return r;
            else{
                r = p;
                p = p->next;
            }
    }
    return NULL;
    }
}

void searchDeleteAnak(ListAnak Lanak, ListInduk L){
    string a,b;
    cout << "Masukkan ID Dosen yang ingin dihapus           : " ; cin >> a;
    cout << "ID Dosen akan dicari pada Fakultas dengan ID   : " ; cin >> b;
    system("cls");
    adr p = findElm(L,b);
    adrAnak q = findElmPrecAnak(p,a);
    if (q==NULL){
        cout << "Data Tidak Ditemukan" << endl;
        getch();
        system("cls");
    }
    else if (q==p->nextAnak){
        adrAnak r;
        deleteFirstAnak(Lanak,r,p);
    }
    else{
        deleteAfterAnak(q,p);
    }
}


void hitungJumlah(ListInduk L){
    adr p = L.first;
    if (p==NULL){
        cout << "Tidak Ada Data" << endl;

    }
    else{
        int c = 0;
        cout << "REPORTING" << endl << endl;
        while (p != NULL){
            c++;
            adrAnak q = p->nextAnak;
            double i=0;
            double x = 0;
            double y = 0;
            double z = 0;
            double k = 0;
            double l = 0;
            double m = 0;
            if (q!=NULL){
                while (q!=NULL){
                    i++;
                    x += q->info.Umur;
                    y += q->info.Berat;
                    z += q->info.Tinggi;
                    q=q->next;
                }
                k = x / i;
                l = y / i;
                m = y / i;
            }
            cout << "Total Dosen di Fakultas " << p->info.NamaFakultas << " adalah " << i << endl;
            cout << "Rata-Rata Umur Dosen di Fakultas " << p->info.NamaFakultas << " adalah " << k << " tahun"<< endl;
            cout << "Rata-Rata Berat Dosen di Fakultas " << p->info.NamaFakultas << " adalah " << l << " kg" << endl;
            cout << "Rata-Rata Tinggi Dosen di Fakultas " << p->info.NamaFakultas << " adalah " << m << " cm" << endl << endl;
            p=p->next;
        }

            cout << "Total Fakultas Sebanyak " << c << endl;
    }
        getch();
        system("cls");
}

void insertData(ListInduk &L){
    int a;
    cout << "Selamat Datang di menu Input Data" << endl;
    cout << "1. Input Data Fakultas" << endl;
    cout << "2. Input Data Dosen" << endl;
    cout << "Pilih Menu: "; cin >> a;
    system("cls");
    if (a==1)
        insertDataParent(L);
    else if (a==2){
        ListAnak Lanak;
        insertDataAnak(Lanak,L);
    }
    else{
        cout << "Maaf Tidak ada pilihan itu" << endl;
        getch();
        system("cls");
    }

}

void searchView(ListInduk L){
    int a;
    cout << "Selamat Datang di menu Pencarian Data" << endl;
    cout << "1. Cari Data Fakultas" << endl;
    cout << "2. Cari Data Dosen" << endl;
    cout << "Pilih Menu: "; cin >> a;
    system("cls");
    if (a==1)
        searchViewParent(L);
    else if (a==2){
        ListAnak Lanak;
        searchViewAnak(L);
    }
    else{
        cout << "Maaf Tidak ada pilihan itu" << endl;
        getch();
        system("cls");
    }
}

void searchDelete(ListInduk &L){
    int a;
    cout << "Selamat Datang di menu Delete Data" << endl;
    cout << "1. Delete Data Fakultas" << endl;
    cout << "2. Delete Data Dosen" << endl;
    cout << "Pilih Menu: "; cin >> a;
    system("cls");
    if (a==1)
        searchDeleteParent(L);
    else if (a==2){
        ListAnak Lanak;
        searchDeleteAnak(Lanak,L);
    }
    else{
        cout << "Maaf Tidak ada pilihan itu" << endl;
        getch();
        system("cls");
    }
}


void menu(){
    ListInduk L;
    ListAnak Lanak;
    createList(L);
    createListAnak(Lanak);
    char a;
    cout << "    Selamat Datang" << endl;
    cout << "         Menu" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Search And View" << endl;
    cout << "3. Search And Delete" << endl;
    cout << "4. View All" << endl;
    cout << "5. Reporting" << endl;
    cout << "6. Keluar" << endl;
    cout << "PILIH MENU     : "; cin >> a;
    system("cls");
    while (a != '6'){
        switch(a){
            case '1' : insertData(L); break;
            case '2' : searchView(L); break;
            case '3' : searchDelete(L); break;
            case '4' : printInfoInduk(L); break;
            case '5' : hitungJumlah(L); break;
            case '6' : break;
        }
        cout << "    Selamat Datang" << endl;
        cout << "         Menu" << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Search And View" << endl;
        cout << "3. Search And Delete" << endl;
        cout << "4. View All" << endl;
        cout << "5. Reporting" << endl;
        cout << "6. Keluar" << endl;
        cout << "PILIH MENU     : "; cin >> a;
        system("cls");
    }
    cout << "Selamat Tinggal!!";
}
