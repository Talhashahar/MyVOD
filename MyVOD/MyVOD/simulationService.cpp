#include "simulationService.h"
#include <fstream>

simulationService::simulationService()
{
	this->_clientServer = new clientService;
	this->_playerServer = new playerService;
}


simulationService::~simulationService()
{
}


void simulationService::loadData(char* clientFile, char* moviesFile, char* seriesFile, char* simulationFile)
{
	this->parseClient(clientFile);
	this->parseMovie(moviesFile);
	this->parseSeries(seriesFile);
	//this->parseSimulation(simulationFile);
}

void simulationService::parseSeries(char* seriesFileName)
{
	string delimiter = " ";
	string delimiter1 = ",";
	string token;
	string tokens[5];
	int token_counter;
	string str;
	ifstream seriesFile(seriesFileName);
	size_t pos;
		
	while (!seriesFile.eof())
	{
		while (getline(seriesFile, str))
		{
			if ((str.length() == 0) || (str[0] == '#') || (str == delimiter))
			{
				continue;
			}
			token_counter = 0;
			pos = 0;
			while ((pos = str.find(delimiter1)) != string::npos)
			{
				token = str.substr(0, pos);
				tokens[token_counter] = token;
				token_counter++;
				str.erase(0, pos + delimiter1.length());

			}
			tokens[4] = str;
			//return tokens;
		}
	}
}


void simulationService::parseMovie(char* movieFileName)
{
	string delimiter = " ";
	string delimiter1 = ",";
	string token;
	string tokens[4];
	int token_counter;
	string str;
	ifstream moviesFile(movieFileName);
	size_t pos;
	
	while (!moviesFile.eof())
	{
		while (getline(moviesFile, str))
		{
			if ((str.length() == 0) || (str[0] == '#') || (str == delimiter))
			{
				continue;
			}
			token_counter = 0;
			pos = 0;
			while ((pos = str.find(delimiter1)) != string::npos)
			{
				token = str.substr(0, pos);
				tokens[token_counter] = token;
				token_counter++;
				str.erase(0, pos + delimiter1.length());
			}
			tokens[3] = str;
			cout << "WhatToPrint ? !? !? " << endl;;
			//return tokens;
		}
	
	
	
	}
}


void simulationService::parseClient(char* clientFileName)
{
	string delimiter = " ";
	string delimiter1 = ",";
	string token;
	string tokens[3];
	int token_counter;
	string str;
	ifstream clientFile(clientFileName);
	size_t pos;
	//client *newclient;
	while (!clientFile.eof())
	{
		while (getline(clientFile, str))
		{
			if ((str.length() == 0) || (str[0] == '#') || (str == delimiter))
			{
				continue;
			}
			token_counter = 0;
			pos = 0;
			while ((pos = str.find(delimiter1)) != string::npos)
			{
				token = str.substr(0, pos);
				tokens[token_counter] = token;
				token_counter++;
				str.erase(0, pos + delimiter1.length());
			}
			tokens[2] = str;

			//look ths i did here, i create a new smart ptr of client and push it to client server (vector of clients)
			SmartPtr<client> newClient(new client(tokens[0], tokens[1], tokens[2], NULL));
			this->_clientServer->addClient(newClient);
		}
	}
}