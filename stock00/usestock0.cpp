// stock股票.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stock00.h"

int main()
{
	Stock cat;
	cat.acquire("NanoSmart", 20, 12.50);
	cat.show();
	cat.buy(15, 18.25);
	cat.show();
	cat.sell(400, 20.00);
	cat.show();
	cat.buy(30000, 40.125);
	cat.show();
    return 0;
}

