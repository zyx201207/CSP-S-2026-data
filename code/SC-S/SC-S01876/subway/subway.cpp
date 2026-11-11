#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const int N = 505;
const int M = 5e5 + 5;
const int MI = 1e3 + 5;
const int TOT = 6e6 + 5;
const int Q = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll c, n, m, d, q;
ll w[M], k[N];

bool sol[N];

ll pos[N * MI];

int tot, head[N * MI], ver[TOT], nxt[TOT];
ll edg[TOT], dis[N * MI];

ll vec[MI][MI];

void add(int x, int y, ll z) {
	ver[++ tot] = y;
	nxt[tot] = head[x];
	edg[tot] = z;
	head[x] = tot;
}

void dij(int be) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pli> pq;
	
	for (int i = 1; i <= n; i ++) {
		dis[(i - 1) * m + be] = pos[(i - 1) * m + be];
		pq.push({ -dis[(i - 1) * m + be], (i - 1) * m + be });
	}
	
	while (!pq.empty()) {
		pli tmp = pq.top();
		pq.pop();
		
		int u = tmp.second;
		ll d = -tmp.first;
		
		if (dis[u] != d) continue;
		if (dis[u] == INF) continue;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i];
			
			if (dis[u] + edg[i] < dis[v]) {
				dis[v] = dis[u] + edg[i];
				pq.push({ -dis[v], v });
			}
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		ll ans = INF; 
		for (int j = 1; j <= n; j ++) {
			int id = (j - 1) * m + i;
			ans = min(ans, dis[id] + pos[id]);
		}
		
		vec[be][i] = ans + w[be] + w[i];
	}
}

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	
	vector<int> tmp;

	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		
		tmp.clear();
		for (int j = 1; j <= k[i]; j ++) {
			ll a, t; cin >> a >> t;
			
			int id = (i - 1) * m + a;
			pos[id] = t;
			tmp.push_back(id);
		}
		
		for (int j = 0; j < int(tmp.size()); j ++) {
			for (int id = j + 1; id < int(tmp.size()); id ++) {
				add(tmp[j], tmp[id], 0);
				add(tmp[id], tmp[j], 0);
			}
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int id = j + 1; id <= n; id ++) {
				int x = (j - 1) * m + i, y = (id - 1) * m + i; 
				add(x, y, pos[x] + pos[y]);
				add(y, x, pos[y] + pos[x]);
			}
		}
	}
	
	for (int i = 1; i <= q; i ++) {
		int x, y; cin >> x >> y;
		if (sol[x] == false) {
			dij(x);
			sol[x] = true;
		}
		
		cout << vec[x][y] << '\n';
	}
	
	return 0;
}