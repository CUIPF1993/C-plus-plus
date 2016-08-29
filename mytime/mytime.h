#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m = 0);
	//重载加号运算符。
	Time operator+(const Time &t)const;
	Time operator-(const Time &t)const;
	Time operator*(double mult)const;
	void Show()const;
	//友元函数：重载*运算符。
	friend Time operator*(double m,const Time &t)
	{
		return t * m;
	}
	//友元函数：重载《运算符。
	friend std::ostream & operator<<(std::ostream & os, const Time &t);
};
#endif // !
