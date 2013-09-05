// Array.cpp : ��������̨Ӧ�ó��������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
int get_max_length(vector<int> &A);
void printArray(vector<int> &A);
int get_max_length_liner_time(vector<int> &A);
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

    printArray(A);
	cout<<get_max_length(A)<<endl;
    cout<<get_max_length_liner_time(A)<<endl;
	return 0;
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
int get_max_length(vector<int> &A)
{
	int n = A.size();
	int pos_i = 0,pos_j = 0;
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
				break;
			}
		}
	}
	return max_length;
}

int get_max_length_liner_time(vector<int> &A)
{
    int n = A.size();
    vector<int> left_max_index(n,0);
    left_max_index[n-1] = n-1;
    for(int i = n-2;i>=0;i--)
    {
        if(A[i] <= A[left_max_index[i+1]])
        {
            left_max_index[i] = left_max_index[i+1];
        }
        else
        {
            left_max_index[i] = i;
        }
    }
    cout<<"left_max_index ";
    printArray(left_max_index);
    int i=0,j=0,max_length = 0;
    while(j<n)
    {
        j = left_max_index[j];
        if(A[j]>=A[i])
        {
            if(j - i > max_length)
            {
                max_length = j - i;
            }
            j++;
        }
        else
        {
            i++;
        }
    }
    return max_length;
}