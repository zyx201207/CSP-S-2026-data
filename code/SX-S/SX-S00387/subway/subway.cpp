#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
int v[500005];
int k;

struct edge {
	int g[500005];
	int t[500005];
} a[505];
long long ans;
int x, y;

void solve() {
	ans += v[x];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (a[i].g[j] == x) {
				ans += a[i].t[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (a[i].g[j] == y) {
				ans += a[i].t[j];
				ans += v[y];
				cout << ans;
				return;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i].g[i] >> a[i].t[i];
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> x >> y;
		solve();
	}
	return 0;
}