#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q;

int w[N];//m¸ö¿Ú
struct node {
	int z, xl;
};
int xlc[N];
vector<int>xl[505];
vector<int>dj[505];
vector<node>v[N];
pair<int, int>mb[100005];
int dis[N];
map<pair<int, int>, int>vis;

void spfa(int x) {
	vis.clear();
	for (int i = 1; i <= n; i++)
		dis[i] = INT_MAX;
	for (int i = 1; i <= n; i++)
		vis[ {x, i}] = 1;
	dis[x] = 0;
	queue<pair<int, int>>q;
	q.push({x, 1});
	while (q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto t : v[u.first]) {
			int d = 0;
			if (u.second != t.xl)
				d = dj[t.z][u.second];
			if (dis[u.first] + dj[t.z][t.xl] + d < dis[t.z]) {
				dis[t.z] = dis[u.first] + dj[t.z][t.xl] + d;
			}
			if (vis[ {t.z, t.xl}] == 0) {
				q.push({t.z, t.xl});
			}
		}
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int zx;
		cin >> zx;
		xlc[i] = zx;
		for (int j = 1; j <= zx; j++) {
			int z, d;
			cin >> z >> d;
			xl[i].push_back(z);
			dj[i].push_back(d);
		}
	}
	for (int i = 1; i <= n; i++) {
		int last = xl[i][0];
		for (int j = 1; j < xlc[i]; j++) {
			v[last].push_back({xl[i][j], i});
			last = xl[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		spfa(x);
		cout << dis[y] + w[x] + w[y] << "\n";
	}
	return 0;
}