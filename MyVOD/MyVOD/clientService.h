#pragma 
#ifndef clientService_h
#define clientService_h
#include <vector>

#include "client.h"

class clientService
{
	vector <client> _clients;
public:
	clientService();
	void addClient (SmartPtr<client> newClient);
	~clientService();
};

#endif

