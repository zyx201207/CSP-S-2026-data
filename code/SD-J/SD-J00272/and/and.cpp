#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],dp[2010][2010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int maxn = -1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	if(n<=2000&&m<=2000)
	{
		dp[1][1] = a[1];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j==1)dp[i][j] = max(dp[i-1][j],a[i]);
				else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		cout<<dp[n][m];
	}
	else
	{
		bool flag = true,flag2=true;
		for(int i=1;i<=n;i++)
		{
			int q = __builtin_popcount(a[i]);
			if(a[i]!=i-1)flag2 = false;
			if((1LL<<(q+1))-1!=a[i])flag = false;
		}
		if(flag)
		{
			cout<<maxn;
			return 0;
		}
		if(__builtin_popcount(n)==1&&flag2)
		{
			if(__builtin_popcount(maxn)+1<=m)cout<<0;
			else cout<<(maxn-(1LL<<(m-2)));
			return 0;
		}
	}
	
	return 0;
}
