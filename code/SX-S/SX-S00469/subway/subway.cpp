#include <bits/stdc++.h>
using namespace std;
const int N = 555, M = 5e5 + 10;
typedef long long ll;
int c, n, m, d, q, k[N];
ll w[M], ans;
vector<pair<int, ll> > v[M];
ll vv[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1, xx, yy; j <= k[i]; j ++) {
			cin >> xx >> yy;
			v[xx].push_back({i, yy});
		}
	}
	memset(vv, 0x3f, sizeof(vv));
	for (int i = 1, len; i <= m; i ++) {
		len = v[i].size();
		for (int x = 0; x < len; x ++) {
			for (int  y = x + 1, a, aa, b, bb; y < len; y ++) {
				a = v[i][x].first, b = v[i][y].first, aa = v[i][x].second, bb = v[i][y].second;
				vv[b][a] = vv[a][b] = aa + bb;
//				cerr << a << " " << b << " " << aa << " " << bb << " qwe " << aa + bb << endl;
			}
		}
	}
	//fllyed

	for (int z = 1; z <= n; z ++) {
		for (int i = 1 ; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i == j) {
					continue;
				}
				vv[i][j] = min(vv[i][j], vv[i][z] + vv[z][j]);
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		vv[i][i] = 0;
	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			cerr << vv[i][j] << " ";
//		}
//		cerr << endl;
//	}
	for (int i = 1, U, V, L, Ll; i <= q; i ++) {
		cin >> U >> V;
		ans = 1e18;
		L = v[U].size();
		Ll = v[V].size();
		for (int j = 0; j < L; j ++) {
			for (int z = 0; z < Ll; z ++) {
				ans = min(vv[v[U][j].first][v[V][z].first] + v[U][j].second + v[V][z].second, ans);
			}
		}
		ans += w[U] + w[V];
		cout << ans << '\n';
	}
	return 0;
}
