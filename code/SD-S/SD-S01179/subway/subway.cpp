#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int MaxN = 505;
constexpr int MaxM = 5e5 + 10;
constexpr int MaxQ = 1e5 + 10;
constexpr int MaxD = 25;

int cid, n, m, d, q;
vector<pair<int, int>> path[MaxN];
vector<pair<int, int>> onw[MaxM];
int val[MaxM];

ll dis[MaxN][MaxN];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> cid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> val[i];
	for (int i = 1; i <= n; i++) {
		int L; cin >> L;
		path[i].reserve(L);
		while (L--) {
			int a, t;
			cin >> a >> t;
			path[i].emplace_back(a, t);
			onw[a].emplace_back(i, t);
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = 1e18;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
		
	for (int u = 1; u <= m; u++) {
		for (auto P : onw[u]) {
			int x = P.first, t1 = P.second;
			for (auto Q : onw[u]) {
				int y = Q.first, t2 = Q.second;
				dis[x][y] = min<ll>(dis[x][y], t1 + t2);
			}
		}
	}
				
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				
	while (q--) {
		int x, y;
		cin >> x >> y;
		
		ll ans = 1e18;
		for (auto P : onw[x]) {
			int i = P.first, t1 = P.second; 
			for (auto Q : onw[y]) {
				int j = Q.first, t2 = Q.second;
				ans = min(ans, t1 + t2 + dis[i][j]);
			}
		}
		ans += val[x] + val[y];
		cout << ans << '\n';
	}
}

/*
对于 n 条边，枚举与其相交的边 (x, y, w) 建边
跑 floyd，然后询问枚举从 x 进从 y 出 

qd^2 + n^3 + md^2
2e8 应该轻松？ 
*/

/*
坐落于大都市顶点空想构筑的理想乡
将这一切湮灭的将是谁的愿望
*/

