#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,m,c[500002],p[500002]={0},mj[300002]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			p[j]=c[j];
		}
		for(int j=i;j<=n;j++)
		{
			for(int l=n;l>=j;l--)
			{
				if(p[j]==p[l])
				{
					for(int u=j;u<=l-1;u++) p[u]=0;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(p[j]!=0) mj[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mj[i]<<" ";
	}
	return 0;
}
