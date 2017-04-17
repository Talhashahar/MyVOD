class viewAble;
#pragma once
#ifndef client_h
#define client_h
#include <string>
#include <iostream>
#include "SmartPtr.h"
#include "viewAble.h"

using namespace std;


class client
{
private:
	string _id;
	string _name;
	string _location;
	SmartPtr <viewAble> _currentViewAble;
public:
//	client();
	client(string id, string name, string location, SmartPtr <viewAble> _currentView);
	bool playViewAble();
	~client();
};

#endif