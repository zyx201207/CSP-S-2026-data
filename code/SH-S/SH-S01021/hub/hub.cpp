#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 17;
int c, T, n, K, dis[N][N];
int fa[N];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]); 
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	fa[x] = y;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> K;
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= n; ++i) dis[i][i] = 0, fa[i] = i;
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			dis[u][v] = dis[v][u] = 1;
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		int ans = 1e18;
		for (int i = 0; i < (1 << n); ++i) {
			if (__builtin_popcount(i) != K) continue;
			int mx = 0, mn;
			for (int j = 0; j < n; ++j) {
				mn = 1e18;
				for (int k = 0; k < n; ++k) {
					if (i >> k & 1) {
						mn = min(mn, dis[j + 1][k + 1]);
					}
				}
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		cout << ans << endl;
	}
}