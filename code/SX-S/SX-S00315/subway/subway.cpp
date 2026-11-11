#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[500010], edge[505][505], shortest[505][505];
int c, m, n, d, q, k[505];
vector<pair<int, int>>vec[500010];
int main(int argv, char **argc) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(edge, 0x3f, sizeof(edge));
	memset(shortest, 0x3f, sizeof(shortest));
	cin >> c  >> n >> m >> d >> q;

	for (int z = 1; z <= m; z++) {
		cin >> w[z];
	}

	for (int z = 1; z <= n; z++) {
		cin >> k[z];
		for (int y = 1; y <= k[z]; y++) {
			ll a, t;
			cin >> a >> t;
			for (auto x : vec[a]) {
				shortest[x.first][z] = shortest[z][x.first] = edge[x.first][z] = edge[z][x.first] = min(edge[x.first][z], x.second + t);
			}
			vec[a].push_back(make_pair(z, t));
		}
		edge[z][z] = shortest[z][z] = 0;
	}

//	for (int z = 1; z <= n; z++) {
//		for (int y = 1; y <= n; y++) {
//			cerr << edge[z][y] << ' ';
//		}
//		cerr << '\n';
//	}

	for (int z = 1; z <= n; z++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				shortest[y][x] = min(shortest[y][x], shortest[z][y] + shortest[z][x]);
			}
		}
	}

	while (q--) {
		int x, y;
		ll ans = LLONG_MAX;
		cin >> x >> y;
		for (auto z : vec[x]) {
			for (auto ww : vec[y]) {
				ans = min(ans, z.second + ww.second + shortest[z.first][ww.first]);
			}
		}
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
}
