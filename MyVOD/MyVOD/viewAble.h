class client;
#pragma once
#ifndef viewAble_h
#define viewAble_h

#include <vector>;
using namespace std;
#include "client.h"
#include "SmartPtr.h"

class viewAble
{
private:
	string _name;
	string _id;
	int _playRunTime;
	vector <client> _currentlyWatchMe;
public:
	viewAble(string name, string id, int playRunTime);
	viewAble();
	virtual string getInfo() = 0;								//pure abstract class 
	string getID();
	bool Register (SmartPtr<client> Client);
	bool unregister(string id);
	virtual bool play() = 0;
	~viewAble();
};

class series : public viewAble
{
private:
	int season;
	int episode;
};

class movies : public viewAble
{
private:
	bool oscarWinner;
};


#endif