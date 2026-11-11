#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 2e6 + 5, N2 = 5005, INF = 1e18;

struct Node {
	int v, w, st;
	bool operator <(const Node &i) const {
		return w > i.w;
	}
};

int c, T, n, d, a[N];
vector<int> G[N2];
pii dist[N2][N2];

void Dijkstra () {
	priority_queue<Node> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = make_pair (INF, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		pq.push ({i, 0, i});
		dist[i][i] = make_pair (0, 1);
	}
	while (!pq.empty ()) {
		Node now = pq.top ();
		pq.pop ();
		int u = now.v, dis = now.w, st = now.st;
		for (int v : G[u]) {
			if (dist[st][v].first > dis + 1) {
				dist[st][v] = make_pair (dis + 1, 1);
				pq.push ({v, dis + 1, st});
			} else if (dist[st][v].first == dis + 1) {
				dist[st][v].second ++;
			}
		}
	}
}

void Solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		G[i].clear ();
	} 
	if (c == 11 || c == 12) {
		int diff = a[2] - a[1];
		int div = d / diff;
		if (div <= 1 || div >= n) {
			cout << "0\n";
		} else {
			cout << n - 2 * div + 1 << '\n';
		}
	} else {
		int ans = 0;
		for (int x = 1; x <= n; x++) {
			for (int y = x + 1; y <= n; y++) {
				if (a[y] - a[x] > d) break;
				G[x].push_back (y);
			}
		}
		Dijkstra ();
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dist[i][j].second == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> c >> T;
	while (T--) {
		Solve ();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5
*/
