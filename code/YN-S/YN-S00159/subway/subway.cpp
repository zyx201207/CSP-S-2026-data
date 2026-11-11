#include <bits/stdc++.h>
#define maxn 500050
using namespace std;
int c, n, m, d, q, xst, yen, dot;
int dis[maxn], h[maxn], net[maxn], w[maxn], to[maxn], cnt;
bool vis[maxn];
priority_queue<pair<int, int> >que;

void add(int a, int b, int v) {
	net[++cnt] = h[a];
	w[cnt] = v;
	to[cnt] = b;
	h[a] = cnt;
}

void dijistra() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	que.push(make_pair(0, xst));
	dis[xst] = 0;
	while (que.size()) {
		int dd = que.top().second;
		que.pop();
		if (vis[dd])
			continue;
		vis[dd] = 1;
		for (int i = h[dd]; i; i = net[i]) {
			if (dis[dd] + w[i] < dis[to[i]]) {
				dis[to[i]] = dis[dd] + w[i];
				que.push(make_pair(-dis[to[i]], to[i]));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		add(i, i + m, t);
		add(i + m, i, t);
	}
	dot = 2 * m;
	for (int i = 1; i <= n; i++) {
		int numm;
		cin >> numm;
		int xx, tt, pathbe;
		cin >> xx >> tt;
		add(xx + m, ++dot, tt);
		add(dot, xx + m, tt);
		pathbe = dot;
		for (int j = 2; j <= numm; j++) {
			int xij, tij;
			cin >> xij >> tij;
			add(xij + m, ++dot, tij);
			add(dot, xij + m, tij);
			add(pathbe, dot, 0);
			add(dot, pathbe, 0);
		}
	}
	for (int i = 1; i <= q; i++) {
		int p;
		cin >> p >> yen;
		if (i == 1 || p != xst) {
			xst = p;
			dijistra();
		}
		cout << dis[yen] << "\n";
	}
	return 0;
}