//string1.h -- fixed and argumented string class definition
#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	//constructors and other methers
	String(const char *s);		//constructor ���캯��
	String();					//default constructor Ĭ�Ϲ��캯��
	String(const String &);		//copy constructor ���ƹ��캯��
	~String();					//destructor ��������
	int length()const { return len; }

	//overloaded operator merhods
	String & operator=(const String &);		//constructor
	String & operator=(const char*);		//default constructor
	char & operator[](int i);				//copy constructor
	const char & operator[](int i)const;	//destructor

	//overloaded operator friends
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String &st);
	friend istream & operator>>(istream & is, const String &st);

	//static function
	static int HowMany();	
};

#endif