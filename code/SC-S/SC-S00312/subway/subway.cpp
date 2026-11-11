#define ll long long
#define _up(i, a, b, c) for (ll i = a; i <= b; i += c)
#define up(i, a, b) _up(i, a, b, 1)
#define _dn(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define dn(i, a, b) _dn(i, a, b, 1)
#define M 500005
#define N 2005
#define D 25
const ll INF = 1e15;
struct node {
	ll i, w;
};
ll c, n, m, d, q, x, y, k, w[M];
ll a[M], t[M], dist[N][N][D];
int cnt[M];
bool vis[N][N][D];
#include <bits/stdc++.h>
using namespace std;
vector<pair<node, ll>> g[N][D];

void spfa(node s) {
	up (i, 0, N - 1) {
		up (j, 0, D - 1) {
			dist[s.i][i][j] = INF;
		}
	}
	queue<node> q;
	q.push(s);
	dist[s.i][s.i][s.w] = 0;

	while (!q.empty()) {
		node u = q.front();
		q.pop();
		vis[s.i][u.i][u.w] = 0;

		for (pair<node, ll> i : g[u.i][u.w]) {
			node v = i.first;
			ll ww = i.second;

			if (dist[s.i][v.i][v.w] > dist[s.i][u.i][u.w] + ww) {
				dist[s.i][v.i][v.w] = dist[s.i][u.i][u.w] + ww;

				if (!vis[s.i][v.i][v.w]) {
					vis[s.i][v.i][v.w] = true;
					q.push(v);
				}
			}
		}
	}
}

void init() {
	cin >> c >> n >> m >> d >> q;

	up (i, 1, m) {
		cin >> w[i];
	}

	up (i, 1, n) {
		cin >> k;

		up (j, 1, k) {
			cin >> a[j] >> t[j];
			cnt[a[j]]++;
		}

		up (j, 2, k) {
			g[a[j - 1]][cnt[a[j - 1]]].push_back({{a[j], cnt[a[j]]}, 0});
			g[a[j]][cnt[a[j]]].push_back({{a[j - 1], cnt[a[j - 1]]}, 0});
		}

		up (j, 1, k) {
			g[a[j]][0].push_back({{a[j], cnt[a[j]]}, t[j]});
			g[a[j]][cnt[a[j]]].push_back({{a[j], 0}, t[j]});
		}
	}

	up (i, 1, m) {
		spfa({i, 0});
	}

	while (q--) {
		cin >> x >> y;
		cout << w[x] + w[y] + dist[x][y][0] << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	return 0;
}