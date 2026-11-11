#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 5e5+5;
int c, n, m, D, q;
ll w[1005], d[1500][1500];
vector <int> e[MAX];
long long s[MAX];

void B(ll T) {
	queue<pair<int, int> > Q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		Q.push({x, 0});
		memset(s, 0x3f, sizeof(s));
		s[x] = 0;
		while (!Q.empty()) {
			auto [u, v] = Q.front();
			Q.pop();
			if (u == y) {
				cout << w[x] + w[y] + 1ll * 2 * v*T << '\n';
				break;
			}
			for (int to : e[u]) {
				Q.push({to, v + 1});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(d, 0x3f, sizeof(d));
	ll T = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll a, t;
			cin >> a >> t;
			if (c < 12) {
				d[a][m + i] = t;
				d[m + i][a] = t;
			} else {
				T = t;
				e[a].push_back(m + i);
			}
		}
	}

	if (c >= 12 && c <= 19) {
		B(T);
		return 0;
	}
	for (int i = 1; i <= m; i++)
		d[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= m ; i++) {
			for (int j = 1; j <= m; j++) {
				d[i][j] = min(d[i][j], d[i][k + m] + d[k + m][j]);
				d[j][i] = d[i][j];
			}
		}
	}

	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m ; i++) {
			for (int j = 1; j <= m ; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				d[j][i] = d[i][j];
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << d[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}