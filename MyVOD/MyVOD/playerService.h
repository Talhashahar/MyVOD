#pragma once

#ifndef playerService_h
#define playerService_h

#include <vector>
#include "viewAble.h"

class playerService
{
private:
	vector <viewAble*> _database;
	int _requests;
public:
	playerService();
	~playerService();
	SmartPtr<viewAble*> requestViewable(string id);
	void addSeries(SmartPtr<series>);
	void addMovies(SmartPtr<movies>);
};


#endif