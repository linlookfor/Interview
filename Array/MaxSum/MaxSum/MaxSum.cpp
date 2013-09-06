// MaxSum.cpp 
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> IntArray;
typedef vector<bool> BoolArray;

int maxSum(IntArray &A);
void printArray(vector<int> &A);

int _tmain(int argc, _TCHAR* argv[])
{
	IntArray A;
	A.push_back(-1);
	A.push_back(3);
	A.push_back(5);
	A.push_back(3);
	A.push_back(-1);
	A.push_back(7);
	A.push_back(1);
	A.push_back(4);
	printArray(A);
	cout<<"NonAdjacentElementMaxSum:"<<maxSum(A)<<endl;
	return 0;
}

//dynamic programming
int maxSum(IntArray &A)
{
	int n = A.size();
	if(n <= 0)
		return 0;
	IntArray max_sum(n,0);
	max_sum[0] = A[0] > 0 ? A[0] : 0; 
	if (n > 1)
	{
		max_sum[1] = A[1] > max_sum[0] ? A[1] : max_sum[0]; 
	}
	for(int i=2;i<n;i++)
	{
		int sum_with_i = max_sum[i-2] + A[i];
		int sum_without_i = max_sum[i-1];
		max_sum[i] = max(sum_with_i,sum_without_i);
	}
	return max_sum[n-1];
}

void printArray(vector<int> &A)
{
	cout<< "Array:";
	for(vector<int>::iterator it=A.begin();it!=A.end();it++)
	{
		cout<<*it;
		cout<<" ";
	}
	cout<<endl;
}