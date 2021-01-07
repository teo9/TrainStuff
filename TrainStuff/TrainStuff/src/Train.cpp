#include "Train.h"

Train::Train(int id, TrainType type, int speed, TrackType track)
{
	this->id = id;
	this->type = type;
	this->Maxspeed = speed;
	this->track = track;

	actualSpeed = 0;
	chilometer = 0;
}

std::vector<int> Train::GetOrari() {
	return this->orari;
}
void Train::SetOrari(std::vector<int> orari) {
	this->orari = orari;
}