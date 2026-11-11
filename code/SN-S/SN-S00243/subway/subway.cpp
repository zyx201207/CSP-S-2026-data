#include <bits/stdc++.h>
#define Inf 9223372036854000000
#define ll long long
#define Maxm 500005
#define Maxn 505

using namespace std;

struct Node {
	ll x, dis;
	bool operator <(const Node &a) const {
		return dis > a.dis;
	}
} tmp;

ll SubID, n, m, d, Q;
ll length[Maxm], res;
ll edge[Maxn][Maxn];
ll dis[Maxn][Maxn];
vector<pair<ll, ll> > lst[Maxm];
vector<pair<ll, ll> > v[Maxn];
priority_queue<Node> q;
bool vis[Maxn];

void Dijkstra(ll st) {
	while (!q.empty()) { q.pop(); }
	for (ll i = 1; i <= n; i ++) {
		vis[i] = 0, dis[st][i] = Inf;
	}
	
	dis[st][st] = 0, q.push((Node){st, 0});
	
	ll x = 0;
	while (!q.empty()) {
		tmp = q.top(), q.pop();
		x = tmp.x;
		
		if (vis[x]) { continue; }
		vis[x] = 1;
		
		for (auto pi : v[x]) {
			ll to = pi.first, lgh = pi.second;
			if (dis[st][to] > dis[st][x] + lgh) {
				dis[st][to] = dis[st][x] + lgh;
				q.push((Node){to, dis[st][to]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> SubID >> n >> m >> d >> Q;
	for (ll i = 1; i <= m; i ++) {
		cin >> length[i];
	}
	
	for (ll i = 1; i <= n; i ++) {
		for (ll j = 1; j <= n; j ++) {
			edge[i][j] = Inf;
		}
	}
	
	for (ll i = 1, k = 0; i <= n; i ++) {
		cin >> k;
		for (ll j = 1, id = 0, lgh = 0; j <= k; j ++) {
			cin >> id >> lgh;
			lst[id].emplace_back(i, lgh);
		}
	}
	
	for (ll i = 1; i <= m; i ++) {
		for (auto pi1 : lst[i]) {
			for (auto pi2 : lst[i]) {
				if (pi1 == pi2) { continue; }
				edge[pi1.first][pi2.first] = min(edge[pi1.first][pi2.first], pi1.second + pi2.second);
				edge[pi2.first][pi1.first] = min(edge[pi2.first][pi1.first], pi1.second + pi2.second);
			}
		}
	}
	
	for (ll i = 1; i <= n; i ++) {
		for (ll j = 1; j <= n; j ++) {
			if (i != j && edge[i][j] != Inf) {
				v[i].emplace_back(j, edge[i][j]);
			}
		}
	}
	
	for (ll i = 1; i <= n; i ++) {
		Dijkstra(i);
	}
	
	for (ll i = 1, x = 0, y = 0; i <= Q; i ++) {
		cin >> x >> y, res = Inf;
		for (auto pi1 : lst[x]) {
			for (auto pi2 : lst[y]) {
				res = min(res, pi1.second + pi2.second + dis[pi1.first][pi2.first]);
			}
		} cout << res + length[x] + length[y] << "\n";
	} return 0;
}
