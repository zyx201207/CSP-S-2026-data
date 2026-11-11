#include <bits/stdc++.h>
using namespace std;
#define maxn 310
#define ll long long
int c, t;
int n, d;
int x[maxn];
ll dis[maxn][maxn];
ll ans[maxn][maxn];

void dfs(int st, int u, int v, ll cnt) {
	if (u == v) {
		if (dis[st][v] == cnt) {
			ans[st][v]++;
		} else if (dis[st][v] > cnt) {
			dis[st][v] = cnt;
			ans[st][v] = 1;
		}
	}
	for (int i = u + 1; i <= v; i++) {
		if (x[i] - x[u] <= d) {
			dfs(st, i, v, cnt + 1);
		} else if (i == u + 1)
			return;
	}
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = maxn;
			ans[i][j] = 0;
		}
	}
	ans[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dfs(i, i, j, 0);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (ans[i][j] == 2)
				ans[0][0]++;
		}
	}
	cout << ans[0][0] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}