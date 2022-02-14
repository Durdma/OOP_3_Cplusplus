#pragma once

class Time
{

private:

	int m_hours;
	int m_minutes;
	int m_seconds;

public:

	Time(int, int, int);
	~Time();

	int getHourse(){ return m_hours; };
	int getMinutes(){ return m_minutes; };
	int getSeconds(){ return m_seconds; };

	Time operator+=(int minutes);

	friend bool operator==(const Time &One, const Time &Two);
	friend Time operator-(Time &One, Time &Two);

};



// START OF CONSTRUCTORS AND DESTRUCTORS

Time::Time(int hourse = 0, int minutes = 0, int seconds = 0)
	: m_hours{hourse}, m_minutes{minutes}, m_seconds{seconds}
{}

Time::~Time()
{}

// END OF CONSTRUCTORS AND DESTRUCTORS



// START OF OVERLOADS

Time Time::operator+=(int minutes)
{
	
	m_minutes += minutes;

	if (m_minutes >= 60)
	{

		m_hours += m_minutes / 60;

		m_minutes = m_minutes % 60;

		if (m_hours >= 24)
		{

			m_hours = m_hours % 24;

		}

	}
	
	return Time();

}

bool operator==(const Time &One, const Time &Two)
{

	if ((One.m_hours == Two.m_hours) && (One.m_minutes == Two.m_minutes) 
		&& (One.m_seconds == Two.m_seconds))
	{

		return true;

	}

	return false;

}

Time operator-(Time &One, Time &Two)
{

	Time res{};

	res.m_hours		= One.m_hours - Two.m_hours;
	res.m_minutes	= One.m_minutes - Two.m_minutes;
	res.m_seconds	= One.m_seconds - Two.m_seconds;

	if (res.m_hours < 0)
	{

		res.m_hours = (-res.m_hours);

	}

	if (res.m_minutes < 0)
	{

		res.m_minutes = (-res.m_minutes);

	}

	if (res.m_seconds < 0)
	{

		res.m_seconds = (-res.m_seconds);

	}

	return res;

}

// END OF OVERLOADS

