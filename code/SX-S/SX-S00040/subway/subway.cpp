#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N = 510, M = 5e5+10, INF = 1e18;
int c, n, m, d, q;
int w[M];
vector<int> hv[M];
vector<PII> G1[M + N];
int dp[N][N];

//fc subway.out subway3.ans
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			G1[a].pb({m + i, t});
			G1[m + i].pb({a, t});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto j : G1[i]) {
			for (auto k : G1[i]) {
				if (j == k)
					continue;
				dp[j.fi - m][k.fi - m] = min(dp[j.fi - m][k.fi - m], j.se + k.se);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = INF;
		for (auto j : G1[x]) {
			for (auto k : G1[y]) {
				ans = min(ans, w[x] + w[y] + j.se + k.se + dp[j.fi - m][k.fi - m]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
