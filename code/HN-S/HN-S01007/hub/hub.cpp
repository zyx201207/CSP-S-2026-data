#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100 + 7;

int n, k, c[N], b[N];
vector<int> adj[N];

int fa[N], f[N], dep[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) fa[v] = u;
}

bool check(int tot) {
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1; i <= tot; i++) {
		int u = b[i];
		for (auto v : adj[u]) {
			if (c[v]) unite(u, v);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (c[i] && fa[i] == i) ++cnt;
	return cnt <= 2;
}

ll Ans = (1LL << 60);

void up(int u, int from) {
	for (auto v : adj[u]) {
		if (v == from) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		up(v, u);
	}
}

int dis(int u, int v) {
	int ans = 0;
	while (u != v) {
		++ans;
		if (dep[u] > dep[v]) u = fa[u];
		else v = fa[v];
	}
	return ans;
}

void dfs(int cur, int cnt) {
	if (cnt > k) return;
	if (cur > n) {
		int tot = 0;
		for (int i = 1; i <= n; i++) if (c[i]) b[++tot] = i;
		if (cnt == k) {
			if (check(tot)) {
				ll res = 0;
				for (int i = 1; i <= n; i++) {
					ll ret = (1LL << 60);
					for (int j = 1; j <= tot; j++) ret = min(ret, (ll)dis(b[j], i)); 
					res = max(res, ret);
				}
				Ans = min(Ans, res);
			}
		}
		return;
	}
	c[cur] = 0;
	dfs(cur + 1, cnt);
	c[cur] = 1;
	dfs(cur + 1, cnt + 1);
}
 
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	up(1, 0);
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d\n", fa[i]);
	// printf("%d\n", dis(1, 3));
	printf("%lld\n", Ans);
	for (int i = 1; i <= n; i++) adj[i].clear();
		Ans = (1LL << 60);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	for (; t--; ) solve();
	return 0;
}

// g++ main.cpp -o main -g -O2 -std=c++14 -static
// ./main
// time ./main