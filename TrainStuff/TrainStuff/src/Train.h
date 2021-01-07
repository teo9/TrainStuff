#pragma once
#include <vector>
enum TrainType { Regional = 1, High_Speed = 2, Super = 3 };
enum TrackType { Single = 0, Return = 1};

class Train
{
	public:
		Train(){}
		Train(int id, TrainType type, int speed, TrackType track);
		int GetId() { return id; }
		int GetMaximumSpeed() { return Maxspeed; }
		int GetActualSpeed() { return actualSpeed; }
		float GetActualPosition() { return chilometer; }
		TrainType GetType() { return type; }
		TrackType GetTrack() { return track; }
		std::vector<int> GetOrari();
		void SetOrari(std::vector<int> orari);
	protected:
		int id;
		int Maxspeed;
		int actualSpeed;
		float chilometer;
		TrainType type;
		TrackType track;
		std::vector<int> orari;
};


class RegionalTrain : public Train
{
public: 
	RegionalTrain(int id, TrackType track) : Train(id, TrainType::Regional, 160,track) {};

};

class HighSpeedTrain :public  Train
{
public:
	HighSpeedTrain(int id, TrackType track) : Train(id, TrainType::High_Speed, 240,track) {};

};

class SuperTrain :public  Train
{
public:
	SuperTrain(int id, TrackType track) : Train(id, TrainType::Super, 300,track) {};

};