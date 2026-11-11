#include <bits/stdc++.h>
#define ll long long
#define il inline
#define pb push_back
using namespace std;
const ll N = 505, M = 5e5+5;

ll c, n, m, d, q, ax, tx, xx, yy, k[N], w[M];

struct Edge{
	ll to, val;
};
vector <Edge> e[50000005];
bool vis[N];
ll dis[N][N];
void zdl(ll st) {
	for (int i = 0; i < N; i++) dis[st][i] = 1e18;
	memset(vis, 0, sizeof(vis));
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	pq.push(st);
	dis[st][st] = 0;
	while (!pq.empty()) {
//		cout << "xunhuan\n";
		ll now = pq.top();
		pq.pop();
		for (Edge i : e[now]) {
//			cout << "i:" << i.to << ' ' << i.val << '\n';

			if (dis[st][i.to] > dis[st][now] + i.val)
				dis[st][i.to] = dis[st][now] + i.val;
			if (!vis[i.to]) {
				pq.push(i.to);
				vis[i.to] = 1;
			}
		}
	}
}

vector <Edge> e2[500000];
bool vis2[N];
ll dis2[N][N];
void zdl2(ll st) {
	for (int i = 0; i < N; i++) dis2[st][i] = 1e18;
	memset(vis2, 0, sizeof(vis2));
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	pq.push(st);
	dis2[st][st] = 0;
	while (!pq.empty()) {
//		cout << "xunhuan\n";
		ll now = pq.top();
		pq.pop();
		for (Edge i : e2[now]) {
//			cout << "i:" << i.to << ' ' << i.val << '\n';

			if (dis2[st][i.to] > dis2[st][now] + i.val)
				dis2[st][i.to] = dis2[st][now] + i.val;
			if (!vis2[i.to]) {
				pq.push(i.to);
				vis2[i.to] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	if (c >= 7 && c <= 11) {
		for (int i = 1; i <= n; i++){
			cin >> k[i];
			if (k[i] == 1) continue;
			ll qq, ww, ee, rr;
			cin >> qq>>ww>>ee>>rr;
			e2[qq].pb({ee, ww+rr});
			e2[ee].pb({qq, ww+rr});
		}
		for (int i = 1; i <= m; i++) {
			zdl2(i);
		}
		for (int i = 1; i <= q; i++) {
			cin >> xx >> yy;
			cout << dis[xx][yy] + w[xx] + w[yy] << '\n';
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		ll lst = 0;
		for (int j = 1; j <= k[i]; j++) {
			cin >> ax >> tx;
			e[ax+m*i].pb({ax, tx});
			e[ax].pb({ax+m*i, tx});
			if (j != 1) {
				e[ax+m*i].pb({lst+m*i, 0});
				e[lst+m*i].pb({ax+m*i, 0});
			}
			lst = ax;
		}
	}

	for (int i = 1; i <= m; i++) {
		zdl(i);
	}

	for (int i = 1; i <= q; i++) {
		cin >> xx >> yy;
		cout << dis[xx][yy] + w[xx] + w[yy] << '\n';
	}


//	for (int i = 1; i <= m; i++) {
//		ll u, v, ww;
//		cin >> u >> v >> ww;
//		e[u].pb({v, ww});
//		e[v].pb({u, ww});
//	}
//	zdl(1);
//
//	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';

//	cout << '\n';
//	for (int i = 1; i <= n; i++) {
//		cout << "i="<<i<<":  ";
//		for (auto j : e[i]) cout << "{"<<j.to<<","<<j.val<<"}" << ' ';
//		cout << '\n';
//	}

	return 0;
}


/*
5 6
1 4 3
2 3 2
2 4 1
2 5 1
3 4 1
4 5 5


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/