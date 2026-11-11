#include <iostream>
#include <queue>

using namespace std;

int fvv, T;

const int N = 1e6 + 5, inf = 2e9;
int n, k, fnl;

int head[N], nxt[N << 1], ver[N << 1], tot;
inline void addedge (int u, int v) {
	ver[++ tot] = v, nxt[tot] = head[u], head[u] = tot;
	ver[++ tot] = u, nxt[tot] = head[v], head[v] = tot;
}

bool chos[N], vis[N];
int dis[N];
queue <int> que;
inline void check () {
	int mxdis = 0, tmp = 0;
	for (int i = 1; i <= n; ++ i) vis[i] = false;
	for (int i = 1; i <= n; ++ i) {
		if (chos[i]) {
			que.push(i), vis[i] = true, dis[i] = 0;
			tmp ++;
			for (int j = head[i], y; j; j = nxt[j]) {
				y = ver[j];
				if (vis[y]) {tmp --; break;}
			}
			if (tmp > 2) return;
		}
		else vis[i] = false;
	}
	if (que.empty()) return;
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (int i = head[x], y; i; i = nxt[i]) {
			y = ver[i];
			if (vis[y]) continue;
			dis[y] = dis[x] + 1;
			mxdis = max(mxdis, dis[y]);
			que.push(y);
			vis[y] = true;
		}
	}
	fnl = min(fnl, mxdis);
}
void dfs (int x, int cnt) {
	if (x == n + 1) return check();
	if (cnt < k) {
		chos[x] = true;
		dfs(x + 1, cnt + 1);
		chos[x] = false;
	}
	dfs(x + 1, cnt);
}
inline void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) head[i] = 0;
	tot = 0;
	for (int i = 1, u, v; i < n; ++ i) {
		cin >> u >> v;
		addedge(u, v);
	}
	fnl = inf;
	dfs(1, 0);
	cout << fnl << '\n';
}

inline void solveA () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) head[i] = 0;
	tot = 0;
	for (int i = 1, u, v; i < n; ++ i) {
		cin >> u >> v;
		addedge(u, v);
	}
	if (n == k) return cout << "0\n", void();
	int m = n / 2;
	int spc = m - k;
	int evr = spc / 4;
	if (spc <= 0) return cout << "1\n", void();
	if (spc % 4 == 0) {
		cout << evr + 1 << '\n';
	} else {
		cout << evr + 2 << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> fvv >> T;
	while (T --) {
//		if (fvv <= 3 or fvv == 7)
//			solve();
		if (fvv == 13 or fvv == 14)
			solveA();
		else solve();
	}
	return 0;
}