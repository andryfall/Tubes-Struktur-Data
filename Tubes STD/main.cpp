#include "tubes.h"
#include <iostream>


using namespace std;

int main()
{
    list_Lobby L;
    list_player U;
    infotype_player x;
    adrPlayer p;
    int pilihan = 0;

    //baru testing
    createListLobby(L);
    createListPlayer(U);

    pilihan = selectMenu();
    while(pilihan != 0){
        switch(pilihan){
        case 1:
            {int jumlah;
            string kembali;
            int i = 0;
            cout<<"Jumlah player yang akan ditambahkan: ";
            cin >> jumlah;
            while (i < jumlah) {
                cout<<"Nama Player : ";
                cin>>x.playerName;
                cout<<"Rank Player : ";
                cin>>x.rankPlayer;

                p = newPlayer(x);
                insertPlayer(U, p);
                i++;
            }
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>kembali;
            if (kembali == "Y"){
                pilihan = 0;
            }
            break;
            }
        case 2:
            connectToLobby(L, U);
            cout<<endl;
            cout<<"===Matchmaking Finished==="<<endl;
            cout<<endl;
            break;
        case 3:
            {
            showAvailableLobby(L);
            break;
            }
        case 4:
            {
            showAllLobby(L, U);
            break;
            }
        case 5:
            {adrPlayer fP;
            string nama;
            cout<<endl;
            cout<<"===========Find Player=========="<<endl;
            cout<<"Nama player yang ingin di cari : ";
            cin>>nama;
            fP = searchPlayer(U, nama);
            cout<<endl;
            cout<<"===========Result=========="<<endl;
            if (fP == NULL){
                cout<<"Player tidak ditemukan"<<endl;
            }else{
                adrLobby t = lobby(fP);
                cout<<"Hasil Pencarian : "<<endl;
                cout<<"Nama Player : ";
                cout<<infoPlayer(fP).playerName<<endl;
                cout<<"Rank Player : ";
                cout<<infoPlayer(fP).rankPlayer<<endl;
                cout<<"Berada di lobby : ";
                if(t == NULL){
                    cout<<"-"<<endl;
                }else{
                    cout<<infoLobby(t).nomor<<endl;
                }
            }
            cout<<endl;
            break;
            }
        case 6:
            {string fP;
            int fL;
            cout<<endl;
            cout<<"===========Find Player In Lobby=========="<<endl;
            cout<<"Nama player yang ingin di cari : ";
            cin>>fP;
            cout<<"Dicari pada lobby ke-";
            cin>> fL;

            cout<<"===========Result=========="<<endl;
            searchPlayerInLobby(L, U, fP, fL);
            cout<<endl;
            break;
            }
        case 7:
            {string nama;
            cout<<endl;
            cout<<"===========Delete Player=========="<<endl;
            cout<<"Nama player yang akan dihapus : ";
            cin>>nama;

            adrPlayer fP = searchPlayer(U, nama);
            deletePlayer(U, fP);
            cout<<"==Delete Berhasil=="<<endl;
            break;
            }
        case 8:
            {
                adrLobby s = searchLobby(L, "Silver");
                int t = countPlayer(U, s);
                cout<<t<<endl;
            }
        }
        pilihan = selectMenu();
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
