#include <bits/stdc++.h>
using namespace std;
#define ll long long
int w[500010];



ll c, n, m, d, q, x, y, ans = LLONG_MAX;

struct st {
	int a, t, p;
};

vector<vector<st>> a(510);

void dfs(ll k, ll r, ll cnt) {
	if (k == r) {
		ans = min(ans, cnt);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i][1].p; j++) {
			if (a[i][j].a == k) {
				dfs(a[i][j + 1].a, r, cnt + a[i][j].t);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	ll p = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		a[i].resize(p + 1);
		for (int j = 1; j <= p; j++) {
			cin >> x >> y;
			a[i][j].a = x, a[i][j].t = y, a[i][j].p = p;
		}
	}
	while (q--) {
		cin >> x >> y;
		ll ti = w[x] + w[y];
		ans = LLONG_MAX;
		dfs( x, y, 0);
		cout << ti + ans << "\n";
	}
	return 0;
}