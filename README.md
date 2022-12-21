# Tugas Besar Struktur Data Kelompok 15
## Anggota Kelompok
- Andry Nur Falah (1302213005)
- Herlin Priatna  (1302213018)
## Studi Kasus
Dalam suatu game online multiplayer, pemain akan bertanding melawan 3 pemain lainnya. Untuk memastikan pertandingan yang adil, maka diperlukan sistem yang dapat mencocokan pemain-pemain dengan kemampuan yang serupa dalam satu pertandingan. Sistem yang akan digunakan dalam studi kasus ini adalah Rank-Based Matchmaking yakni sistem yang akan mencocokan pemain dengan rank yang sama pada satu lobby.
## Ilustrasi
![alt text](https://github.com/andryfall/Tubes-Struktur-Data/blob/main/Ilustrasi.PNG)
## Spesifikasi
### userList (child)
userList adalah single circular linked list yang akan menyimpan data pemain berupa :
- userName()
- userId()
- Rank()
- lobby() penguhubung ke lobbyList
### lobbyList (Parent)
lobbyList adalah single linked list yang akan menyimpan data lobby berupa :
- idLobby()
- totalPemain()
- Rank()
### Fungsionalitas
- createAccount()   : Membuat akun baru berdasar input user dan disimpan di userList
- createLobby()     : Membuat lobby baru yang akan disimpan lobbyList
- findUser()        : Mencari data user pada userList berdasar userID()
- findUserInLobby() : Mencari data user pada lobby berdasar userID()
- joinGame()        : Menghubungkan user(child) ke lobby(parent) dengan data Rank() yang sama. Apabila tidak ditemukan Rank() yang sama pada lobbyList, maka akan                             memanggil createLobby() untuk membuat lobby baru dengan Rank() tersebut.
- deleteAccount()   : Menghapus data akun user dari userList
- removePlayer()    : Mengeluarkan user dari lobby (delete child dari parent)
- deleteLobby()     : Menghapus data lobby
- showAllLobby()    : show semua data lobby(parent)
- findLobby()       : Mencari lobby dengan menggunakan idLobby()
- showLobbyData()   : menampilkan data sebuah lobby, menggunakan findLobby() untuk pencariannya
- Main()
