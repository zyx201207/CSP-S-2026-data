#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long b[500005];
long long c[500005];
	
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	bool f=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=1;
		}
	}
	if(f==0)
	{
		long long k=0;
		for(long long i=1;i<=n;i++)
		{
			k=0;
			for(long long s=i;s<=n;s++)
			{
				if(a[s]==a[s-1])
				{
					k--;
				}
				b[++k]=a[s];
			}
			for(long long j=1;j<=k;j++)
			{
				c[b[j]]++;
			}
		}
		for(long long i=1;i<=m;i++)
		{
			cout<<c[i]<<" ";
		}
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		long long k=0;
		for(long long s=i;s<=n;s++)
		{
			long long x=INT_MAX;
			for(long long j=k;j>0;j--)
			{
				if(b[j]==a[s])
				{
					x=j;
					break;
				}
			}
			if(x!=INT_MAX)
			{
				k=x-1;
			}
			b[++k]=a[s];
		}
		for(long long j=1;j<=k;j++)
		{
			c[b[j]]++;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
