#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
void sol() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int>w(m + 1), k(n + 1);
	vector<vector<int>>sta(m + 1);
	vector<vector<int>>dp, g(n + 1, vector<int>(n + 1, 1e18)), a(n + 1, vector<int>(m + 1)), t(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= m; i++)	cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][a[i][j]];
			sta[a[i][j]].push_back(i);
		}
	}
	for (int p = 1; p <= m; p++) {
		for (int i = 0; i < sta[p].size(); i++) {
			for (int j = i; j < sta[p].size(); j++) {
				g[sta[p][i] ][sta[p][j] ] = g[sta[p][j] ][sta[p][i] ] = min(g[i][j], t[sta[p][i] ][p] + t[sta[p][j] ][p]);
			}
		}
	}
	dp = g;
	for (int i = 1; i <= n; i++)	dp[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[i][j] = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<"  yagouzaode "<<endl;
//	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (auto a : sta[x]) {
			for (auto b : sta[y]) {
				ans = min(ans, w[x] + t[a][x] + t[b][y] + w[y] + dp[a][b]);
			}
		}
		cout << ans << '\n';
	}

}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/