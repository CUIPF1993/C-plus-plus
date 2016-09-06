//brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
//Brass Acount Class

class Brass
{
private:
	std::string fullName;	//用户姓名
	long acctNum;			//账号
	double balance;			//账户结余
public:
	Brass(const std::string & s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);		//存款
	virtual void Withdraw(double amt);		//取款
	double Balance() const;		//账户结余
	virtual void ViewAcct() const;
	virtual ~Brass();
};

//Brass Plus Account Class
class BrassPlus :public Brass
{
private:
	double maxLoan;		//透支限额
	double rate;		//透支贷款利率
	double owesBank;	//当前的透支总额
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0;}
};

#endif // !BRASS_H_
