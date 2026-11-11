#include <bits/stdc++.h>
#define pii pair<int, int> 
using namespace std;
const int MAXN = 5e5 + 10;
int cid, n, m, d, q, w[MAXN], x, y, t[MAXN];
long long f[510][510], ans;
pii p[MAXN][21];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> cid >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i], t[i] = 0;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) f[i][j] = 1e18;
	for(int i = 1, k; i <= n; i ++) {
		cin >> k;
		f[i][i] = 0;
		while(k --) {
			cin >> x >> y;
			p[x][++ t[x]] = {i, y};
		}
	}
	for(int i = 1; i <= m; i ++) {
		for(int j = 1; j < t[i]; j ++) for(int k = j + 1; k <= t[i]; k ++) {
			x = p[i][j].first, y = p[i][k].first;
			long long w = p[i][j].second + p[i][k].second;
			f[x][y] = min(f[x][y], w), f[y][x] = min(f[y][x], w);
		}
	}
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) {
		for(int k = 1; k <= n; k ++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	}
	while(q --) {
		cin >> x >> y;
		ans = 1e18;
		for(int i = 1; i <= t[x]; i ++) {
			for(int j = 1; j <= t[y]; j ++) {
				ans = min(ans, w[x] + w[y] + f[p[x][i].first][p[y][j].first] + p[x][i].second + p[y][j].second);
			}
		}
		cout << ans << "\n";
	}
}