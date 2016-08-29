#include <iostream>
#include "stock00.h"


//管理对某公司股票的首次购买。
void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative;"
			<< company << "shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_value = pr;
	set_tot();
}
//管理增加股票持有。
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout <<"Number of shares can't be negative;"
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_value = price;
		set_tot();
	}
}
//管理减少股票持有。
void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		std::cout << "Number of shares can't be negative;"
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		shares -= num;
		share_value = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_value = price;
	set_tot();
}
//重新设置公司的股票价值。
void Stock::show()
{
	std::cout << "Company: " << company
		<< " shares: " << shares << '\n'
		<< "share price :$" << share_value
		<< "Total worth :$" << total_value << '\n';

}
