#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const int N = 2e6 + 5;
const int NI = 5e3 + 5;

ll n, d, ans;
ll x[N];

int tot, head[N], ver[NI * NI], nxt[NI * NI];

ll dis[N], cnt[N];

bool vis[N];

void add(int x, int y) {
	ver[++ tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void bfs(int be) {
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	
	dis[be] = 0;
	cnt[be] = 1;
	
	queue<int> q;
	q.push(be);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i];
			
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
			}
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		if (i == be) continue;
		if (cnt[i] == 2) ans ++;
	}
}

void dij(int be) {
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[be] = 0;
	cnt[be] = 1;
	
	priority_queue<pli> pq;
	pq.push({ 0, be });
	
	while (!pq.empty()) {
		pli tmp = pq.top();
		pq.pop();
		
		int u = tmp.second;
		ll d = -tmp.first;
		
		if (dis[u] != d) continue;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i];
			
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				pq.push({ -dis[v], v });
			}
			else if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
			}
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		if (i == be) continue;
		if (cnt[i] == 2) ans ++;
	}
}

void init() {
	memset(head, 0, sizeof(head));
	tot = 0;
	ans = 0;
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, T; cin >> c >> T;
	while (T --) {
		init();
		
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				if (abs(x[i] - x[j]) <= d) {
					add(i, j);
					add(j, i);
				}
			}
		}
		
		if (n <= 300) {
			ans = 0;
			for (int i = 1; i <= n; i ++) dij(i);
			
			cout << ans / 2 << '\n';
			continue;
		}
		
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			bfs(i);
		}
		
		cout << ans / 2 << '\n';
	}
	
	return 0;
}