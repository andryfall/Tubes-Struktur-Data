#include "lobby.h"
void createLobby(list_Lobby &L, infotype_lobby lobbyBaru){
    adrLobby P;
    P = new elmLobby;
    infoLobby(P) = lobbyBaru;
    nextLobby(P) = NULL;
    
    if(first(L)==NULL){
        first(L) = P;
    } else {
        adrLobby Q;
        Q = first(L);
        while(Q!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void removePlayer(list_Lobby &L, ){
    
}

void deleteLobby(list_Lobby &L, adrLobby &P);{
    adrLobby Q;
    if(first(L) == NULL){
        cout << "Lobby Kosong" << endl;
    } else if (next(first(L))==NULL){
        P = first(L);
        first(L) = NULL;
    } else {
        Q = first(L);
        while(next(Q)!=NULL){
            Q = next(Q);   
        }
        first(L) = nextLobby(P);
        nextLobby(Q) = nextLobby(P);
        nextLobby(P) = NULL;
           
    }
}
void showAllLobby(list_Lobby L){
    adrLobby P;
    if(first(L)!=NULL){
        P = first(L);
        while(P!=NULL){
            cout << "ID Lobby : " << infoLobby(P).id << endl;
            cout << "Total Player : " << infoLobby(P).totalPlayer << endl;
            cout << "Rank : " << infoLobby(P).rank << endl;
            P = nextLobby(P);
        }
        cout << endl;
    } else {
        cout << "Lobby Kosong" << endl;
    }
}

bool findLobby(list_Lobby L, int id){
    
}

void showLobbyData(list_Lobby L, adrLobby P){
    
}
