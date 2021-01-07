#include "TimeManagement.h"


int Getminutes(int maxSpeed, Station* a, Station* b, bool transito) {
	int time = 0;
	int posA = a->GetPosition();
	int posB = b->GetPosition();
	int c = posA - posB;
	int distance = c < 0 ? posB - posA : c;
	if (!transito)
	{
		distance -= 10; // KM con limite del binario
		time += 10 / (80/60);
	}
	time += distance / (maxSpeed/60);
	return time;
}

std::string GetTime(int minutes)
{
	int m = minutes % 60;
	int h = (minutes - m) / 60;
	std::string hh = h < 10 ? "0"+ std::to_string(h) : std::to_string(h);
	std::string mm = m < 10 ? "0" + std::to_string(m): std::to_string(m);
	std::string result = hh + ":" + mm;
	return result;
}

