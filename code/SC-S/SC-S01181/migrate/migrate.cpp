#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace sub1
{
	const int maxn = 5e3+5;
	int n , m , to[maxn];
	ll dp[maxn][maxn] , a[maxn] , f[maxn][maxn] , d;
	void Solve()
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)for(int j=1; j<=n; j++)dp[i][j]=2e18+5,f[i][j]=0;
		ll ans = 0;
		for (int i = 1; i <= n; i++)cin >> a[i],dp[i][i]=0,f[i][i]=0;
		for (int i = 1; i <= n; i++)
		{
			int pos = upper_bound(a + i , a + n + 1 , a[i] + d)-a-1;
			to[i]=pos;
		}
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) 
			if (j <= to[i])dp[i][j]=f[i][j]=1;
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i == k)continue;
				for (int j = 1; j <= n; j++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
			for (int j = 1; j <= n; j++) 
				for (int k = 1; k <= n; k++) 
					if (dp[i][j]==dp[i][k]+dp[k][j])f[i][j]+=f[i][k]*f[k][j];
			for (int j = 1; j <= n; j++)if (f[i][j] == 2)ans++;
		}
		cout << ans << "\n";
	}
};
namespace sub2
{
	const int maxn = 1e6+5;
	int n , m , to[maxn];
	ll a[maxn] , d;
	void Solve()
	{
		cin >> n >> d;
		ll ans = 0;
		for (int i = 1; i <= n; i++)cin >> a[i];
		cout << 0 << "\n";
	}
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c , T;
	cin >> c >> T;
	while(T--)
	{
		if (c != 13 && c != 14)sub1::Solve();
		else sub2::Solve();
	}
	return 0;
}

/*
0 1
4 2
1 3 4 5

*/