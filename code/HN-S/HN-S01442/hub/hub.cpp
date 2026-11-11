#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int c, t, n, k, ans;
bool f[N], mk[N], dep[N], dp[N][21];
vector<int> v[N];

inline void link(int x, int y) {
	v[x].push_back(y), v[y].push_back(x);
}

void tr(int x) {
	mk[x] = 1;
	for (int i : v[x]) {
		if (mk[i] || !f[i]) continue;
		tr(i);
	} 
}

bool check() {
	for (int i = 1; i <= n; i++) mk[i] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!mk[i] && f[i]) tr(i), cnt++;
	}
	return cnt <= 2;
}

void init(int x, int fa) {
	dep[x] = dep[fa] + 1, dp[x][0] = fa;
	for (int i = 1; (1 << i) <= dep[x]; i++) dp[x][i] = dp[dp[x][i - 1]][i - 1];
	for (auto i : v[x]) {
		if (i == fa) continue;
		init(i, x);
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[dp[y][i]] >= dep[x]) y = dp[y][i];
	}
	for (int i = 20; i >= 0; i--) {
		if (dp[y][i] != dp[x][i]) y = dp[y][i], x = dp[x][i];
	}
	return dp[x][0];
}

int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void dfs(int x, int cnt) {
	if (cnt > k) return;
	if (x > n) {
		if (cnt != k || !check()) return;
		int maxx = 0;
//		cout << '\n';
		for (int i = 1; i <= n; i++) {
//			cout << f[i] << ' ';
			if (f[i]) continue;
			int minn = 1e9;
			for (int j = 1; j <= n; j++) {
				if (!f[j]) continue;
				minn = min(minn, dis(i, j));
			}
			maxx = max(minn, maxx);
		}
		ans = min(ans, maxx);
		return;
	}
	f[x] = 0; dfs(x + 1, cnt);
	f[x] = 1; dfs(x + 1, cnt + 1);
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		link(x, y);
	}
	if (n == k) {
		cout << "0\n";
		return;
	}
	if (c == 13 || c == 14) {
		cout << (int)ceil((n - k) / 4.0) << '\n';
		return;
	}
	init(1, 0);
	ans = 1e9;
	if ((c > 0 && c <= 3) || n <= 10) {
		dfs(1, 0);
		cout << ans << '\n';
		return;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
} 
