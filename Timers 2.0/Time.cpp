#include "Time.h"

Time::Time(int h, int m) : hour{ h }, minute{ m } {}; 

Time Time::operator++()
{
	minute++; 

	if (hour > 23)
	{
		hour = 0;
	}; 

	if (minute > 59)
	{
		minute = 0;
		hour++;
	}; 

	return *this;
}

Time Time::operator--()
{
	if ((hour == 0) && (minute == 0))
	{
		minute = 0;
		hour = 0;
	}
	else if ((hour >= 0) && (minute >= 0))
		{
			minute--;
		};

	

	if (hour < 0)
	{
		hour = 0;
		minute = 0; 
	};

	if (minute < 0)
	{
		minute = 59;
		hour--;
	};

	return *this;
}