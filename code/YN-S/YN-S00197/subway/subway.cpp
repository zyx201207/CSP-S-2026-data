#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5;
long long c, n, m, d, q, w[M], k[N], ans, l, r, dis[N][N];
bool used[N][M];

struct nod {
	int a, t;
};
map<long long, map<long long, nod>>p;
map<long long, map<long long, long long>>wei;
vector<int>e[N], g[M], sh;

struct no {
	int v, w;
};

struct ee {
	long long x, co;
	friend bool operator<(ee a, ee b) {
		return a.co < b.co;
	}
};
vector<no>ed[N];

void dij(int x) {
	priority_queue<ee>pq;
	pq.push({x, 0});
	memset(dis[x], 0x3f, sizeof(dis[x]));
	dis[x][x] = 0;
	while (!pq.empty()) {
		ee tmp = pq.top();
		pq.pop();
		int u = tmp.x, co = tmp.co;
		for (int i = 0; i < ed[u].size(); i++) {
			int v = ed[u][i].v, w = ed[u][i].w;
			if (dis[x][v] > dis[x][u] + w) {
				dis[x][v] = dis[x][u] + w;
				pq.push({v, dis[x][v]});
			}
		}
	}
}

int main() {
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
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, t;
			cin >> a >> t;
			p[i][j] = {a, t};
			g[a].push_back(i);
			if (g[a].size() > 1) {
				sh.push_back(a);

			}
			wei[i][a] = j;
			e[i].push_back(a);
			used[i][a] = 1;
		}
	}
	for (auto v : sh) {
		for (auto i : g[v]) {
			for (auto j : g[v]) {
				if (i == j)
					continue;
				ed[i].push_back({j, p[i][wei[i][v]].t + p[j][wei[j][v]].t});
				ed[j].push_back({i, p[i][wei[i][v]].t + p[j][wei[j][v]].t});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dij(i);
//		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
	}
	while (q--) {
		cin >> l >> r;
		ans = 1e18;
		for (auto i : g[l]) {
			for (auto j : g[r]) {
				int ccc = dis[i][j] + p[i][wei[i][l]].t + p[j][wei[j][r]].t;
				if (ans > ccc) {
					ans = ccc;
				}
			}
		}
		cout << ans + w[l] + w[r] << "\n";
	}
	return 0;
}
