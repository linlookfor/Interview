// IntegerDivide.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool integerDivide(int x,int &a,int &b,int &c);
int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,c,x;
	x = 33;
	if (integerDivide(x,a,b,c))
	{
		cout<<x<<" = 6*"<<a<<" + 9*"<<b<<" + 20*"<<c<<endl;
	}
	else
	{
		cout<<x<<"can not be divide by 6 9 20";
	}
	return 0;
}

bool integerDivide(int x,int &a,int &b,int &c)
{// 6a + 9b + 20c = x
//  0<= a < 9
//	0<= b < 20
//  0<= c
//==> 6*8 + 9*19 + 20c >= x
//==>c>=(x-6*8-9*19)/20 && 0 <= c &&  c<=x/20
	if (x<0)
	{
		return false;
	}
	for (c=max((x - 6*8 -9*19)/20,0);c <= x/20;c++)
	{
		int left_x = x - 20 * c;
		for (a=0;a<9;a++)
		{
			for (b=0;b<20;b++)
			{
				if(left_x == 6*a + 9*b)
					return true;
			}
		}
	}
	return false;
}
