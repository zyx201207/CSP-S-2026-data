#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int v[N],dp[N];
int n,m;
void solve()
{
	memset(dp,0xcf,sizeof dp);
	dp[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = m + 1;j >= 1;j--)
		{
			dp[j] = max(dp[j],(dp[j - 1] < 0 ? v[i] : dp[j - 1] & v[i]));
		}
	}
	cout << dp[m];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> v[i];
	}
	// p
	if (n > 20)
	{
		solve();
		return 0;
	}
	int tn,ts,ans = -1e9;
	for (int i = 1;i < (1 << n);i++)
	{
		ts = 0;
		tn = 0;
		for (int j = 0;j < i;j++)
		{
			if (i >> j & 1) 
			{
				if (ts == 0) ts = v[j + 1];
				else ts = ts & v[j + 1];
				tn++;
			}
		}
		if (tn != m) continue;
		ans = max(ans,ts);
	}
	cout << ans;
	return 0;
}
