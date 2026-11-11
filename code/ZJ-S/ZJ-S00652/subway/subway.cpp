#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const int N = 505, M = 5e5 + 5;

struct Node {
	ll v, w;
};
ll w[M], d[N][N];
vector<Node> v[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, D, q;
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			d[i][j] = 1e18;
		}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		ll a, t, k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			v[a].push_back(Node{i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (Node v1 : v[i]) {
			for (Node v2 : v[i]) {
				d[v1.v][v2.v] = min(d[v1.v][v2.v], v1.w + v2.w);
				d[v2.v][v1.v] = min(d[v2.v][v1.v], v1.w + v2.w);
			}
		}
	}
	for (int l = 1; l <= n; l++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for (Node v1 : v[x])
			for (Node v2 : v[y])
				ans = min(ans, d[v1.v][v2.v] + v1.w + v2.w);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}