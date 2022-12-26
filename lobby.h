#ifndef LOBBY_H_INCLUDED
#define LOBBY_H_INCLUDED

#include <iostream>
using namespace std;

#define infoLobby(P) (P)->infoLobby
#define nextLobby(P) (P)->nextLobby
#define first(L) ((L).first)


struct lobby{
    int idLobby;
    int totalPemain;
    string rankUser;
};

typedef struct elmLobby *adrLobby;
typedef lobby infotype_lobby;

struct elmLobby{
    infotype_lobby infoLobby;
    adrLobby nextLobby;
};

struct list_Lobby{
    adrLobby first;
};

void createLobby(list_Lobby &L, infotype_lobby lobbyBaru);
void removePlayer(list_Lobby &L, );
void deleteLobby(list_Lobby &L, adrLobby &P);
void showAllLobby(list_Lobby L);
bool findLobby(list_Lobby L, infotype_lobby x);
void showLobbyData(list_Lobby L, adrLobby P);
#endif // LOBBY_H_INCLUDED
