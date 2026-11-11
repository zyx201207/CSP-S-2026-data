#include<iostream>
#define int long long
using namespace std;
int a[200010],dp[2010][2010],n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
	}
	for(int x=1;x<=m;x++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<n;j++)
			{
				dp[i][x]=max(dp[i][x],dp[j][x-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}

