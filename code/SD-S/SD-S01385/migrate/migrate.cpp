#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5005, M = 2e6 + 5;
int c, T, n, dis[N], vis[N], cnt[N];
int head[N], nxt[N * N], to[N * N], idx;
ll d, a[M];
void add (int u, int v) {
	to[++idx] = v, nxt[idx] = head[u], head[u] = idx;
}
void dij (int s) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	dis[s] = 0, cnt[s] = 1, q.emplace(0, s);
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1, q.emplace(dis[v], v);
			if (dis[v] == dis[u] + 1)
				cnt[v] += cnt[u]; 
		}
	}
}
void solve () {
	cin >> n >> d, idx = 0;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], head[i] = 0;
	if (n < 4 || d >= a[n] - a[1]) {
		puts("0");
		return;
	}
	if (c == 11 || c == 12) {
		int x = d / (a[2] - a[1]);
		if (x < 2) {
			puts("0");
			return;
		}
		cout << n - x * 2 + 1 << endl;
		return;
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[i] - a[j] <= d)
				add(i, j), add(j, i);
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		dij(i);
		for (int j = 1; j < i; ++j)
			ans += cnt[j] == 2;
	}
	cout << ans << endl;
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
