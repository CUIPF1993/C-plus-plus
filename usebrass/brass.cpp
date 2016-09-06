//brass.cpp -- bank accout class methods
#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

//fromating stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass methods
Brass::Brass(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}
void Brass::Deposit(double amt)		//存款
{
	if (amt < 0) 
	{
		cout << "Negative deposit not allowed; "
			<< "deposit is cancelled.\n";
	}
	else
	{
		balance += amt;
	}
}
void Brass::Withdraw(double amt)		//取款
{
	//set up ###.##format
	format initializeState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdraw amount must be positive; "
			<< "withdraw canceled.\n";
	}
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else 
	{
		cout << "Withdraw amount of $" << amt
			<< "exceeds your balance.\n"
			<< "Withdraw canceled.\n";
	}
}
double Brass::Balance() const		//结余
{
	return balance;
}
void Brass::ViewAcct() const
{
	//set up ###.## format
	format initializeState = setFormat();
	precis prec = cout.precision(2);

	cout << "Client: " << fullName << endl;
	cout << "Amount Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initializeState, prec);
}

//BrassPlus Methods

BrassPlus::BrassPlus(const std::string & s, long an,
	double bal, double ml, double r) :Brass(s, an, bal)
{
	maxLoan = ml;		//透支限额
	owesBank = 0.0;		//透支总额
	rate = r;			//透支利率
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r): 
					Brass(ba)	//uses implict copy constructor
{
	maxLoan = ml;		//透支限额
	owesBank = 0.0;		//透支总额
	rate = r;			//透支利率
}
//readfine how ViewAcct() const
void BrassPlus::ViewAcct() const
{
	// set up ###.## format
	format initializeState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();		//display base portion
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);		// ###.### format
	cout << "Loan Rate" << 100 * rate << "%\n";
	restore(initializeState, prec);
}
//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	// set up ###.## format
	format initializeState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass:Withdraw(amt);
	}
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0* rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance* rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded. Transaction cancelled.\n";
		restore(initializeState, prec);
	}
}
format setFormat()
{
	// set up ###.## format
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p)
{
	cout.setf(f,std::ios_base::floatfield);
	cout.precision(p);
}


