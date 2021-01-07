#include "Parser.h"


std::vector<std::string> GetLines(const std::string filename)
{
	std::vector<std::string> result = std::vector<std::string>{};
	std::ifstream input;
	input.open(filename);
	while (!input.eof())
	{
		std::string line;
		std::getline(input, line);
		result.push_back( line );
	}
	return result;
}

std::vector<std::string> Parse(std::string line)
{
	std::vector<std::string> result = std::vector<std::string>{};
	std::string element = "";
	for (int i = 0; i < line.size(); i++)
	{
		char c = line.at(i);
		if (c == ' ')
		{
			result.push_back(element);
			element = "";
		}
		else
		{
			c = c == '_' ? ' ' : c; // remove underscore
			element += c;
		}

		if (i == line.size() - 1)
			result.push_back(element);
	}
	return result;
}

std::vector<Train*> GetTrains()
{
	std::vector<std::string> lines = GetLines( TIMETABLE );
	std::vector<Train*> trains = std::vector<Train*>{};
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> elem = Parse(lines.at(i));
		int id = stoi( elem.at(0));
		TrackType track = (TrackType)stoi(elem.at(1));
		TrainType type = (TrainType)stoi(elem.at(2));
		Train* train = nullptr;
		switch (type)
		{
		case TrainType::Regional:
			train = new RegionalTrain(id, track);
			trains.push_back(train);
			break;
		case TrainType::High_Speed:
			train = new HighSpeedTrain(id, track);
			trains.push_back(train);
			break;
		case TrainType::Super:
			train = new SuperTrain(id, track);
			trains.push_back(train);
			break;
		}
		std::vector<int> orari = std::vector<int>{};
		for (int i = 3; i < elem.size(); i++) {
			orari.push_back( stoi( elem.at(i) ) );
		}
		train->SetOrari(orari);
	}
	return trains;
}

std::vector<Station*> GetStations()
{
	std::vector<std::string> lines = GetLines(LINE_DESCRIPTION);
	std::vector<Station*> stations = std::vector<Station*>{};
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> elem = Parse(lines.at(i));
		std::string name = elem.at(0);
		int pos = stoi(elem.at(1));
		StationType type = (StationType)stoi(elem.at(2));
		Station* station = new Station();
		switch (type)
		{
		case StationType::Local:
			*station = LocalStation(name, pos);
			stations.push_back(station);
			break;
		case StationType::Main:
			*station = MainStation(name, pos);
			stations.push_back(station);
			break;
		}
	}
	return stations;
}