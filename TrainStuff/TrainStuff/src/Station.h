#pragma once
#include <string>
#include "Platform.h"

enum StationType { Local = 0, Main = 1 };

class Station
{
public:
	Station(){}
	Station(std::string name, int position,StationType type, int defplatform, int transitplatform);
	std::string GetName() { return name; }
	StationType GetType() { return type; }
	int GetPosition(){ return KmPosition; }
	Platform* GetPlatform(int pos) { return platform[pos]; }
protected:
	StationType type;
	std::string name;
	Platform** platform;
	int KmPosition;
};

class MainStation :public  Station
{
public:
	MainStation(std::string name, int position) : Station(name,position, StationType::Main,4,2 ) {}
};

class LocalStation :public  Station
{
public:
	LocalStation(std::string name, int position) : Station(name, position, StationType::Local,4,0) {}
};