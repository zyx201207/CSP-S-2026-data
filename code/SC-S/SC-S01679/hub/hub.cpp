#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void read(T& x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) ;
	for (;  isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T, typename... other>
inline void read(T& x, other&... y) {
	read(x);
	read(y...);
}

int c, t;
int n, k;
vector<int> g[1000005];
bool vis1[1000005], vis2[1000005];
int d[1000005], p[1000005];

void bfs() {
	fill(vis2 + 1, vis2 + n + 1, false);
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (!vis1[i])
			continue;
		vis2[i] = true;
		for (const auto& to : g[i])
			if (!vis2[to])
				vis2[to] = true, q.emplace(to, to);
	}
	fill(d + 1, d + n + 1, 0), fill(p + 1, p + n + 1, 0);
	while (!q.empty()) {
		const auto [cur, par] = q.front();
		q.pop();
		d[cur] = d[par] + 1;
		for (const auto& to : g[cur])
			if (!vis2[to])
				vis2[to] = true, p[to] = cur, q.emplace(to, cur);
	}
}

int solve(int a, int b) {
	fill(vis1 + 1, vis1 + n + 1, false), vis1[a] = vis1[b] = true;
	for (int i = 3; i <= k; i++) {
		bfs();
		int u = max_element(d + 1, d + n + 1) - d;
		while (p[u] != 0)
			u = p[u];
		vis1[u] = true;
	}
	bfs();
	return *max_element(d + 1, d + n + 1);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (read(c, t); t--; ) {
		read(n, k);
		for (int i = 1, u, v; i < n; i++)
			read(u, v), g[u].push_back(v), g[v].push_back(u);
		int res = INT_MAX;
		for (int u = 1; u < n; u++)
			for (int v = u + 1; v <= n; v++)
				res = min(res, solve(u, v));
		cout << res << '\n';
		for (int i = 1; i <= n; i++)
			g[i].clear();
	}
	return 0;
}