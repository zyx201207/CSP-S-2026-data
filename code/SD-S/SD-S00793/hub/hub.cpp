#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector<int> edge[N];
int fa[N];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int check(vector<int>& t, int n) {
	queue<int> q;
	vector<int> dis(n + 1, 1e9), ext(n + 1, 0), vis(n + 1, 0);
	for (int i : t) {
		q.push(i);
		dis[i] = 0;
		ext[i] = 1;
	}
	for (int u = 1;u <= n;u++) fa[u] = u;
	for (int u = 1;u <= n;u++) {
		for (int v : edge[u]) {
			if (ext[v]) fa[find(u)] = fa[find(v)];
		}
	}
	set<int> st;
	for (int i = 1;i <= n;i++) {
		if (!ext[i]) continue;
		find(i);
		st.insert(fa[i]);
	}
//	cout << st.size() << "\n";
	if (st.size() > 2) return -1;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : edge[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	int maxn = 0;
	for (int i = 1;i <= n;i++) {
		maxn = max(maxn, dis[i]);
	}
	return maxn;
}

void solve(int c) {
	int n, k; cin >> n >> k;
	for (int i = 1;i <= n;i++) edge[i].clear();
	for (int i = 1;i < n;i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if (c <= 3) {
		int ans = 1e9;
		for (int mask = 0;mask < (1 << n);mask++) {
			vector<int> tmp;
			if (__builtin_popcount(mask) > k) continue;
			for (int i = 0;i < n;i++) {
				if ((mask >> i) & 1) tmp.push_back(i + 1);
			} 
			int t = check(tmp, n);
			if (t != -1) ans = min(ans, t);
		}
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T; cin >> c >> T;
	while (T--) solve(c);
	return 0;
}
