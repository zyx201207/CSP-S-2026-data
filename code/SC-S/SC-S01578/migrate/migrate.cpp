#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define ep emplace
#define pii pair <int, int>
#define fi first
#define se second
constexpr int MAXN = 2000005;
int c, t;
int n, d;
int x[MAXN];
int sx[MAXN];
int dp[5005][5005];
int dp2[5005][5005];
int brute ()
{
	
	memset(dp, 0x3f, sizeof dp);
	memset(dp2, 0, sizeof dp2);
	memset(sx, 0, sizeof sx);
	vector <int> adj[5005];
	for (int i = 1 ; i <= n ; i ++)
	{
		sx[i] = sx[i - 1] + x[i] - x[i - 1];
	} 
	for (int u = 1 ; u <= n ; u ++)
	{
		for (int v = u + 1 ; v <= n ; v ++)
		{
			if (sx[v] - sx[u] <= d)
			{
				adj[u].eb(v);
			}
		}
	}
	queue <pii> q;
	for (int i = 1 ; i <= n ; i ++)
	{
		q.ep(i, 0);
		while (not q.empty())
		{
			auto uu = q.front().fi, len = q.front().se;
			q.pop();
			for (int it : adj[uu])
			{
				if (len + 1 < dp[i][it])
				{
					dp[i][it] = len + 1;
					dp2[i][it] = 1;
					q.ep(it, len + 1);
				}
				else if (len + 1 == dp[i][it])
				{
					dp2[i][it] ++;
					q.ep(it, len + 1);
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		for (int j = 1 ; j <= n ; j ++)
		{
			cnt += (dp2[i][j] == 2);
		}
	}
	return cnt;
}
signed main ()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> d;
		for (int i = 1 ; i <= n ; i ++)
		{
			cin >> x[i]; 
		}
		if (n <= 5000)
		{
			cout << brute() << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	} 
	return 0;
}
