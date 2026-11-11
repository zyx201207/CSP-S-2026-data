#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2000005;
int n, m, a[MAXN], dis[MAXN], cnt[MAXN], ans;

void bfs(int u) {
	for (int i = u + 1; i <= n; i++)
		dis[i] = 4e18, cnt[i] = 0;
	dis[u] = 0, cnt[u] = 1;
	for (int i = u; i <= n; i++) {
		int j = i + 1;
		while (j <= n && a[j] - a[i] <= m) {
			int w = dis[i] + 1, nc = cnt[i];
			if (dis[j] > w)
				dis[j] = w, cnt[j] = cnt[i];
			else if (dis[j] == w)
				cnt[j] += cnt[i];
			j++;
		}
	}
	for (int i = u + 1; i <= n; i++)
		if (cnt[i] == 2)
			ans++;
}

void solve() {
	cin >> n >> m;
	ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		bfs(i);
	cout << ans << '\n';
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}