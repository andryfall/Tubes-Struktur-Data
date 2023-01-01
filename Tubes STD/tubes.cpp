#include "tubes.h"

void createListPlayer(list_player &U){
    first(U) = NULL;
}
void createListLobby(list_Lobby &L){
    first(L) = NULL;
}

adrPlayer newPlayer(infotype_player x){
    adrPlayer p;
    p = new elmPlayer;
    infoPlayer(p) = x;
    nextPlayer(p) = NULL;
    return p;
}

adrLobby newLobby(int nomor, int totalPlayer, string rankPlayer){
    adrLobby p;
    p = new elmLobby;
    infoLobby(p).nomor = nomor;
    infoLobby(p).totalPlayer = totalPlayer;
    infoLobby(p).rankPlayer = rankPlayer;
    nextLobby(p) = NULL;
    return p;
}

void insertPlayer(list_player &U, adrPlayer p){

    if(first(U)==NULL){
        first(U) = p;
        nextPlayer(p) = first(U);
    } else {
        adrPlayer Q;
        Q = first(U);
        nextPlayer(p) = first(U);
        while(nextPlayer(Q)!=first(U)){
            Q = nextPlayer(Q);
        }
        nextPlayer(Q) = p;
    }
}

void insertLobby(list_Lobby &L, adrLobby p){
    adrLobby Q;
    if(first(L)==NULL){
        first(L) = p;
    } else {
        Q = first(L);
        while(nextLobby(Q) !=NULL){
            Q = nextLobby(Q);
        }
        nextLobby(Q) = p;
    }
}

adrPlayer searchPlayer(list_player &U, string playerName){
    if(first(U) == NULL){
        return NULL;
    }else{
        adrPlayer p = first(U);
        while(infoPlayer(p).playerName != playerName && nextPlayer(p) != first(U)){
            p = nextPlayer(p);
        }
        if(infoPlayer(p).playerName == playerName){
            return p;
        }else{
            return NULL;
        }
    }
}

adrLobby searchLobby(list_Lobby &L, string rankPlayer){
    adrLobby q;
    q = first(L);
    if (first(L) == NULL){
        return NULL;
    }else{
        while(q != NULL){
            if(infoLobby(q).rankPlayer == rankPlayer){
                return q;
            }else{
                q = nextLobby(q);
            }
        }
    }
    return NULL;
}
void connectToLobby(list_Lobby &L, list_player &U){
    int nomorLobby = 1;
    adrPlayer p;
    p = first(U);
    adrLobby q, s;
    q = first(L);

    if(p == NULL){
        cout<<"List Player Kosong"<<endl;
    }else if(nextPlayer(p) == first(U)){
        s = searchLobby(L, infoPlayer(p).rankPlayer);
        if(s == NULL){
            insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
            s = searchLobby(L, infoPlayer(p).rankPlayer);

            lobby(p) = s;
            infoLobby(lobby(p)).totalPlayer++;
        }else if(s != NULL){
            while(q != NULL){
                if((infoLobby(q).rankPlayer == infoPlayer(p).rankPlayer) && (infoLobby(q).totalPlayer < 4)){
                    lobby(p) = q;
                }else{
                    q = nextLobby(q);
                }
            }
            if(q == NULL && lobby(p) == NULL){
                insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
                q = nextLobby(q);
                lobby(p) = q;
                infoLobby(lobby(p)).totalPlayer++;
            }
        }
    }else{
        while(nextPlayer(p) != first(U)){
            s = searchLobby(L, infoPlayer(p).rankPlayer);
            if(s == NULL){
                insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
                nomorLobby++;
                s = searchLobby(L, infoPlayer(p).rankPlayer);
                lobby(p) = s;
                infoLobby(lobby(p)).totalPlayer++;
            }else if(s != NULL){
                if(infoLobby(s).totalPlayer < 4){
                    lobby(p) = s;
                    infoLobby(lobby(p)).totalPlayer++;
                }else{
                    insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
                    s = searchLobby(L, infoPlayer(p).rankPlayer);
                    lobby(p) = s;
                    infoLobby(lobby(p)).totalPlayer++;
                }
            }
            p = nextPlayer(p);
        }
        s = searchLobby(L, infoPlayer(p).rankPlayer);

        if (s == NULL){
            insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
            nomorLobby++;
            s = searchLobby(L, infoPlayer(p).rankPlayer);
            lobby(p) = s;
            infoLobby(lobby(p)).totalPlayer++;
        }else if(s != NULL){
            if(infoLobby(s).totalPlayer < 4){
                lobby(p) = s;
                infoLobby(lobby(p)).totalPlayer++;
            }else{
                insertLobby(L, newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer));
                s = searchLobby(L, infoPlayer(p).rankPlayer);
                lobby(p) = s;
                infoLobby(lobby(p)).totalPlayer++;
            }
        }
    }
}
void searchPlayerInLobby(list_Lobby &L, string playerName, int nomor){

}
void deletePlayer(list_player &U, adrPlayer &p){
    adrPlayer Q;
    if (first(L)==NULL){
        cout << "Player Tidak Ada" << endl;   
    } else if (nextPlayer(first(L))==first(L)){
        p = first(L);
        Q = first(L);
        first(L) = nextPlayer(first(L));
        nextPlayer(Q) = first(L);
        nextPlayer(p) = NULL;
    } else {
        Q = first(L);
        while(nextPlayer(Q)!=first(L)){
            Q = nextPlayer(Q);
        }
        p = nextPlayer(Q);
	nextPlayer(Q) = first(L);
	nextPlayer(p) = NULL;
    }
}
void deleteLobby(list_Lobby &L, adrLobby &p){
    adrLobby Q;
    if(first(L) == NULL){
        cout << "Lobby Kosong" << endl;
    } else if (nextLobby(first(L))==NULL){
        p = first(L);
	next(p) = NULL;
        first(L) = NULL;
    } else {
        Q = first(L);
        while(nextLobby(Q)!=NULL){
            Q = nextLobby(Q);   
        }
        first(L) = nextLobby(p);
        nextLobby(Q) = nextLobby(p);
        nextLobby(p) = NULL;
           
    }   
}
int countPlayer(adrLobby p);
void showAllLobby(list_Lobby L){
	adrLobby P;
	if(first(L)==NULL){
		cout << "Lobby Kosong" << endl;
	} else {
		P = first(L);
		while(P!=NULL){
			cout << "Nomor Lobby-" << info(P).nomor << endl;
			cout << "Total Player: " << info(P).totalPlayer << endl;
			cout << "Rank: " << info(P).rankPlayer << endl;
			adrPlayer R = first(L);
			while(R!=first(L)){
				if(lobby(R)==P){
					cout << "Nama Player: " << info(R).playerName << endl;
					cout << "Rank Player: " << info(R).rankPlayer << endl;
				}
				R = nextPlayer(R);
			}
			P = nextLobby(P);
		}
	}
	
}
void showDetailLobby(list_Lobby L, adrLobby p){
	adrLobby Q = searchLobby(L, info(p).rankPlayer);
	if (Q==NULL){
		cout << "Lobby Tidak Ditemukan" << endl;
	} else {
		cout << "Nomor Lobby-" <<  info(P).nomor << endl;
		cout << "Total Player: " << info(P).totalPlayer << endl;
		cout << "Rank: " << info(P).rankPlayer << endl;
	}
}
	


