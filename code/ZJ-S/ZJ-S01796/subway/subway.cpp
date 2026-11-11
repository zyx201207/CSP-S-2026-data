#include <bits/stdc++.h>
#define int long long
#define ST string
#define DB double
#define PII pair <int, int>
#define x first
#define y second

#define fr(x, y, z) for (int x = y; x <= z; x ++ )
#define dfr(x, y, z) for (int x = y; x >= z; x -- )

using namespace std;

const int N = 510, M = 5e5 + 5;
int c, n, m, d, q, w[M], dis[N][N];

vector <PII> v[M];
signed main() {
	 freopen("subway.in", "r", stdin);
	 freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	fr (i, 1, m) cin >> w[i];
	
	int k;
	fr (i, 1, n) {
		cin >> k;
		int x, t;
		fr (j, 1, k) {
			cin >> x >> t;
			v[x].push_back({i, t});
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	fr (i, 1, n) dis[i][i] = 0;
	
	fr (i, 1, m) {
		fr (j, 0, (int)v[i].size() - 1) fr (k, 0, (int)v[i].size() - 1)
			dis[v[i][j].x][v[i][k].x] = min(dis[v[i][j].x][v[i][k].x], v[i][j].y + v[i][k].y);
	}
	
	fr (k, 1, n) fr (i, 1, n) fr (j, 1, n) 
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	int x, y;
	while (q -- ) {
		cin >> x >> y;
		int res = 1e18;
		fr (xi, 0, (int)v[x].size() - 1) fr (yi, 0, (int)v[y].size() - 1)
			res = min(res, v[x][xi].y + dis[v[x][xi].x][v[y][yi].x] + v[y][yi].y);
		cout << res + w[x] + w[y] << '\n';
	} 
	
	return 0;
}

// 100 plzzzzz
