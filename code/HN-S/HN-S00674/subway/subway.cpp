#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e4 + 5, M = 5e2 + 5;
const ll INF = 1e18;

struct P {
	int x, y;
};

int c, n, m, d, p, w[N], a[M][N], t[M][N], k[M], vis[M][N], v2[M][N];
ll ans;
vector<P> g[M][N], g2[N];
vector<int> v;

void dfs(int x, int Y, ll time, int ls) {
	if (x == Y) {
		ans = min(ans, time);
		/*for (int i : v) {
			cout << i << ' ';
		}
		cout <<'\n'<<ans<< '\n';*/
		return;
	}
	if (vis[ls][x]) {
		return;
	}
	vis[ls][x] = 1;
	for (int h = n; h >= 1; h--) {
		v.push_back(x);
		if (h != ls && v2[h][x] > 0 && !vis[h][x]) {
			dfs(x, Y, time + v2[h][x], h);
		} else if (h == ls) {
			for (auto i2 : g[h][x]) {
				//cout << i.x;
				dfs(i2.x, Y, time + i2.y, h);
			}
		}
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			g2[a[i][j]].push_back({i, t[i][j]});
			v2[i][a[i][j]] = t[i][j];
		}
		for (int b = 1; b <= k[i]; b++) {
			for (int j = 1; j <= k[i]; j++) {
				if (b == j) continue;
				g[i][a[i][b]].push_back({a[i][j], t[i][j]});
			}
		}
	}
	while (p--) {
		ll z = INF;
		int x, y;
		cin >> x >> y;
		for (auto i : g2[x]) {
			for (int i1 = 1; i1 <= n; i1++) {
				for (int j = 1; j <= m; j++) {
					vis[i1][j] = 0;
				}
			}
			v.clear();
			ans = INF;
			dfs(x, y, w[x] + w[y] + i.y, i.x);
			z = min(ans, z);
		}
		cout << z << '\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
