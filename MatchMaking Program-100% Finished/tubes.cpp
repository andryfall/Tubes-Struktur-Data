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
adrLobby searchLobbyByNomor(list_Lobby &L, int nomor){
    adrLobby q;
    q = first(L);
    if (first(L) == NULL){
        return NULL;
    }else{
        while(q != NULL){
            if(infoLobby(q).nomor == nomor){
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
    adrLobby s;

    if(p == NULL){
        cout<<"List Player Kosong"<<endl;
    }else if(nextPlayer(p) == first(U)){
        cout<<"Hanya Terdapat Satu Player"<<endl;
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
                int cT = countPlayer(U, s);
                if(cT < 4){
                    lobby(p) = s;
                    cT = countPlayer(U, s);
                    infoLobby(lobby(p)).totalPlayer = cT;
                }else{
                    cout<<s<<endl;
                    s = nextLobby(s);
                    cout<<s<<endl;
                    while(s != NULL && lobby(p) == NULL){
                        cout<<1<<endl;
                        if(infoLobby(s).rankPlayer == infoPlayer(p).rankPlayer && infoLobby(s).totalPlayer < 4){
                            cout<<2<<endl;
                            lobby(p) = s;
                            cout<<3<<endl;
                            cT = countPlayer(U, s);
                            cout<<4<<endl;
                            infoLobby(lobby(p)).totalPlayer = cT;
                            cout<<5<<endl;
                        }else{
                            cout<<6<<endl;
                            s = nextLobby(s);
                        }
                    }
                    if(s == NULL && lobby(p) == NULL){
                        adrLobby n = newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer);
                        insertLobby(L, n);
                        nomorLobby++;
                        lobby(p) = n;
                        int cT = countPlayer(U, n);
                        infoLobby(lobby(p)).totalPlayer = cT;
                    }
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
                    int cT = countPlayer(U, s);
                    infoLobby(lobby(p)).totalPlayer = cT;
                }else{
                    s = nextLobby(s);
                    while(s != NULL){
                        if(infoLobby(s).rankPlayer == infoPlayer(p).rankPlayer && infoLobby(s).totalPlayer < 4){
                            lobby(p) = s;
                            int cT = countPlayer(U, s);
                            infoLobby(lobby(p)).totalPlayer = cT;
                        }else{
                            s = nextLobby(s);
                        }
                    }
                    if(s == NULL && lobby(p) == NULL){
                        cout<<1<<endl;
                        adrLobby n = newLobby(nomorLobby, 0, infoPlayer(p).rankPlayer);
                        insertLobby(L, n);
                        nomorLobby++;
                        lobby(p) = n;
                        int cT = countPlayer(U, n);
                        infoLobby(lobby(p)).totalPlayer = cT;
                    }
                }
        }
    }
}
void searchPlayerInLobby(list_Lobby &L, list_player U, string playerName, int nomor){
    adrPlayer p;
    adrLobby q;

    p = searchPlayer(U, playerName);

    if(p == NULL){
        cout<<"Tidak ada player dengan nama tersebut"<<endl;
    }else{
        q = lobby(p);
        if (q == NULL){
            cout<<"Player tidak berada dalam lobby manapun"<<endl;
        }else if(infoLobby(q).nomor == nomor){
            cout<<"Player ada dalam lobby tersebut"<<endl;
        }
    }
}
void deletePlayer(list_player &U, adrPlayer p){
    adrPlayer Q, R, prec;
    adrLobby t;
    if (first(U)==NULL){
        cout << "Player Tidak Ada" << endl;
    } else if (nextPlayer(first(U))==first(U)){
        t = lobby(p);
        p = first(U);
        Q = first(U);
        first(U) = nextPlayer(first(U));
        nextPlayer(Q) = first(U);
        nextPlayer(p) = NULL;
        infoLobby(t).totalPlayer--;
    } else {
        t = lobby(p);
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
            infoLobby(t).totalPlayer--;
        }else if(p == R){
            while(nextPlayer(nextPlayer(Q)) != first(U)){
                Q = nextPlayer(Q);
            }
            p = nextPlayer(Q);
            nextPlayer(Q) = first(U);
            nextPlayer(p) = NULL;
            infoLobby(t).totalPlayer--;
        }else{
            while(Q != p){
                prec = Q;
                Q = nextPlayer(Q);
            }
            p = nextPlayer(prec);
            nextPlayer(prec) = nextPlayer(p);
            nextPlayer(p) = NULL;
            infoLobby(t).totalPlayer--;
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
int countPlayer(list_player U,  adrLobby p){
    adrPlayer r;
    adrLobby q;
    r = first(U);
    int total = 0;

    if(p == NULL){
        cout<<"Player kosong"<<endl;
    }else if(nextPlayer(r) == first(U)){
        q = lobby(r);
        if(q == p){
            return 1;
        }
    }else{
        q = lobby(r);

        while(nextPlayer(r) != first(U)){
            if (q == p){
                total++;
            }
            r = nextPlayer(r);
            q = lobby(r);
        }
        if (q == p){
                total++;
        }
    }
    return total;
}
void showAllLobby(list_Lobby L, list_player U){
	adrLobby P;
	cout<<endl;
	cout<<"======All Lobby and Players======="<<endl;
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
            cout << "Player dalam Lobby : ";
			if(nextPlayer(R) == first(U)){
                if(Q == P){
                    cout<< infoPlayer(R).playerName << endl;
                }
			}else{
                while(nextPlayer(R) != first(U)){
                    if(Q == P){
                        cout<< infoPlayer(R).playerName << " - ";
                    }
                    R = nextPlayer(R);
                    Q = lobby(R);
                }
                adrLobby Q = lobby(R);
                if(Q == P){
                    cout<< infoPlayer(R).playerName << " - ";
                }
			}
			int t = countPlayer(U, P);
			if (t == 4){
                cout<<"FULL"<<endl;
			}else{
                cout<<"...Waiting For More Players..."<<endl;
			}
			cout<<endl;
			P = nextLobby(P);
		}
	}
}
void showAvailableLobby(list_Lobby L){
    adrLobby p = first(L);
    cout<<endl;
    cout<<"======All Available Lobby======="<<endl;
    while(p != NULL){
        cout << "Nomor Lobby-" << infoLobby(p).nomor << endl;
        cout << "Total Player: " << infoLobby(p).totalPlayer << endl;
        cout << "Rank: " << infoLobby(p).rankPlayer << endl;
        cout<<endl;
        p = nextLobby(p);
    }
    cout<<endl;
}

int selectMenu(){
    cout << "======MENU======="<<endl;
    cout<<"1. Menambahkan Player(s) baru"<<endl;
    cout<<"2. Start Matchmaking"<<endl;
    cout<<"3. Tampilkan semua lobby yang ada"<<endl;
    cout<<"4. Tampilkan semua lobby dan playernya"<<endl;
    cout<<"5. Cari dan tampilkan data pemain"<<endl;
    cout<<"6. Cek player dalam suatu lobby"<<endl;
    cout<<"7. Delete player"<<endl;
    cout<<"8. Delete All Full Lobby"<<endl;
    cout<<"0. Exit"<<endl;
    cout<< "Masukkan menu: ";
    int input = 0;
    cin >> input;

    return input;

}
