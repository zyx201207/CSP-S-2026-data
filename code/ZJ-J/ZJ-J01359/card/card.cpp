#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
#define M 300005
int n, m;
int a[N], b[M], f[N], ans[M];
vector<int> e[N];
void dfs(int u) {
	f[u] = 1;
	for (int i = 0; i < e[u].size(); ++i) {
		dfs(e[u][i]);
		f[u] += f[e[u][i]];
	}
	if (b[a[u]] == u) ans[a[u]] = f[u];
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; --i) {
		if (!b[a[i]]) {
			b[a[i]] = i;
			e[i+1].push_back(i);
		}
		else {
			e[b[a[i]]].push_back(i);
		}
	}
	dfs(n+1);
	for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
