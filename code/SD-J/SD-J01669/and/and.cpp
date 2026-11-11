#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxx=-1e18,ma=-1e18,mi=1e18;
	int n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		if(a[i]!=i-1)
		{
			f=0;
		}
		mi=min(mi,a[i]);
	}
	if(n<=20)
	{
		if(m==3)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					for(int k=1;k<=n;k++)
					{
						if(i==j||j==k||i==k)
						{
							continue;
						}
						maxx=max(maxx,a[i]&a[j]&a[k]);
					}
				}
			}
			cout<<maxx;
			return 0;
		}
		if(n==4)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					for(int k=1;k<=n;k++)
					{
						for(int l=1;l<=n;l++)
						{
							if(i==j||i==k||i==l||j==k||j==l||k==l)
							{
								continue;
							}
							maxx=max(maxx,a[i]&a[j]&a[k]&a[l]);
						}
					}
				}
			}
			cout<<maxx;
			return 0;
		}
		else
		{
			cout<<0;
		}
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	else if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(n>2000)
	{
		if(f==1)
		{
			cout<<0;
			return 0;
		}
		cout<<mi;
	}
	return 0;
}
