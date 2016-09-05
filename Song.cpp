
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Song {
public:
	string songName;
	string songAtrist;
	int releasedDate;

	Song(){}

	Song(string songName, string songAtrist, int releasedDate){
		this->songName = songName;
		this->songAtrist = songAtrist;
		this->releasedDate = releasedDate;
	}
};
