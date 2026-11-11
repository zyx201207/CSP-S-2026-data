# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int c, n, m, d, q;
const int N = 1e6 + 5;
int w[N];
int t[N][30];
int s, e;
int a[N][30];
int dis[1000][1000];
int k[N];

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	fst;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++ ) {
			cin >> a[j][i];
			cin >> t[j][i];
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= k[i]; j ++ ) {
			for (int l = j + 1; l <= k[i]; l ++ ) {
				dis[a[j][i]][a[l][i]] = t[a[j][i]][i] + t[a[l][i]][i];
				dis[a[l][i]][a[j][i]] = t[a[l][i]][i] + t[a[j][i]][i];
//				cout << dis[a[j][i]][a[l][i]] << endl;
			}
		}
	}
	for (int k = 1; k <= n; k ++ ) {
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				if ((dis[i][k] != 0) && (dis[k][j] != 0)) {
					dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]); 
				}
			}
		} 
	}
	for (int i = 1; i <= q; i ++ ) {
		cin >> s >> e;
		cout << w[s] + w[e] + dis[s][e] << endl; 
	}
	return 0;
}
