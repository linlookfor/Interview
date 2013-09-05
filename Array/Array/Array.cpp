// Array.cpp : ��������̨Ӧ�ó��������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> A;
	A.push_back(6);
	A.push_back(4);
	A.push_back(7);
	A.push_back(8);
	A.push_back(3);
	A.push_back(2);
	A.push_back(5);
	cout<<get_max_length(A)<<endl;
	return 0;
}

int get_max_length(vector<int> &A)
{
	int n = A.size();
	int pos_i,pos_j;
	int max_length = 0;
	for(int i=0; i < n; i++)
	{
		for(int j=n-1;j > pos_j;j--)
		{
			if(A[j] >= A[i])
			{
				pos_i = i;
				pos_j = j;
				max_length = j - i;
			}
		}
	}
}
