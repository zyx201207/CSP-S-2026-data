#include <iostream> 
#include <algorithm> 
#include <bits\stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long n,m,tn,tm,ma=0;cin>>n>>m;
	long a[n+5];
	for(long i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
	}
	sort(a+1,a+n+1);
	long maxm=0; 
	for(long i=1;i<=n;i++)
	{
		maxm+=ma-a[i];
	}
	if(maxm<=m)
	{
		cout<<n;
		return 0;
	}
	if(ma-a[n-1]>m)
	{
		cout<<0;
		return 0;
	}
	long i=n;
	while(maxm>m&&i>=1)
	{
		maxm-=(i-1)*(a[i]-a[i-1]);
		i-=1;
	}
	cout<<max(i,((m-maxm)/(a[i+1]-a[i])));
	return 0;
}
   

