#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 500010;
const int INF = 1e9;

int n, m, rt;
vector<int> G[N];
int p[N], cnt;

void dfs(int u, int fa, int x) {
	p[u] = 0;
	for(int v : G[u]) {
		if(v == fa) continue;
		dfs(v, u, x);
		p[u] = max(p[u], p[v] + 1);
	}
	if(p[u] == x) { p[u] = 0; ++ cnt; }
}

bool check(int x) {
	cnt = 0; dfs(rt, 0, x);
	return cnt <= m;
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) G[i].clear();
	for(int i = 1; i < n; ++ i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i)
		if(G[i].size() == 1) { rt = i; break; }
	int L = 0, R = n;
	while(L < R) {
		int Mid = (L + R) >> 1;
		if(check(Mid)) R = Mid;
		else L = Mid + 1;
	}
	cout << L << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T; cin >> c >> T;
	while(T --) solve();
	return 0;
}
