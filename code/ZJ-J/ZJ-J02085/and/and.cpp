#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	int minn=2147483647;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]);
	}
	cout<<minn;
	return 0;
}

