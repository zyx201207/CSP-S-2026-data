#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 503;
const int M = 5e5 + 3;

const ll kMax = 9e18;

int c, n, m, d, q;
int w[M], k[N];
vector<pii> lines[M];
vector<pii> nodes[N];

//bool isLineInclude[N][M];
map<int, int> isLineInclude[N];

struct Edge {
	int v, w;
};
vector<Edge> e[N];

ll dist[N][N];

int temp1[M][2];

signed main() {
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (7 <= c && c <= 11) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dist[i][j] = (i == j ? 0ll : kMax);
			}
		}
		for (int i = 1; i <= n; i++) {
			int node1, node2, t1, t2;
			cin >> k[i] >> node1 >> t1;
			if (k[i] == 1) continue;
			cin >> node2 >> t2; 
			ll w = t1 + t2;
			dist[node1][node2] = dist[node2][node1] = w;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= j) {
					dist[i][j] = dist[j][i]; continue;
				}
				for (int k = 1; k <= m; k++) {
					if (k == i || k == j || dist[i][k] == kMax || dist[k][j] == kMax) continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		for (int x, y; q--;) {
			cin >> x >> y;
			cout << dist[x][y] + w[x] + w[y] << '\n';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1, nodeId, t; j <= k[i]; j++) {
			cin >> nodeId >> t;
			if (k[i] == 1) {
				break; ///////////
			}
			lines[nodeId].push_back(make_pair(i, t));
			nodes[i].push_back(make_pair(nodeId, t));
			isLineInclude[i][nodeId] = t;
		}
	}
	if (c == 20 || c == 21) {
		int minCrossTime = 2e9 + 1;
		for (int i = 1; i <= m; i++) {
			temp1[i][0] = temp1[i][1] = 0;
			for (pii p : lines[i]) {
				temp1[i][p.first - 1] = p.second;
			}
			if (temp1[i][0] && temp1[i][1]) {
				minCrossTime = min(minCrossTime, temp1[i][0] + temp1[i][1]);
			}
		}
		for (int _q = 1, node1, node2; _q <= q; _q++) {
			cin >> node1 >> node2;
			ll ans = kMax;
			if (temp1[node1][0] && temp1[node2][0]) ans = min(ans, (ll)temp1[node1][0] + temp1[node2][0]);
			if (temp1[node1][1] && temp1[node2][1]) ans = min(ans, (ll)temp1[node1][1] + temp1[node2][1]);
			if (temp1[node1][0] && temp1[node2][1]) ans = min(ans, (ll)temp1[node1][0] + temp1[node2][1] + minCrossTime);
			if (temp1[node1][1] && temp1[node2][0]) ans = min(ans, (ll)temp1[node1][1] + temp1[node2][0] + minCrossTime);
			cout << ans + w[node1] + w[node2] << '\n';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		//cerr << i << " / " << n << '\n';
		for (int j = 1; j <= n; j++) {
			dist[i][j] = kMax;
			if (i == j) dist[i][j] = 0;
			if (j <= i) continue;
			int minTimeCost = 2e9 + 1;
			for (pii p : nodes[j]) {
				int t2 = isLineInclude[i][p.first];
				if (t2 > 0) {
					minTimeCost = min(minTimeCost, p.second + t2);
				}
			}
			if (minTimeCost < int(2e9 + 1)) {
				e[i].push_back(Edge{j, minTimeCost});
				e[j].push_back(Edge{i, minTimeCost});
				//cerr << "# lines: " << i << " - " << j << ": " << minTimeCost << '\n';
				
				dist[i][j] = dist[j][i] = minTimeCost;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//dist[i][i] = dist[j][j] = 0; ///
			if (i >= j) {
				dist[i][j] = dist[j][i];
				continue;
			}
			for (int k = 1; k <= n; k++) {
				if (dist[i][k] == kMax || dist[k][j] == kMax || k == i || k == j) continue;
				//cerr << "! " << k << '\n';
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					//cerr << "!! " << dist[i][k] << " + " << dist[k][j] << " < " << dist[i][j] << '\n';
					dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];
					//cerr << i << " -> " << k << " -> " << j << '\n';
				}
			}
			//cerr << "## minTime: " << i << " - " << j << ": " << dist[i][j] << '\n';
		}
	}
	for (int _q = 1, node1, node2; _q <= q; _q++) {
		cin >> node1 >> node2;
		ll res = kMax;
		for (pii p1 : lines[node1]) {
			for (pii p2 : lines[node2]) {
				res = min(res, p1.second + p2.second + dist[p1.first][p2.first]);
				//cerr << "* " << p1.first << "," << p2.first << ": " << p1.second << " + " << p2.second << " + " << dist[p1.first][p2.first] << " = " << p1.second + p2.second + dist[p1.first][p2.first] << '\n';
			}
		}
		cout << res + w[node1] + w[node2] << '\n';
		//cerr << "# " << w[node1] << " + " << res << " + " << w[node2] << '\n';
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
0 3 10 20 4
0 0 0 0 0 0 0 0 0 0
6 1 3 2 2 3 1 4 5 9 2 10 8
8 1 4 2 6 3 2 4 4 5 3 6 7 7 2 8 5
6 5 4 6 9 7 6 8 8 9 6 10 1
1 10
6 9
3 8
2 6
*/

/*
22 2 8 20 5
0 0 0 0 0 0 0 0
6 1 1 2 2 3 6 4 2 5 5 6 8
6 1 5 2 7 3 2 4 3 7 9 8 1
1 2
4 5
3 4
1 7
5 8
*/

/*
// PaperLily Chaper 2!!!
*/
