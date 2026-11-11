#include <bits/stdc++.h>
using namespace std;
long long f[25][25];
long long a[2005],ans=-1;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][1]=a[i];
	}
	if (m==1)
	{
		for (int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	if (m==2)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if (m==n)
	{
		ans=a[1];
		for (int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	if (n<=20&&m<=n)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
			}
		}
		ans=f[n][m];
	}
	cout<<ans;
	return 0;
}

