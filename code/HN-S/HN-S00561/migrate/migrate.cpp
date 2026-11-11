#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5; 

int c, t;
int n, m;
int a[N];
int ans[N], minn[N];
bool vis[N];
vector<int> e[N];
int dis[N], k;

void dfs(int x, int sum, int y) {
	if (k > 2 || x > y || sum > dis[y]) return ;
	if (x == y) {
		if (sum == dis[y]) k++;
		return ;
	}
	for (int i = x + 1; i <= n; i++) {
		if (a[i] - a[x] <= m) dfs(i, sum + 1, y);
	}
	return ;
}

void solve() {
	cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(a[j] - a[i]) > m) break;
			e[i].emplace_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 1, idx = a[i];
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - idx > m) cnt++, idx = a[j];
			dis[j] = cnt;
		}
		for (int j = i + 1; j <= n; j++) {
			k = 0;
			dfs(i, 0, j);
			if (k == 2) tot++;
		}
	}
	cout << tot << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
lian n <= 1000 dou guo bu liao.
*/
