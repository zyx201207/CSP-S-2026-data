#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define lowbit(x) x&(-x)

const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int c, n, m, d, q;
int w[M], k[N];
int dis[N][N];
vector <int> a[N], t[N];
vector <pair <int, int> > b[M];

inline void upd (int & x, int & y, int z) {
	x = min(x, z);
	y = min(y, z);
}

void solve () {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i] = vector <int> (k[i] + 1, 0);
		t[i] = vector <int> (k[i] + 1, 0);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			b[a[i][j]].push_back({i, j});
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = INF;
	for (int i = 1; i <= n; i++) dis[i][i] = 0ll;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			for (auto tmp : b[a[i][j]]) {
				int x = tmp.first, y = tmp.second;
				if (i != x) upd(dis[i][x], dis[x][i], t[i][j] + t[x][y]);
			}
	
	for (int k = 1; k < n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				upd(dis[i][j], dis[j][i], dis[i][k] + dis[k][j]);
	
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cout << i << " " << j << " " << dis[i][j] << "\n";
	
	while(q--) {
		int x, y; cin >> x >> y;
		int ans = INF;
		for (auto tmp1 : b[x]) for (auto tmp2 : b[y]) {
			int i = tmp1.first, pos1 = tmp1.second;
			int j = tmp2.first, pos2 = tmp2.second;
			ans = min(ans, w[x] + w[y] + dis[i][j] + t[i][pos1] + t[j][pos2]);
		}
		cout << ans << "\n";
	}
}

signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; // cin >> T;
	while(T--) solve();
	return 0;
}