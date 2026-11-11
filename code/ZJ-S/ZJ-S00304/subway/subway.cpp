#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500, M = 500010;
vector <pair <int, int>> adj[M];
int n, m, q;
ll w[M], d[N][N];
int read () {
	int ret = 0;
	char ch = getchar ();
	while (!isdigit (ch)) {
		ch = getchar ();
	}
	while (isdigit (ch)) {
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);
		ch = getchar ();
	}
	return ret;
}
ll readlong () {
	ll ret = 0;
	char ch = getchar ();
	while (!isdigit (ch)) {
		ch = getchar ();
	}
	while (isdigit (ch)) {
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);
		ch = getchar ();
	}
	return ret;
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	read (), n = read (), m = read (), read (), q = read ();
	for (int i = 1; i <= m; i++) {
		w[i] = readlong ();
	}
	for (int i = 1; i <= n; i++) {
		int x = read ();
		for (int j = 1; j <= x; j++) {
			int y = read ();
			int z = read ();
			adj[y].push_back (make_pair (i, z));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				d[i][j] = 0x3f3f3f3f3f3f3f3fll;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int x = adj[i].size ();
		for (int j = 0; j < x; j++) {
			for (int k = j + 1; k < x; k++) {
				int u = adj[i][j].first, v = adj[i][k].first;
				ll dd = adj[i][j].second + adj[i][k].second;
				d[u][v] = d[v][u] = min (d[u][v], dd);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while (q --> 0) {
		int u, v;
		scanf ("%d%d", &u, &v);
		ll ret = 0x3f3f3f3f3f3f3f3f;
		for (auto i : adj[u]) {
			for (auto j : adj[v]) {
				ret = min (ret, 1ll * i.second + j.second + d[i.first][j.first]);
			}
		}
		printf ("%lld\n", ret + w[u] + w[v]);
	}
	return 0;
}