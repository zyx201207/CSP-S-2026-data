#include<bits/stdc++.h>
using namespace std;
const int N=10e6+5;
long long n,a[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ct=1,xb=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			ct++;
			xb=i;
		}
	}
	long long MIN=1000000;
	if(ct==1)
	{
			for(long long i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]<=MIN&&a[i+1]-a[i-1]>m)
			{
				xb=i;
			}
		}
		if(a[n]-a[1]==n-1)
		{
			xb=n;
		}
	}
	for(long long i=xb;i>=0;i--)
	{
		if(a[i]<a[xb])
		{
			m-=a[xb]-a[i];
			if(m<0)
			{
				break;
			}
			else
			{
				ct++;
			}
		}
	}
	cout<<ct;
	return 0;
}