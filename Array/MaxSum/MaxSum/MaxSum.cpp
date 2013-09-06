// MaxSum.cpp : ��������̨Ӧ�ó��������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
#typedef vector<int> IntArray

int maxSum(IntArray &A);

int _tmain(int argc, _TCHAR* argv[])
{
	IntArray A;
	A.push_back(5);
	A.push_back(3);
	A.push_back(-1);
	A.push_back(7);
	A.push_back(0);
	return 0;
}

int maxSum(IntArray &A)
{
	int n = A.size();
	if(n <= 0)
		return 0;
	IntArray max_sum(n+1,0);//max_sum[i] : maxSum of first i element
	max_sum[1] = A[0] > max_sum[0] ? A[0] : max_sum[0]; 
	for(int i=1;i<n;i++)
	{
		int sum_with_i = max_sum[i-1] + A[i];
		int sum_without_i = max_sum[i];
		max_sum[i+1] = max(sum_with_i,sum_without_i);
	}
	return max_sum[n];
}
