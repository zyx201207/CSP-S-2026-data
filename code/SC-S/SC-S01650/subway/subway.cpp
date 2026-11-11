#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
int c, n, m, d, q, x, y, r;
ll w[N], t[510][N], a[510][N], k[N], cnt = -1;
void dfs(ll aa, ll ss, ll timee) {
	if (a[aa][ss] == y) {
		cnt = max(timee + w[x] + w[y] + t[aa][ss], cnt);
		return;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (a[i][j] == a[aa][ss]) {
				for (ll l = 1; l <= n; l++) {
					if (a[i][l] == a[aa][ss])continue;
					dfs(i, l, timee + t[aa][ss] + t[i][j]);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)cin >> a[i][j] >> t[i][j];

	}
	while (q--) {
		cin >> x >> y;
		cnt = -1;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if (a[i][j] == x)dfs(i, j, 0);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}