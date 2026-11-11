#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 1e5 + 5;
int c, n, m, d, q;
vector<pair<int, int>>g[N];
vector<int>dd[N];
int w[N], kk[N];
int b[1005][1005];

struct node {
	int x, y;
};
vector<node>e[N];
int xx[N], yy[N];
int cq[505][505];
int cc[505][505];
int fdis[505];

bool cmp(node a, node b) {
	return a.x < b.x;
}
int dis[N];
int cnt[N];
bool fB;
int fBB;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	set<int>st;
	for (int i = 1; i <= n; i++) {
		cin >> kk[i];
		ans += kk[i];
		for (int j = 1; j <= kk[i]; j++) {
			int x, y;
			cin >> x >> y;
			if (!fB)
				st.insert(y);
			fBB = y;
			if (st.size() > 1) {
				fB = 1;
			}
			e[i].push_back({x, y});
		}
		sort(e[i].begin(), e[i].end(), cmp);
	}
	for (int i = 1; i <= q; i++) {
		cin >> xx[i] >> yy[i];
	}
	if (ans <= 1000) {
		for (int i = 1; i <= n; i++) {

			for (int j = 0; j < (int)e[i].size(); j++) {
				int x = e[i][j].x, y = e[i][j].y;
				cnt[x]++;
			}
			for (int j = 0; j < (int)e[i].size(); j++) {
				int x = e[i][j].x, y = e[i][j].y;

				g[x].push_back({x + m *cnt[x], y});
				g[x + m * cnt[x]].push_back({x, y});
				if (j < (int)e[i].size() - 1) {
					int xj = e[i][j + 1].x;
					g[x + m * cnt[x]].push_back({xj + m *cnt[xj], 0});
				}
				cnt[x]++;
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				//	cout << cnt[j] << " ";
				for (int k = 0; k <= d; k++) {
					dis[j + m * k] = 1e18;
				}
				//	cout << "\n";
			}
			dis[i] = 0;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
			q.push({0, i});
			while (!q.empty()) {
				auto t = q.top();
				//cout << t.second << "\n";
				q.pop();
				for (auto v : g[t.second]) {
					if (dis[t.second] + v.second < dis[v.first]) {
						dis[v.first] = dis[t.second] + v.second;
						q.push({dis[v.first], v.first});
					}
				}
			}
			for (int j = 1; j <= m; j++) {
				b[i][j] = dis[j];
			}
		}
		for (int i = 1; i <= q; i++) {
			int x = xx[i], y = yy[i];
			if (x > y)
				swap(x, y);
			cout << b[x][y] + w[x] + w[y] << "\n";
		}
		return 0;
	}
	if (!fB) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < e[i].size(); j++) {
				int x = e[i][j].x;
				dd[x].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < e[i].size(); j++) {
				for (int v : dd[e[i][j].x]) {
					if (!cq[i][v]) {
						cq[i][v] = 1;
						g[i].push_back({v, 2 * fBB});
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fdis[j] = 1e18;
			}
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
			fdis[i] = 0;
			q.push({fdis[i], i});
			while (!q.empty()) {
				auto t = q.top();
				q.pop();
				for (auto v : g[t.second]) {
					if (fdis[t.second] + v.second < fdis[v.first]) {
						fdis[v.first] = fdis[t.second] + v.second;
						q.push({fdis[v.first], v.first});
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				cc[i][j] = fdis[j];
			}
		}
		for (int i = 1; i <= q; i++) {
			int x = xx[i], y = yy[i];
			int mi = 1e18;
			for (int v : dd[x]) {
				for (int it : dd[y]) {
					mi = min(mi, cc[v][it]);
				}
			}
			cout << mi + w[x] + w[y] + fBB * 2 << "\n";
		}
	}
	return 0;
}