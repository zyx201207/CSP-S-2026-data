#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 505;
int w[N];
vector<pii> g[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		for (auto cur : g[x]) {
			int v = cur.first, w = cur.second;
			for (int i = 1; i  <= n; i++) {
				ans += w + v;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}