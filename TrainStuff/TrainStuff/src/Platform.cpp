#include "Platform.h"

Platform::Platform(PlatformType type, TrackType track,int maxSpeed)
{
	this->stoppingTime = 0;
	this->treno = nullptr;
	this->type = type;
	this->track = track;
	this->maxSpeed = maxSpeed;
}