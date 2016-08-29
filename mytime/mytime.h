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
	//���ؼӺ��������
	Time operator+(const Time &t)const;
	Time operator-(const Time &t)const;
	Time operator*(double mult)const;
	void Show()const;
	//��Ԫ����������*�������
	friend Time operator*(double m,const Time &t)
	{
		return t * m;
	}
	//��Ԫ���������ء��������
	friend std::ostream & operator<<(std::ostream & os, const Time &t);
};
#endif // !
