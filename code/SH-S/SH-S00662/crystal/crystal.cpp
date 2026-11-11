#include <bits/stdc++.h> 
using namespace std;
long long a[500010];
long long d[500010];
long long sum[500010];
long long sum1[500010];
long long sum2[500010];
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
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	sum[1]=d[n];
	for(int i=2;i<=n-1;i++)
	{
		sum[i]=sum[i-1]+d[n-i+1];
	}
	for(int i=1;i<=n-1;i++)
	{
		sum1[i]=sum[n-i];
	}
	for(int i=1;i<=n-1;i++)
	{
		sum2[i]=sum2[i-1]+sum1[i];
	}
	int l=1,r=1;
	int maxn=0;
	while(true)
	{
		while(true)
		{
			if(sum2[r]-sum2[l-1]-sum1[r+1]*(r-l+1)<=m)
			{
				maxn=max(maxn,r-l+1);
				if(r==n-1)
				{
					break;
				}
				else
				{
					r++;
				}
			}
			else
			{
				break;
			}
		}
		while(true)
		{
			if(sum2[r]-sum2[l-1]-sum1[r+1]*(r-l+1)>m)
			{
				l++;
			}
			else
			{
				break;
			}
		}
		if(r==n-1)
		{
			break;
		}
	}
	cout<<maxn+1<<endl;
}
