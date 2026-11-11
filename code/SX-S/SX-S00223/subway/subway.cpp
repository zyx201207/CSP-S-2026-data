#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll w[20005];//地铁口到站厅
ll k[505];

struct node {
	ll a, t;
} a[505][20005], b[20005];
queue<node> que;
ll c, n, m, d, q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		cin >> k[i]; //第ki条线路的站数
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j].a >> a[i][j].t; //第i条线的第j站，a是哪个站，t是站厅到站台的时间
		}
	}
	for (ll i = 1; i <= q; i++) {
		ll e, y;
		cin >> e >> y;
		while (!que.empty())
			que.pop();
		ll aans = 1e9;
		que.push({e, 0});
		while (!que.empty()) {
			node x = que.back();
			que.pop();
			if (x.a == y)
				aans = min(aans, x.t);
			if (x.t > aans)
				continue;
			for (int v = 1; v <= n; v++) {
				bool f = 0;
				for (int j = 1; j <= k[v]; j++) {
					if (a[v][j].a == x.a && f == 0)
						f = 1, j = 1;
					if (f == 1 && a[v][j] .a != x.a) {
						que.push({a[v][j].a, x.t + 2});
					}
				}
			}
		}
		cout << aans*a[1][1].t / 2 + w[e] + w[y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 1 2 1 4 1
3 2 1 3 1 5 1
1 3
1 2

*/