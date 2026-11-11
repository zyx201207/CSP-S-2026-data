#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, m, d, q;
ll w[500005];
int k[505], vis[500005][20], top[500005];
vector<int> a[505];
map<int, int> t[505];
ll dp[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _ = 1;
//	cin>>_;
	while (_--) {
		memset(dp, 0x3f, sizeof(dp));
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= n; i++)
			dp[i][i] = 0;
		for (int i = 1; i <= m; i++)
			cin >> w[i];
		for (int i = 1; i <= n; i++) {
			int tt, aa;
			cin >> k[i];
			a[i].push_back(0);
			for (int j = 1; j <= k[i]; j++) {
				cin >> aa >> tt;
				a[i].push_back(aa);
				vis[a[i][j]][++top[a[i][j]]] = i;
				t[i].insert({aa, tt});
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= top[i]; ++j) {
				for (int kk = 1; kk < j; ++kk) {
					dp[vis[i][kk]][vis[i][j]] = dp[vis[i][j]][vis[i][kk]] = min(dp[vis[i][j]][vis[i][kk]],
					                            0ll+t[vis[i][j]][i] + t[vis[i][kk]][i]);
				}
			}
		}

		for (int kk = 1; kk <= n; kk++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dp[i][j] = min(dp[i][j], dp[i][kk] + dp[kk][j]);
				}
			}
		}

		while (q--) {
			int x, y;
			cin >> x >> y;
			ll ans = 1145141919810114514;
			for (int i = 1; i <= top[x]; i++) {
				for (int j = 1; j <= top[y]; j++) {
					ans = min(ans, w[x] + w[y] + t[vis[x][i]][x] + t[vis[y][j]][y] + dp[vis[x][i]][vis[y][j]]);
				}
			}
			cout << ans << "\n";
		}
	}
}/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
