#include "tubes.h"
#include <iostream>


using namespace std;

int main()
{
    list_Lobby L;
    list_player U;
    infotype_player x;
    adrPlayer p;

    //baru testing
    createListLobby(L);
    createListPlayer(U);

    x.playerName = "Saya";
    x.rankPlayer = "Bronze";
    insertPlayer(U, newPlayer(x));

    x.playerName = "Dia";
    x.rankPlayer = "Bronze";
    insertPlayer(U, newPlayer(x));

    x.playerName = "Kami";
    x.rankPlayer = "Silver";
    insertPlayer(U, newPlayer(x));



    connectToLobby(L, U);

    adrLobby n;
    p = searchPlayer(U, "Saya");
    n = lobby(p);
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;
    cout <<infoLobby(n).nomor << endl;

    p = searchPlayer(U, "Dia");
    n = lobby(p);
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;
    cout <<infoLobby(n).nomor << endl;

    p = searchPlayer(U, "Kami");
    n = lobby(p);
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;
    cout <<infoLobby(n).nomor << endl;


    cout<<"================================================="<<endl;
    showAllLobby(L, U);
    cout<<"================================================="<<endl;


    adrPlayer dP;
    dP = searchPlayer(U, "Dia");
    deletePlayer(U, dP);

    cout<<"================================================="<<endl;
    showAllLobby(L, U);
    cout<<"================================================="<<endl;

    adrLobby dL;
    dL = searchLobby(L, "Silver");
    deleteLobby(L, dL);

    cout<<"================================================="<<endl;
    showAllLobby(L, U);
    cout<<"================================================="<<endl;


}
