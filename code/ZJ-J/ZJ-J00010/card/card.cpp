#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e5 + 5; 
long long n, a[MAXN], m;
long long cnt[MAXN], nxt[MAXN], last[MAXN];
long long islast[MAXN], sz[MAXN];
vector<long long> g[MAXN];
void dfs(long long u, long long fa) {
	sz[u] = 1;
	for (long long v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	if (islast[u]) {
		long long t = islast[u];
		cnt[t] += sz[u];
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = n; i >= 1; i--) {
		if (nxt[a[i]]) g[nxt[a[i]]].push_back(i), g[i].push_back(nxt[a[i]]);
		nxt[a[i]] = i;
	}
	memset(nxt, 0, sizeof nxt);
	islast[n] = a[n];
	for (long long i = n; i >= 1; i--) {
		if (!nxt[a[i]] && i != n) islast[i] = a[i], g[i].push_back(i + 1), g[i + 1].push_back(i);
		nxt[a[i]] = i;
	}
	dfs(n, 0);
	for (long long i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
