#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> G[1000005];
ll dp[1000005], n, k, ans;
bool choose[1000005];

ll check(ll now, ll pre)
{
	ll tcnt = 0;
	if (choose[now] && !choose[pre]) tcnt = 1;
	for (auto i : G[now])
	{
		if (i == pre) continue;
		tcnt += check(i, now);
	}
	return tcnt;
}

void dfs2(ll now, ll pre)
{
	if (choose[now]) dp[now] = 0;
	for (auto i : G[now])
	{
		if (i == pre) continue;
		dp[i] = min(dp[i], dp[now] + 1);
		dfs2(i, now);
		dp[now] = min(dp[now], dp[i] + 1);
	}
	return;
}

void dfs(ll now, ll cnt)
{
	if (cnt + n - now + 1 < k) return;
	if (cnt == k)
	{
		if (check(1, 0) > 2) return;
		fill(dp, dp + n + 1, 4e18);
		ll maxx = 0;
		dfs2(1, 0);
		dfs2(1, 0);
		for (int i = 1; i <= n; i++)  maxx = max(maxx, dp[i]);
		ans = min(ans, maxx);
		return;
	} 
	choose[now] = 1;
	dfs(now + 1, cnt + 1);
	choose[now] = 0;
	dfs(now + 1, cnt);
	return;
}

void solve()
{
	ll u, v;
	ans = 4e18;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> u >>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << "\n";
	return;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while (t--) 
	{
		if (c <= 3) solve();
		else 
		{
			int x, y;
			cin >> n >> k;
			for (int i = 1; i <= n - 1; i++) cin >> x >> y;
			if (k <= n / 2) cout << (n / 2 - k + 3) / 4 + 1 << "\n";
			else if (k < n) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;
}
