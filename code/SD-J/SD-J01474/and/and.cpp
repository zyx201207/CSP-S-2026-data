#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
long long a[200005]={};
long long andyu[200005]={};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==2)
	{
		for(int i=n-1;i>0;i--)
		{
			if(a[i]==a[i+1])
			{
				cout<<a[i];
				return 0;
			}
		}
		string last;
		while(a[n]>0)
		{
			last+=a[n]%2+'0';
			a[n]/=2;
		}
		for(int i=n-1;i>0;i--)
		{
			string aq,aw;
			while(a[i]>0)
			{
				aq+=a[i]%2+'0';
				a[i]/=2;
			}
			string jieguo;
			for(int j=0;j<min(last.size(),aq.size());j++)
			{
				jieguo+=aq[j]&last[j];
			}
			long long j=1,sum=0;
			for(int x=0;x<jieguo.size();x++)
			{
				sum=sum*10+(int(jieguo[i])-int('1'))*j;
				j*=2;
			}
			andyu[i]=sum;
		}
		sort(andyu,andyu+n);
		cout<<andyu[n-1];
		return 0;
	}
	else if(m==3)
	{
		for(int i=n-2;i>0;i--)
		{
			if(a[i]==a[i+1]&&a[i]==a[i+2])
			{
				cout<<a[i];
				return 0;
			}
		}
		string last1,last;
		while(a[n]>0)
		{
			last1+=a[n]%2+'0';
			a[n]/=2;
		}
		while(a[n-1]>0)
		{
			last+=a[n-1]%2+'0';
			a[n-1]/=2;
		}
		for(int i=n-2;i>0;i--)
		{
			string aq;
			while(a[i]>0)
			{
				aq+=a[i]%2+'0';
				a[i]/=2;
			}
			string jieguo;
			for(int j=0;j<min(min(last.size(),aq.size()),last1.size());j++)
			{
				jieguo+=aq[j]&last[j]&last1[j];
			}
			long long j=1,sum=0;
			for(int x=0;x<jieguo.size();x++)
			{
				sum=sum*10+(int(jieguo[i])-int('1'))*j;
				j*=2;
			}
			andyu[i]=sum;
		}
			sort(andyu,andyu+n-1);
			cout<<andyu[n-2];
			return 0;
	}
	return 0;
}
