#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)	c[i]=a[i]-a[i-1];
	bool f=1;
	for(int i=3;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		unsigned long long x=m*2/c[2];
		long long y=sqrt(x);
		if(y>n)	cout<<n;
		else
		{
			if(y*(y+1)*c[2]/2>m)	cout<<y;
			else
			{
				if(y+1>n)	cout<<n;
				else cout<<y+1;
			}
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		long long ans=i*a[i]-sum[i];
		if(ans<=m)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
/*
5 30
1 4 7 10 13
*/
