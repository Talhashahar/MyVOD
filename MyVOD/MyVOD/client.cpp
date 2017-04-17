#include "client.h"
//testing push


client::client(string id, string name, string location, SmartPtr <viewAble> _currentView)
{
	_id = id;
	_name = name;
	_location = location;
	_currentViewAble = _currentView;
}


client::~client()
{
}
