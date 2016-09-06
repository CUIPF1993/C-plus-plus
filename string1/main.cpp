// mian.cpp : 定义控制台应用程序的入口点。
//main.cpp -- using expanded String class
//compile with string1.cpp

#include "stdafx.h"
#include<iostream>
#include"string1.h"

const int ArSize = 10;
const int Maxlen = 81;
int main()
{
	using::std::cout;
	using::std::cin;
	using::std::endl;

	String name;
	cout << "Hi,what's your name?\n";
	cin >> name;

	cout << name << ",please enter uo to" << ArSize
		<< " short saying <empty line to quit>:\n";
	String saying[ArSize];		//array of object
	char temp[Maxlen];			//temporary string storage
	int i;

	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, Maxlen);
		while (cin &&cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')		//empty line?
			break;			//i not incremented
		else
			sayings[i] = temp;			//overloaded assignment
	}
	int total = i;			//toatal # of lines read

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i =0; i<total;i++)
		{
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		}
		int shortest = 0;
		int first = 0;
		for (i = 0; i < total; i++)
		{

		}
	}

	return 0;
}

