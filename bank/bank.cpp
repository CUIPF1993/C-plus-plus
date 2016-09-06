// bank.cpp : using the Queue interface
//compile with queue.cpp

#include "stdafx.h"
#include <iostream>
#include <cstdlib>		//for rand() and srand(0
#include <ctime>		//for time
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);		//is there a new customer

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	//setting thing up
	std::srand(std::time(0));		//random initialzing of rand()

	cout << "Case Study::Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);		//line queue holds up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours;			//hours of simulation
	cin >> hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;		//#of cycles

	Item temp;				//new coustomer data
	long turnways = 0;		//turned away by full queue
	long customers = 0;		//joined the queue
	long served = 0;		//served during the simulation
	int wait_time = 0;		//cumulative line length
	

    return 0;
}
bool newcustomer(double x)
{
	return (std::rand()* x / RAND_MAX < 1);
}

