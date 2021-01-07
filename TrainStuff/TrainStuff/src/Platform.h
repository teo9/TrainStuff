#pragma once
#include "Train.h"

enum PlatformType { Standard = 0, Transit = 1};

class Platform
{

public:
	Platform(PlatformType type, TrackType track,int maxSpeed);
private:
	PlatformType type;
	TrackType track;
	Train* treno;
	float stoppingTime;
	int maxSpeed;
};

