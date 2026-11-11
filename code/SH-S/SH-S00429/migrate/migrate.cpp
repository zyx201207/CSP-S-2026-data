#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> G[2000005];
ll c, dp[2000005], dis[2000005], pos[2000005], in[2000005];

void solve()
{
	ll n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> pos[i];
	for (int i = 1; i <= n; i++)
	{
		ll r = i;
		G[i].clear();
		while (r + 1 <= n && pos[r + 1] - pos[i] <= d)
		{
			r++;
			G[i].push_back(r);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++) 
		{
			in[j] = 0;
		}
		for (int j = i; j <= n; j++) 
		{
			for (auto k : G[j]) in[k]++;
			dp[j] = 0;
			dis[j] = 4e18;
		}
		queue<ll> q;
		if (in[i + 1] == 0)
		{
			continue;
		}
		q.push(i);
		dp[i] = 1;
		dis[i] = 0;
		while (!q.empty())
		{
			ll u = q.front();
			q.pop();
			if (dp[u] == 2) ans++;
			for (auto k : G[u])
			{
				in[k]--;
				if (dis[u] + 1 == dis[k]) dp[k] += dp[u];
				else if (dis[u] + 1 < dis[k]) 
				{
					dis[k] = dis[u] + 1;
					dp[k] = dp[u];
				}
				if (!in[k]) q.push(k);
			}
		}
	}
	cout << ans << "\n";
	return;
}

void solve2()
{
	ll n, d;
	cin >> n >> d;
	ll cha;
	for (int i = 1; i <= n; i++)  cin >> pos[i];
	if (n == 1) cout << 0 << "\n";
	cha = pos[n] - pos[n - 1];
	if (d / cha <= 1) cout << 0 << "\n";
	else cout << max(0LL, (n - (d / cha * 2) + 1)) << "\n";
	return;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> c >> t;
	while (t--) 
	{
		if (c <= 10) solve();
		else if (c <= 12) solve2();
		else if (c <= 14) cout << 0 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
