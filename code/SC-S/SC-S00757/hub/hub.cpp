#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
const int inf = 0x3f3f3f3f;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
int c, T, cnt, n, k;
int f[N], g[N];
vector<int> e[N];
void dfs(int u, int fa, int D) {
	f[u] = -inf, g[u] = inf;
	for (int v : e[u]) {
		if (v == fa)continue;
		dfs(v, u, D);
		f[u] = max(f[u], f[v] + 1), g[u] = min(g[u], g[v] + 1);
	}
	if (f[u] == D)++cnt, f[u] = 0, g[u] = 0;
	if (f[u] + g[u] > D)f[u] = -inf, g[u] = 0, ++cnt;
}
bool check(int D) {
	dfs(1, 0, D);
	return cnt <= k;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), T = read();
	while (T--) {
		n = read(), k = read();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			e[u].push_back(v), e[v].push_back(u);
		}
		int l = 1, r = n, ans;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid))ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}