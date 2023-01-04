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

    p = searchPlayer(U, "Saya");
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;

    x.playerName = "Dia";
    x.rankPlayer = "Bronze";
    insertPlayer(U, newPlayer(x));

    p = searchPlayer(U, "Dia");
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;

    x.playerName = "Kami";
    x.rankPlayer = "Silver";
    insertPlayer(U, newPlayer(x));

    p = searchPlayer(U, "Kami");
    cout <<infoPlayer(p).playerName<<endl;
    cout <<infoPlayer(p).rankPlayer<<endl;

    cout<<endl;

    adrPlayer t = first(U);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;



    cout<<endl;

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

    p = searchPlayer(U, "Kami");
    deletePlayer(U, p);

    t = first(U);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;
    t = nextPlayer(t);
    cout<<infoPlayer(t).playerName<<endl;

    n = first(L);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);

    insertLobby(L, newLobby(3, 0, "Silver"));
    insertLobby(L, newLobby(4, 0, "Silver"));
    insertLobby(L, newLobby(5, 0, "Silver"));

    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);

    n = first(L);
    while(n != NULL){
        if(infoLobby(n).nomor == 4){
            deleteLobby(L, n);
        }
        n = nextLobby(n);
    }

    n = first(L);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
    cout<<infoLobby(n).nomor<<endl;
    n = nextLobby(n);
