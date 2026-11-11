#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=500005;
int a[MAXN]={},b[300005]={};
int d[MAXN]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int c[300005]={};
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]>0)
			{
				for(int q=c[a[j]];d[q]!=0;q++)
				{
					c[d[q]]=0;
					d[q]=0;
					sum--;
				}
			}
			else
			{
				sum++;
				d[sum]=a[j];
				c[a[j]]=sum;
			}
		}
		for(int j=1;j<=sum;j++)
		{
			b[d[j]]++;
			d[j]=0;
		}
	}
	bool fir=true;
	for(int i=1;i<=m;i++)
	{
		if(fir)
		{
			cout<<b[i];
		}
		else
		{
			cout<<" "<<b[i];
		}
		fir=false;
	}
	return 0;
}
