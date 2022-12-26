#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
using namespace std;

#define infoUser(P) (P)->infoUser
#define nextUser(P) (P)->nextUser
#define first(L) ((L).first)
#define lobby(P) (P)->lobby

struct user{
    string userName;
    int userId;
    string rankUser;
};

typedef struct elmUser *adrUser;
typedef user infotype_user;

struct elmUser{
    infotype_user infoUser;
    adrUser nextUser;
    adrLobby lobby;
};

struct list_user{
    adrUser first;
};

createUser(list_user &U, infotype_user userBaru);
findUser(list_user &U, int idUser);
findUserinLoby(list_lobby &L, int idUser);
joinGame(adrLobby P, adrUser &C);
deleteUser(list_user &U);



#endif // USER_H_INCLUDED
