#include <iostream>
#include "stock00.h"


//�����ĳ��˾��Ʊ���״ι���
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
//�������ӹ�Ʊ���С�
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
//������ٹ�Ʊ���С�
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
//�������ù�˾�Ĺ�Ʊ��ֵ��
void Stock::show()
{
	std::cout << "Company: " << company
		<< " shares: " << shares << '\n'
		<< "share price :$" << share_value
		<< "Total worth :$" << total_value << '\n';

}
