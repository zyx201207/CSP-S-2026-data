#include<bits/stdc++.h>
using namespace std;
bool b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==1)
	{
		long long maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		long long maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		long long maxn;
		maxn=(a[1]&a[2]);
		for(int i=3;i<=n;i++)
		{
			maxn=(maxn&a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		long long maxn=(a[2]&a[3]);
		for(int i=4;i<=n;i++)
		{
			maxn=(maxn&a[i]);
		}
		for(int i=2;i<=n;i++)
		{
			long long mx=a[1];
			for(int j=2;j<=n;j++)
			{
				if(j!=i)
				{
					mx=(mx&a[j]);
				}
			}
			maxn=max(maxn,mx);
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
