#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, k;
int ans;
int in[N], siz1[N], siz2[N];
vector<int> g[N];
void solve1() {
	int m = (n - 1) / 2;
	printf("%lld\n", (m - k + 1) / 2 + 1);
}
void dfs(int u, int fa) {
	siz1[u] = 1, siz2[u] = 1;
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		if (siz1[v] + 1 >= siz1[u]) {
			siz2[u] = siz1[u];
			siz1[u] = siz1[v] + 1;
		} else if (siz1[v] + 1 > siz2[u]) {
			siz2[u] = siz1[v] + 1;
		}
	}
	ans = max(ans, siz1[u] + siz2[u]);
}
void solve2() {
	ans = 0;
	dfs(1, 0);
	if (k == 2) printf("%lld\n", (ans - 2) / 2);
	else printf("%lld\n", (ans - 1) / 2);
}
void solve3() {
	ans = 0;
	dfs(1, 0);
	printf("%lld\n", (ans - k) / 2);
}
void solve() {
	scanf("%lld%lld", &n, &k);
	bool A = 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		in[u]++, in[v]++;
		if (in[u] > 3 || in[v] > 3) A = 0;
	}
	if (A) {
		solve1();
		return ;
	} else if (k <= 2) {
		solve2();
		return ;
	} else {
		solve3();
		return ;
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, T;
	scanf("%lld%lld", &C, &T);
	while (T--) {
		solve();
	}
	return 0;
}