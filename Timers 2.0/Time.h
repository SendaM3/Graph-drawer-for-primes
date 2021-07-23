#pragma once
class Time
{
public: 
	Time(int hour, int minute); 
	Time operator++(); 
	Time operator--();

	int hour;
	int minute; 
	
};
/*
className& className::operator++()
{
	classAttribute++;
	return *this;
}
*/