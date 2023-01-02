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
void deletePlayer(list_player &U, adrPlayer p){
    adrPlayer Q, R, prec;
    if (first(U)==NULL){
        cout << "Player Tidak Ada" << endl;
    } else if (nextPlayer(first(U))==first(U)){
        p = first(U);
        Q = first(U);
        first(U) = nextPlayer(first(U));
        nextPlayer(Q) = first(U);
        nextPlayer(p) = NULL;
    } else {
        Q = first(U);
        R = first(U);

        while(nextPlayer(R) != first(U)){
            R = nextPlayer(R);
        }

        if (p == Q){
            while(nextPlayer(Q) != first(U)){
                Q = nextPlayer(Q);
            }
            p = first(U);
            first(U) = nextPlayer(first(U));
            nextPlayer(Q) = first(U);
            nextPlayer(p) = NULL;
        }else if(p == R){
            while(nextPlayer(nextPlayer(Q)) != first(U)){
                Q = nextPlayer(Q);
            }
            p = nextPlayer(Q);
            nextPlayer(Q) = first(U);
            nextPlayer(p) = NULL;
        }else{
            while(Q != p){
                prec = Q;
                Q = nextPlayer(Q);
            }
            p = nextPlayer(prec);
            nextPlayer(prec) = nextPlayer(p);
            nextPlayer(p) = NULL;
        }
    }
}
void deleteLobby(list_Lobby &L, adrLobby p){
    adrLobby Q, R, prec;
    if(first(L) == NULL){
        cout << "Lobby Kosong" << endl;
    } else if (nextLobby(first(L))==NULL){
        p = first(L);
        nextLobby(p) = NULL;
        first(L) = NULL;
    } else {
        Q = first(L);
        R = first(L);

        while(nextLobby(R) != NULL){
            R = nextLobby(R);
        }

        if(p == first(L)){
            p = first(L);
            first(L) = nextLobby(p);
            nextLobby(p) = NULL;
        }else if(p == R){
            while(nextLobby(nextLobby(Q)) != NULL){
                Q = nextLobby(Q);
            }
            p = nextLobby(Q);
            nextLobby(Q) = NULL;
        }else{
            while(Q != p){
                prec = Q;
                Q = nextLobby(Q);
            }
            p = nextLobby(prec);
            nextLobby(prec) = nextLobby(p);
            nextLobby(p) = NULL;
        }
    }
}
int countPlayer(adrLobby p);
void showAllLobby(list_Lobby L, list_player U){
	adrLobby P;
	if(first(L)==NULL){
		cout << "Lobby Kosong" << endl;
	} else {
		P = first(L);
		while(P!=NULL){
			cout << "Nomor Lobby-" << infoLobby(P).nomor << endl;
			cout << "Total Player: " << infoLobby(P).totalPlayer << endl;
			cout << "Rank: " << infoLobby(P).rankPlayer << endl;
			adrPlayer R = first(U);
			adrLobby Q = lobby(R);
			if(nextPlayer(R) == first(U)){
                if(Q == P){
                    cout<< "Nama Player : " <<infoPlayer(R).playerName <<endl;
                    cout<< "Rank Player : " <<infoPlayer(R).rankPlayer <<endl;
                }
			}else{
                while(nextPlayer(R) != first(U)){
                    if(Q == P){
                        cout<< "Nama Player : " <<infoPlayer(R).playerName <<endl;
                        cout<< "Rank Player : " <<infoPlayer(R).rankPlayer <<endl;
                    }
                    R = nextPlayer(R);
                }
                adrLobby Q = lobby(R);
                if(Q == P){
                    cout<< "Nama Player : " <<infoPlayer(R).playerName <<endl;
                    cout<< "Rank Player : " <<infoPlayer(R).rankPlayer <<endl;
                }
			}
			P = nextLobby(P);
		}
	}
}
void showAvailableLobby(list_Lobby L){
    adrLobby p = first(L);
    while(p != NULL){
        cout << "Nomor Lobby-" << infoLobby(p).nomor << endl;
        cout << "Total Player: " << infoLobby(p).totalPlayer << endl;
        cout << "Rank: " << infoLobby(p).rankPlayer << endl;
        p = nextLobby(p);
    }
}


