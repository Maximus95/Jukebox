
#include "stdafx.h"
#include "Song.cpp"
#include <iostream>

using namespace std;

struct Node {
	Song *song;
	Node *next;
};

class songL {
public:

	int plSize;
	Node *head;

	songL() {
		this->head = NULL;
		this->plSize = 0;
	}

	Song* getSongIn(int index) {
		Node* current = head;
		if (plSize != 0){
			if (index>0 && index <= plSize) {
				for (int i = 0; i<index - 1; i++) {
					current = current->next;
				}
				return current->song;
			}
			else {
				return NULL;
			}
		}
		else {
			return NULL;
		}
	}

	void displayall(){
		if (plSize == 1) {
			cout << plSize << " song is available" << endl;
		}
		else if (plSize == 0) {
			cout << "List is empty" << endl;
		}
		else {
			cout << plSize << " available song" << endl;
		}

		cout << endl;

		Node *current = head;

		for (int i = 0; i<plSize; i++) {
			cout << i + 1 << " " << current->song->songName << " - " << current->song->songAtrist << " " << current->song->releasedDate << " ";
			cout << " - ";

			if (current->song->releasedDate >= 2016) {
				cout << "1 rm" << endl;
			}
			else {
				cout << "available for free" << endl;
			}

			current = current->next;
		}

		if (plSize != 0) {
			cout << endl;
		}
	}

	void insertSong(Song* song) {
		Node* newNode = new Node;
		newNode->song = song;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node *last = head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = newNode;
		}
		plSize++;

		cout << "The song has beed added" << endl;
		cout << endl;
	}

	void deletePlaylistS(int index){
		if (plSize != 0) {
			if (index <= plSize) {
				if (index == 1) {
					if (plSize > 0) {
						Node *toBeDeleted = head;
						head = head->next;
						delete toBeDeleted;
						plSize--;

						cout << "The song has been  deleted from the songList!" << endl;
						cout << endl;
					}
				}
				else if (index == 0) {
					cout << "The id number is not available!" << endl;
					cout << endl;
				}

				else {
					Node *prev = NULL, *toDelete = head;
					for (int i = 0; i < index - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					plSize--;

					cout << "The song has been  deleted from the songList!" << endl;
					cout << endl;
				}
			}
			else {
				cout << "The id number is out of bounds!" << endl;
				cout << endl;
			}
		}
		else {
			cout << "There are no songs available!" << endl;
			cout << endl;
		}
	}
};

class playListQ {
public:
	int plSize;
	Node *head;

	playListQ(){
		this->head = NULL;
		this->plSize = 0;
	}

	void displayall(){
		cout << " QUEUE PLAYLIST " << endl;

		if (plSize == 0) {
			cout << "List is empty" << endl;
		}

		cout << endl;

		Node *current = head;

		for (int i = 0; i<plSize; i++) {
			cout << i + 1 << ". " << current->song->songAtrist << " - " << current->song->songName << " " << current->song->releasedDate << " ";

			if (current->song->releasedDate >= 2016) {
				cout << "1 rm" << endl;
			}
			else {
				cout << "avaiable for free" << endl;
			}

			current = current->next;
		}

		if (plSize != 0) {
			cout << endl;
		}
	}

	void addAsLast(Song* song) {
		Node* newNode = new Node;
		newNode->song = song;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node *last = head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = newNode;
		}
		plSize++;
	}

	void deletePlaylistS(int index){
		if (plSize != 0) {
			if (index <= plSize) {
				if (index == 1) {
					if (plSize > 0) {
						Node *toBeDeleted = head;
						head = head->next;
						delete toBeDeleted;
						plSize--;

						cout << "The song has been  deleted from the playlist!" << endl;
						cout << endl;
					}
				}
				else if (index == 0) {
					cout << "Wrong ID number" << endl;
					cout << endl;
				}

				else {
					Node *prev = NULL, *toDelete = head;
					for (int i = 0; i < index - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					plSize--;

					cout << "The song has been  deleted from the  playlist!" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}
		}
		else {
			cout << "Invalid input" << endl;
			cout << endl;
		}
	}
};

class playListS {
public:

	int plSize;
	Node *head;

	playListS(){
		this->head = NULL;
		this->plSize = 0;
	}

	void displayall(){
		cout << " STACK PLAYLIST " << endl;

		if (plSize == 0) {
			cout << "List is empty" << endl;
		}

		cout << endl;

		Node *current = head;

		for (int i = 0; i<plSize; i++) {
			cout << i + 1 << ". " << current->song->songAtrist<< " - " << current->song->songName << " " << current->song->releasedDate << " ";
			if (current->song->releasedDate > 2016) {
				cout << "1 rm" << endl;
			}
			else {
				cout << "available for free" << endl;
			}

			current = current->next;
		}

	}

	void insertAsFirst(Song* song){
		Node* newNode = new Node;
		newNode->song = song;
		newNode->next = head;
		head = newNode;
		plSize++;
	}

	void deletePlaylistS(int index){
		if (plSize != 0) {
			if (index <= plSize) {
				if (index == 1) {
					if (plSize > 0) {
						Node *toBeDeleted = head;
						head = head->next;
						delete toBeDeleted;
						plSize--;

						cout << "The song has been  deleted the  playlist!" << endl;
						cout << endl;
					}
				}
				else if (index == 0) {
					cout << "Invalid input" << endl;
					cout << endl;
				}

				else {
					Node *prev = NULL, *toDelete = head;
					for (int i = 0; i < index - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					plSize--;

					cout << "The song has been  deleted from the  playlist!" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}
		}
		else {
			cout << "Invalid input" << endl;
			cout << endl;
		}
	}
};

