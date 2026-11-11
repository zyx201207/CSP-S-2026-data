#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+5, N = 505;
int c, n, m, d, q, k;
long long w[M];
long long t;
bool vis[M];
long long dist[M];
priority_queue<pair<long long, long long> > pq;
struct edge {
	int u, v, w;
	bool operator < (const edge & o) const {
		return w < o.w;
	}
};
vector<edge> e;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			long long x, y;
			cin >> x >> y;
			t = y;
			
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		
		cout << w[x]+w[y] << '\n';
	} 
	return 0;
}
