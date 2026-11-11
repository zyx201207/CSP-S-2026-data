#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[300000];
	int ans=0,c=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<=n;i++)
		{
			ans=max(a[i],c);
			c=ans;
		}
	}
	else if(m==n)
	{
		for(int i=0;i<=n;i++)
		{
			if(i==0)
			{
				c=a[0];
			}
			else if(i>=1)
			{
				ans=a[i]&c;
				c=ans;
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				{
					ans=max(a[i]&a[j],c);
					c=ans;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
