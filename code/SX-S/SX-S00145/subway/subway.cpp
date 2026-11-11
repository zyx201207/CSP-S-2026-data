#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N = 5000005, M = 505;

struct B {
	ll v, w;
};
vector<B> vt[N];
ll dq[N], f[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, d, T;
	cin >> n;
	cin >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++)
		cin >> dq[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i != j)
				f[i][j] = 1e18;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll x, y;
			cin >> x >> y;
			for (int ii = 0; ii < vt[x].size(); ii++) {
				f[i][vt[x][ii].v] = min(f[i][vt[x][ii].v], y + vt[x][ii].w);
				f[vt[x][ii].v][i] = min(f[vt[x][ii].v][i], y + vt[x][ii].w);
			}
			vt[x].push_back({i, y});
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		}
	}
	while (T--) {
		ll x, y, ans = 1e18;
		cin >> x >> y;
		for (int i = 0; i < vt[x].size(); i++) {
			for (int j = 0; j < vt[y].size(); j++)
				ans = min(ans, vt[x][i].w + vt[y][j].w + f[vt[x][i].v][vt[y][j].v]);
		}
		cout << ans + dq[x] + dq[y] << "\n";
	}
	return 0;
}
