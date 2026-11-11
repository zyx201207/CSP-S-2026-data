#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int N=5e5+5;
int n,cnt=1,yb=0,sum=0,s=0,g=0,sumn=0,cntt=1;
long long m,a[N],hx[1000000000000],mxx=0,maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		hx[a[i]]++;
		if(a[i]==i)
		{
			s++;
			if(m==3)
			{
				cnt=3;
			}
			else if(m==2||m==1)
			{
				cnt=2;
			}
			else 
			{
				for(int i=1;i*i<=m;i++)
				{
					sum+=i;
					if(sum<=m)cnt++;
				}
			}
		}
	}
	if(s==n)cout<<cnt<<endl;
	int x,y;
	for(int i=3;i<=n;i++)
	{
		x=a[i]-a[i-1];
		y=a[i-1]-a[i-2];
		if(x==y)g++;
	}
	if(g==n-2)
	{
		x=a[n]-a[n-1];
		for(long long i=x;i<=m;i=i+x)
		{
			sumn=sumn+i;
			if(sumn<=m)cntt++;
		}
		cout<<cntt<<endl;
	}
	if(m==0)
	{
		for(long long i=1;i<=maxn;i++)mxx=max(mxx,hx[i]);
		cout<<mxx<<endl;
	}
	return 0;
} 