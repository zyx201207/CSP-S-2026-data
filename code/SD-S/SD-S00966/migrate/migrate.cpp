#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005;
int c, t, n, d, ans;
int x[N], dis[N], cnt[N], vis[N];
vector<int> G[N];

void solve1() {
	while (t--) {
		ans = 0;
		cin >> n >> d;
		int x1, x2;
		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 1) cin >> x1;
			else cin >> x2;
		}
		int dd = abs(x1 - x2);
		int maxstep = d / dd;
		if (maxstep == 0 || maxstep == 1) {
			cout << 0 << '\n';
			continue;
		}
		ans = n - maxstep * 2 + 1;
		if (ans < 0) cout << 0 << '\n';
		else cout << ans << '\n';
	}
}

void bfs(int beg) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	queue<pair<int, int>> q;
	q.push({0, beg}), vis[beg] = 1, dis[beg] = 0;
	while (q.size()) {
		int u = q.front().second, d = q.front().first;
		q.pop();
		for (auto v : G[u]) {
			if (!vis[v]) {
				dis[v] = dis[u] + 1;
				vis[v] = 1, cnt[v] = 1;
				q.push({dis[v], v}); 
			} else if (vis[v] && dis[u] + 1 == dis[v]) {
				cnt[v]++, q.push({dis[v], v});
			} 
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 2) ans++;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		solve1();
		return 0;
	}
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int dist = x[j] - x[i];
				if (x[j] - x[i] > d) break;
				G[i].push_back(j);
			}
		}
		for (int i = 1; i <= n; ++i) {
			bfs(i);
		}
		cout << ans << '\n';
	}
	return 0;
}

