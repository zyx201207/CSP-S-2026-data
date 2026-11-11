#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n,m,maxn,cnt,a[2000005],ll;
string tot(long long x)
{
	string res;
	while(x)
	{
		res+=(x%2)+'0';
		x/=2;
	}
	return res;
}
string as(string x,string y)
{
	long long res=min(x.size(),y.size());
	string f;
	for(int i=0;i<res;i++)
	{
		if(x[i]=='1'&&y[i]=='1')
		{
			f+='1';
		}
		else
		{
			f+='0';
		}
	}
	reverse(f.begin(),f.end());
	return f;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n]<<endl;
		return 0;
	}
	string cc,ans;
	string d=tot(a[n]);
	string dd=tot(a[n-1]);
	ans=as(d,dd);
	long long l=0;
	for(int i=ans.size()-1;i>=0;i--)
	{
		
		if(ans[i]!='0')
		{
			cnt+=(1<<l);
		}
		l++;
	}
	cout<<cnt<<endl;
	return 0; 
}
