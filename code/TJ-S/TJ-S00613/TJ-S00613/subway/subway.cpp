#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 505;
const int maxm = 5e5 + 515;
const int inf = 1e9;
int c, n, m, d, q;
struct node {
	int v, w;
};
int w[maxm];
int k[maxn];
vector <node> e[maxn];
int cnt = 0;
struct edge {
	int v, w;
	friend bool operator <(edge x, edge y) {
		return x.w > y.w;
	}
};
int dis[maxm], vis[maxm];
void dijkstra (int s) {
	for (int i = 0; i <= cnt; i ++) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	vis[s] = 1;
	queue <int> qq;
	qq.push(s);
	while (!qq.empty()) {
		int u = qq.front();
		qq.pop();
		vis[u] = 0;
		for (int i = 0; i < e[u].size(); i ++) {
			int v = e[u][i].v;
//			if (vis[v]) continue;
			int w = e[u][i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) qq.push(v);
			}
		}
	}
}
signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cout << " +___";
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	cnt = m;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		int a, t;
		cin >> a >> t;
		cnt ++;
		e[a].push_back({cnt, t});
		e[cnt].push_back({a, t});
		for (int j = 2; j <= k[i]; j ++) {
			cin >> a >> t;
			e[cnt].push_back({cnt + 1, 0});
			e[cnt + 1].push_back({cnt, 0});
			e[cnt + 1].push_back({a, t});
			e[a].push_back({cnt + 1, t});
			cnt ++;
		}
	}
//	for (int i = 1; i <= cnt; i ++) {
//		cout << i << " : ";
//		for (int j = 0; j < e[i].size(); j ++) {
//			cout << e[i][j].v << " " << e[i][j].w << endl;
//		}
//		cout << endl;
//	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		dijkstra(x);
//		for (int i = 1; i <= cnt; i ++) {
//			cout << dis[i] << " ";
//		}
		cout << w[x] + w[y] + dis[y] << endl;
	}
	return 0;
}


