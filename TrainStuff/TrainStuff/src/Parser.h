#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Train.h"
#include "Station.h"
#include "Platform.h"

const std::string TIMETABLE = ".\\Files\\timetable.txt";
const std::string LINE_DESCRIPTION = ".\\Files\\line_description.txt";

std::vector<std::string> GetLines(const std::string filename);
std::vector<std::string> Parse(std::string line);
std::vector<Train*> GetTrains();
std::vector<Station*> GetStations();