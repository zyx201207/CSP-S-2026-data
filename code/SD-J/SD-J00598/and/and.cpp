#include<bits/stdc++.h>
//#include<iostream>
//#include<string>
using namespace std;

//int big(long long x,long long y)
//{
//	if(x>=y)
//	{
//		return x;
//	}
//	else
//	{
//		return y;
//	}
//}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n = 0;
	long long max = 0;
	int a[200002] = {};
	//int b[200002] = {};
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];	
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = i;j < m;j++)
		{
			for(int k = j;k < m;k++)
			{
				if((a[j] & a[j+1]) >= max)
				{
					max = (a[j] & a[j+1]);
				}
			}
		}
	}
	cout << max;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
