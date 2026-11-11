#include<bits/stdc++.h>
using namespace std;
struct fm
{
	int num;
	int f=0;
};
int main()
{
	int n,m,a[500001],g[500001]={-1},t;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	fm s[300001];
	for(int i=0;i<m;i++)
	{
		s[i].num=i;
	}
	for(int i=0;i<n;i++)
	{
		int f=0,t=a[i];
		for(int j=0;j<i;j++)
		{
			if(g[j]==t)
			{
				f=j;
			}
		}
		if(f!=0)
		{
			for(int j=f;j<n;j++)
			{
				g[j]=0;
			}
			g[f]=t;
		}
		else
		{
			
		}
	}
	return 0;
}
