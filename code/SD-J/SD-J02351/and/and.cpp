#include <bits/stdc++.h>
using namespace std;
int m,n,ans,a[200005],ma;
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin >>n>>m;
	for (int i=1; i<=n; i++)
	{
		cin >>a[i];
	}
	if (m==n)
	{
		ans=a[1];
		for (int i=1; i<=n; i++)
		{
			ans=ans&a[i];
		}
		cout <<ans;
	}
	if (m==2)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (i==j)
				{
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout <<ans;
	}
	if (m==n-1)
	{
		for (int i=1; i<=n; i++)
		{
			if (i==1) ans=a[2];
			else ans=a[1];
			for (int j=1; j<=n; j++)
			{
				if (j==i)
				{
					continue;
				}
				ans=ans&a[j];
			}
			ma=max(ma,ans);
		}
		cout <<ma;
	}
	for (int i=1; i<=n; i++)
	{
		ans=max(a[i],ans);
	}
	cout <<ans;
	return 0;
}
