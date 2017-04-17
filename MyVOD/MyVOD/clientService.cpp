#include "clientService.h"


clientService::clientService()
{
}


clientService::~clientService()
{
}


void clientService::addClient(SmartPtr<client> newClient)
{
	this->_clients.push_back(*(newClient.GetPtr()));
}