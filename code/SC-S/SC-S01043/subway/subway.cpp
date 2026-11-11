// 15:08 T2 100pts
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int M = 5e5 + 10, N = 510;
const LL inf = 1e18 + 10;
LL w[M], k[N];

vector<pair<int, int> > a[M];

LL E[N][N];

LL Min(LL x, LL y) {
	return (x > y) ? y : x;
}

int main() {
	
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, T;
    cin >> c >> n >> m >> d >> T;

    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			int x, y; cin >> x >> y;
			a[x].push_back({i, y});
		}
    }
	memset(E, 0x3f, sizeof(E));
	for(int i = 1; i <= m; i++) {
		for(auto [x, tx] : a[i]) {
			for(auto [y, ty] : a[i]) {
				if(x == y) continue;
				E[x][y] = E[y][x] = Min(E[x][y], 1ll * tx + ty);
			}
		}
	}
	for(int i = 1; i <= n; i++) E[i][i] = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) {
				E[i][j] = Min(E[i][j], E[i][k] + E[k][j]);
			}
		}
	}
	while(T--) {
		int u, v; cin >> u >> v;
		LL ans = inf;
		for(auto [x, tx] : a[u]) {
			for(auto [y, ty] : a[v]) {
				LL res = 1ll * tx + ty + E[x][y];
				ans = min(ans, res + w[u] + w[v]);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
// g++ std.cpp -o std --std=c++14 -Wall -W &&  ulimit -s &&./std
// 524288
// 131072