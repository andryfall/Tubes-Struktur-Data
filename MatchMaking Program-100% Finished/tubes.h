#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define infoPlayer(P) (P)->infoPlayer
#define nextPlayer(P) (P)->nextPlayer
#define first(L) ((L).first)
#define lobby(P) (P)->lobby
#define infoLobby(P) (P)->infoLobby
#define nextLobby(P) (P)->nextLobby
#define first(L) ((L).first)

struct player{
    string playerName;
    string rankPlayer;
};

struct lobby{
    int nomor;
    int totalPlayer;
    string rankPlayer;
};

typedef struct elmPlayer *adrPlayer;
typedef player infotype_player;

typedef struct elmLobby *adrLobby;
typedef lobby infotype_lobby;

struct elmPlayer{
    infotype_player infoPlayer;
    adrPlayer nextPlayer;
    adrLobby lobby;
};

struct elmLobby{
    infotype_lobby infoLobby;
    adrLobby nextLobby;
};

struct list_player{
    adrPlayer first;
};

struct list_Lobby{
    adrLobby first;
};

void createListPlayer(list_player &U);
void createListLobby(list_Lobby &L);
adrPlayer newPlayer(infotype_player x);
adrLobby newLobby(int nomor, int totalPlayer, string rankPlayer);
void insertPlayer(list_player &U, adrPlayer p);
void insertLobby(list_Lobby &L, adrLobby p);
adrPlayer searchPlayer(list_player &U, string playerName);
void connectToLobby(list_Lobby &L, list_player &U);
adrLobby searchLobby(list_Lobby &L, string rankPlayer);
adrLobby searchLobbyByNomor(list_Lobby &L, int nomor);
void searchPlayerInLobby(list_Lobby &L,list_player U, string playerName, int nomor);
void deletePlayer(list_player &U, adrPlayer p);
void deleteLobby(list_Lobby &L, adrLobby p);
int countPlayer(list_player U,  adrLobby p);
void showAllLobby(list_Lobby L, list_player U);
void showAvailableLobby(list_Lobby L);
int selectMenu();

#endif // TUBES_H_INCLUDED
