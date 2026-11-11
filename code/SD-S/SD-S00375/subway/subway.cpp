#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e2 + 5;
const int M = 5e5 + 5;

int c, n, m, d, q;
int w[N];
//vector<pair<int, int> > g[(M << 1) + N];
vector<int> a[N], t[N];
int gg[N << 1][N << 1];
int cnt;
//priority_queue<pair<int, int> > q;
//
//void dij(int s) {
//	while (!q.empty()) q.pop();
//	q.push({0, s});
//	while ()
//}

void solve() {
	for (int i = 0; i < (N << 1); i++)
		for (int j = 0; j < (N << 1); j++)
			gg[i][j] = 1e9;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x;
		a[i].push_back(x);
		t[i].push_back(x);
		for (int j = 1; j <= x; j++) {
			cin >> y >> z;
			a[i].push_back(y);
			t[i].push_back(z);
		}
		cnt++;
		for (int j = 1; j < x; j++) {
			gg[a[i][j]][cnt] = t[i][j];
			gg[cnt][a[i][j]] = t[i][j];
			gg[a[i][j + 1]][cnt] = t[i][j + 1];
			gg[cnt][a[i][j + 1]] = t[i][j + 1];
		}
	}
	for (int i = 1; i <= cnt; i++) gg[i][i] = 0;
	for (int k = 1; k <= cnt; k++) {
		for (int i = 1; i <= cnt; i++) {
			for (int j = 1; j <= cnt; j++) {
				if (gg[i][j] > gg[i][k] + gg[k][j]) {
					gg[i][j] = gg[i][k] + gg[k][j];
				}
			}
		}
	}
//	cout << cnt << "==============\n";
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << gg[u][v] + w[u] + w[v] << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	cnt = m;
	if (c <= 11) solve();
//	for (int i = 1; i <= n; i++) {
//		int x, y, z;
//		cin >> x;
//		a[i].push_back(x);
//		t[i].push_back(x);
//		for (int j = 1; j <= x; j++) {
//			cin >> y >> z;
//			a[i].push_back(y);
//			t[i].push_back(z);
//		}
//		for (int j = 1; j < x; j++) {
//			g[a[i][j]].push_back({(++cnt), t[i][j]});
//			g[cnt].push_back({a[i][j], t[i][j]});
//			g[cnt].push_back({a[i][j + 1], t[i][j + 1]});
//			g[a[i][j + 1]].push_back({cnt, t[i][j + 1]});
//		}
//	}
	
	
	return 0;
}
