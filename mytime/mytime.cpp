
#include <iostream>
#include"mytime.h"

Time::Time()
{
	hours = 0;
	minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
Time Time::operator+(const Time &t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = t.hours+ hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator-(const Time &t)const 
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.hours = (tot2 - tot1) / 60;
	diff.minutes = (tot2 - tot1) % 60;
	return diff;
}
//重载*运算符
Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}
void Time::Show()const
{
	std::cout << hours << "hours," << minutes << "minutes";
}
//友元函数
std::ostream & operator<<(std::ostream & os, const Time &t)
{
	os << t.hours << "hours," << t.minutes << "minutes";
	return os;
}