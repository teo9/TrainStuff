#pragma once

#include "Station.h"

int Getminutes(int maxSpeed, Station*a, Station*b, bool transito);
std::string GetTime(int minutes);