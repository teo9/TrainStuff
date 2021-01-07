#include "Station.h"

Station::Station(std::string name, int position, StationType type, int defplatform, int transitplatform) 
{
	this->name = name;
	this->KmPosition = position;
	this->type = type;
	int element = defplatform + transitplatform;
	Platform** tempplatform = new Platform * [element];
	int index = 0;
	for (int i = 0; i < defplatform; i++)
	{
		Platform p1 = Platform(PlatformType::Standard , TrackType::Return,80);
		tempplatform[i++] = &p1;
		Platform p2 = Platform(PlatformType::Standard , TrackType::Single,80);
		tempplatform[i++] = &p2;
	}	
	for (int i = 0; i < transitplatform; i++)
	{
		Platform p1 = Platform(PlatformType::Transit, TrackType::Return, 10000);
		tempplatform[i++] = &p1;
		Platform p2 = Platform(PlatformType::Transit, TrackType::Single, 1000);
		tempplatform[i++] = &p2;
	}
	this->platform = tempplatform;
}
