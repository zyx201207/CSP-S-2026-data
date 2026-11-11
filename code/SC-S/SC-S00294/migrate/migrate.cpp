#include <bits/stdc++.h>

using ll = long long;
const int N = 2e6 + 5;

int n, nxt[N];
ll ans, d, x[N], f[N][3];
std::vector <int> e[N];

void dfs(int cur) {
	if (nxt[nxt[cur]]) {
		int to = nxt[cur];
		
		if (nxt[to - 1] < nxt[to] - 1) f[cur][0] = f[to][0];
		if (nxt[to - 1] == nxt[to] - 1) f[cur][0] = f[to][1];
		if (nxt[to - 1] == nxt[to] && (cur > to - 2 || nxt[to - 2] != nxt[to])) f[cur][0] = f[to][2];
		if (nxt[to - 1] > to) f[cur][0] += nxt[to - 1] - (cur > to - 2 ? 0 : nxt[to - 2]);
		
		if (nxt[to - 1] < nxt[to] - 1) f[cur][1] = f[to][0];
		if (nxt[to - 1] == nxt[to] - 1) f[cur][1] = f[to][1];
		
		if (nxt[to - 1] <= nxt[to] - 1) f[cur][2] = f[to][2]; 
		f[cur][2] += nxt[to] - nxt[to - 1];
		
		ans += f[cur][0];
	}
	for (int j : e[cur]) dfs(j);
}

void solve(int l, int r) {
	if (r - l <= 1) return ;
	for (int i = l, j = l; i < r; i ++) {
		while (j < r && x[j + 1] - x[i] <= d) j ++;
		nxt[i] = j, e[j].emplace_back(i);
	}
	dfs(r);
}

void solve() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; i ++) std::cin >> x[i];
	for (int i = 1, j = 1; i <= n; i ++) {
		if (i == n || x[i + 1] > x[i] + d) {
			solve(j, i); j = i + 1;
		}
	}
	std::cout << ans << '\n', ans = 0;
	for (int i = 1; i <= n; i ++) e[i].clear(), nxt[i] = 0;
	for (int i = 1; i <= n; i ++) f[i][0] = f[i][1] = f[i][2] = 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int c, t;
	std::cin >> c >> t;
	
	while (t --) solve();
	return 0;
}