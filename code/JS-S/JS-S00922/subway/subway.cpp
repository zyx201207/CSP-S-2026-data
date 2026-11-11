#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5+5;

int n, m, d, Q;
ll w[maxn];
vector<pair<int, ll>> to[maxn];
ll g[505][505];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof(g));
	scanf("%*d %d %d %d %d", &n, &m, &d, &Q);
	for (int i = 0; i < n; ++i) g[i][i] = 0LL;
	for (int i = 0; i < m; ++i) scanf("%lld", w+i);
	for (int i = 0, k; i < n; ++i){
		scanf("%d", &k);
		int a; ll t;
		while (k--){
			scanf("%d %lld", &a, &t); --a;
			to[a].push_back({i, t});
		}
	}
	for (int i = 0; i < m; ++i){
		int sz = to[i].size();
		for (int j = 0; j < sz; ++j){
			for (int k = j+1; k < sz; ++k){
				if (to[i][j] == to[i][k]) continue;
				int x, y; ll wx, wy;
				tie(x, wx) = to[i][j]; tie(y, wy) = to[i][k];
				g[x][y] = min(g[x][y], wx + wy);
				g[y][x] = g[x][y];
			}
		}
	}
	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int x, y; Q--;){
		scanf("%d %d", &x, &y);
		--x; --y; ll ans = LLONG_MAX;
		for (pair<int, ll> T1 : to[x]){
			for (pair<int, ll> T2 : to[y]){
				ans = min(ans, w[x] + w[y] + T1.second + T2.second + g[T1.first][T2.first]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
