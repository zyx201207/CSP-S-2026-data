#include<bits/stdc++.h>
using namespace std;
long long a[500010],d[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=1;
	for(long long i=2;i<=n;i++)
	{
		long long t=a[i]-a[i-1];
		for(long long j=1;j<=k;j++)
		{
			if(m>=t)
			{
				a[j]+=t;
				m-=t;
			}
			else
			{
				a[j]+=m;
				m=0;
			}
		}
		k++;
	}
	if(m)
	{
		for(int i=1;i<=m%n;i++)
		{
			a[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		d[a[i]]++;
	}
	sort(d+1,d+n+1);
	cout<<d[n];
	return 0;
}
