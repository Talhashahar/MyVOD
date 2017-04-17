#include "client.h"
#include "SmartPtr.h"
#include "viewAble.h"
#include "simulationService.h"

int main(int argc, char** argv)
{
	cout << "xxx" << endl;
	simulationService * simulservice;
	simulservice = new (simulationService);
	try
	{
		simulservice->loadData(argv[1], argv[2], argv[3], argv[4]);
	}
	catch (...)
	{
		cout << "failed to read one of text file, exit from program" << endl;
	}



};