#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int P = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 5e5 + 5;
const int maxm = 505;

int C, n, m, d, q;
int a[maxn];
int dis[maxm][maxm];
vector<pair<int, int> > c[maxn];
vector<int> g[maxn];

signed main() {
//	system("fc subway7.ans subway.out");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fst;

	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i ) cin >> a[i];
	for (int i = 1; i <= n; ++ i ) {
		for (int j = 1; j <= n; ++ j ) dis[i][j] = INF;
	}
	for (int i = 1; i <= n; ++ i ) dis[i][i] = 0;
	for (int i = 1; i <= n; ++ i ) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++ j ) {
			int x, t; cin >> x >> t;
			for (auto e : c[x]) dis[e.first][i] = dis[i][e.first] = e.second + t;
			c[x].push_back({i, t});
		}
	}
	for (int k = 1; k <= n; ++ k ) {
		for (int i = 1; i <= n; ++ i ) {
			for (int j = 1; j <= n; ++ j ) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q -- ) {
		int x, y; cin >> x >> y;
		int ans = INF;
		for (auto e : c[x]) {
			for (auto w : c[y]) {
				ans = min(ans, e.second + w.second + dis[e.first][w.first] + a[x] + a[y]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}


/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
