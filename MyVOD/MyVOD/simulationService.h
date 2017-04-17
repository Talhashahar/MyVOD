#pragma once
#ifndef simulationService_h
#define simulationService_h

#include "clientService.h"
#include "playerService.h"
#include <string>

using namespace std;


class simulationService
{
private:
	SmartPtr <clientService> _clientServer;
	SmartPtr <playerService> _playerServer;

	//private function for parseing (using by loaddata funcation)
	void parseSeries(char *seriesFileName);
	void parseMovie(char *seriesFileName);
	void parseClient(char *seriesFileName);
	void parseSimulation(char *seriesFileName);
public:
	simulationService();
	~simulationService();
	void update();
	void loadData(char* clientFile, char* moviesFile, char* seriesFile, char* simulationFile);
	bool executeSimulation();
};



#endif