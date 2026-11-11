#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1005;
const int N = 505;
const int inf = 0x3f3f3f3f;
int dp[M][M];
int w[M];
int k[N];
vector<int> G[M];
int a[N][20005], t[N][20005];
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	int C, n, m, d, q; cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			G[a[i][j]].push_back (i);
		}
	}
	memset (dp, inf, sizeof dp);
	for (int i = 1; i <= m; i++) dp[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int u = 0; u < G[i].size (); u++) {
			int to = G[i][u];
			for (int j = 1; j <= k[to]; j++) {
				if (a[to][j] == i) break;
				dp[a[to][j]][i] = min (dp[a[to][j]][i], dp[a[to][j]] + t[to][i] + w[i] - w[a[to][j]] + t[to][a[to][j]]);
			}
		}
	}
	dp[1] = 0;
	for (int i = 1; i <= m; i++) cout << dp[i] << ' ';
	while (q--) {
		int l, r; cin >> l >> r;
		if (l > r) swap (l, r);
		cout << dp[r] - dp[l] << "\n";
	}
	return 0;
}
