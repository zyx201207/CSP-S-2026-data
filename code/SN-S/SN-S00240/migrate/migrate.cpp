#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e6 + 5;
int n, f[N], g[N]; i64 d, x[N];
int dist[N]; int cnt[N], hd, tl, que[N];

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> x[i], f[i] = g[i] = 0;
	
	i64 ans = 0;
	for (int i = 1; i <= n; ++ i)
	{
		std::fill(dist + 1, dist + n + 1, n + 1),
		std::fill(cnt + 1, cnt + n + 1, 0);
		dist[i] = 0, hd = tl = 0, que[tl ++] = i, cnt[i] = 1;
		for (; hd < tl;)
		{
			int u = que[hd ++];
			for (int v = u + 1; v <= n; ++ v)
			{
				if (x[u] + d < x[v]) break;
				if (dist[u] + 1 < dist[v])
				{
					dist[v] = dist[u] + 1, cnt[v] = 1,
					que[tl ++] = v;
				}
				else if (dist[v] == dist[u] + 1) ++ cnt[v];
			}
		}
		for (int j = i; j <= n; ++ j)
			if (cnt[j] == 2) ++ ans;
	}
	cout << ans << '\n';
}

int main()
{
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int testpoint, T; cin >> testpoint >> T;
	for (int sampleid = 1; sampleid <= T; ++ sampleid) solve();
	return 0;
}
