
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Lists.cpp"

using namespace std;

class SongMachine {
public:
	SongMachine(){
		cout << "===  SongMachine ===" << endl;
		displayMenu();
	}

private:
	playListQ q;
	playListS st;
	songL songlist;

	void displayMenu(){
		cout << "==  MENU ==" << endl;

		int option = 0;

		cout << " 1- Playlist" << endl;
		cout << " 2- Songs" << endl;
		cout << " 3- Exit" << endl;

		cin >> option;

		if (option == 1) {
			displayPlaylist();
		}
		else if (option == 2) {
			displaySongs();
		}
		else if (option == 3) {
			cout << "End" << endl;
		}
		else {
			cout << "Error" << endl;
			displayMenu();
		}
	}

	void displayPlaylist(){
		cout << "== PlayList ==" << endl;

		st.displayall();
		q.displayall();

		int option;

		cout << " 1- PlayList:Add Song" << endl;
		cout << " 2- PlayList:Delete song" << endl;
		cout << " 3- Main menu" << endl;

		cin >> option;

		if (option == 1) {
			int id;

			cout << "Enter the song ID";
			cin >> id;

			Song *song = NULL;

			song = songlist.getSongIn(id);

			if (song != NULL){
				st.insertAsFirst(song);
				q.addAsLast(song);

				cout << "The song has been added!" << endl;
				cout << endl;
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}

			displayPlaylist();
		}
		else if (option == 2) {
			int id;

			cout << "Playlist: Which song do you want delete?: ";
			cin >> id;

			if (id != 0 && id <= q.plSize) {
				q.deletePlaylistS(id);
				st.deletePlaylistS(id);

				cout << "Songs have been deleted!" << endl;
				cout << endl;
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}

			displayPlaylist();
		}
		else if (option == 3) {
			displayMenu();
		}
		else {
			cout << "Invalid input" << endl;
			cout << endl;

			displayPlaylist();
		}
	}

	void displaySongs() {
		cout << " SONGS " << endl;

		songlist.displayall();

		int option;

		cout << " 1- Add new song" << endl;
		cout << " 2- Delete song" << endl;
		cout << " 3- Main menu" << endl;

		cin >> option;

		if (option == 1) {
			string songName, songAtrist;
			int releasedDate;

			cout << "Name of the song: ";
			cin >> songName;

			cout << "songAtrist: ";
			cin >> songAtrist;

			cout << "Realesed Date: ";
			cin >> releasedDate;

			Song* song = new Song(songName, songAtrist, releasedDate);

			songlist.insertSong(song);

			displaySongs();
		}
		else if (option == 2) {
			if (songlist.plSize == 0){

				cout << "There are no songs available!" << endl;
				cout << endl;

				displaySongs();
			}
			else {

				int id;

				cout << "Which song do you want delete?:";
				cin >> id;

				songlist.deletePlaylistS(id);
				displaySongs();
			}
		}
		else if (option == 3) {
			displayMenu();
		}
		else {
			cout << "Invalid input" << endl;
			cout << endl;

			displaySongs();
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	SongMachine *songmachine = new SongMachine();
	return 0;
}

