#include<bits/stdc++.h>
using namespace std;
int dfg(int o[],int n,int m,int max)
{
	int y;
	if (m == 2)
	{
		int y;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				y = o[i]&o[j];
				if(y > max)
				{
					max = y;
				}
			}
		}
	}
	else
	{
		for(int j = 0; j < n; j++)
		{
			y = y&o[j];
			if(y > max)
			{
				max = y;
			}
		}
		dfg(o, m--, max);
	}
	return max;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, max = 0;
	int o[1000];
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>o[i];
	}
	int r = dfg(o,n,  m, max);
	cout<<r;
	return 0;
}
