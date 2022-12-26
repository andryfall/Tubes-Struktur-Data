#include "lobby.h"
void createLobby(list_Lobby &L, infotype_lobby lobbyBaru){
    adrLobby P;
    P = new elmLobby;
    infoLobby(P) = lobbyBaru;
    nextLobby(P) = NULL;
}
void removePlayer(list_Lobby &L, );
void deleteLobby(list_Lobby &L, adrLobby &P);
void showAllLobby(list_Lobby L);
bool findLobby(list_Lobby L, infotype_lobby x);
void showLobbyData(list_Lobby L, adrLobby P);
