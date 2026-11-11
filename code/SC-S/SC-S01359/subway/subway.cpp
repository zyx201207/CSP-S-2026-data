#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,j,k) for(int i=j;i<=k;i++)
int c, n, m, d, q;
const int N = 505;
const int M = 5e5+1000;
vector<int>a[N], t[N];
vector<int>where[M];
int w[M];
int dis[N][N];
bool can_reach[N][N];
pair<int, int> where_to_appear[25];
unordered_map<int, int> sta_to_wal[M];
vector<pair<int, int>>adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	F(i, 1, m) cin >> w[i];
	F(i, 1, n) {
		int K ;
		cin >> K;
		a[i].resize(K + 1);
		t[i].resize(K + 1);
		F(j, 1, K) {
			cin >> a[i][j] >> t[i][j];
			sta_to_wal[i][a[i][j]] = t[i][j];
			where[a[i][j]].emplace_back(i);
		}
	}
	F(i, 1, m) {
		int cnt = 0;
		for (int appear : where[i]) {
			where_to_appear[++cnt] = {appear, sta_to_wal[appear][i]};
		}
		F(I, 1, cnt) {
			F(J, 1, cnt) {
				int u = where_to_appear[I].first;
				int v = where_to_appear[J].first;
				if (u == v)continue;
				int wal = where_to_appear[I].second + where_to_appear[J].second;
				adj[u].emplace_back(v, wal);
				adj[v].emplace_back(u, wal);
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	F(s, 1, n) {
		dis[s][s] = 0;
		pq.emplace(dis[s][s], s);
		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			if (can_reach[s][u])continue;
			can_reach[s][u] = 1;
			for (pair<int, int>E : adj[u]) {
				int v = E.first;
				int w = E.second;
				if (dis[s][v] > dis[s][u] + w) {
					dis[s][v] = dis[s][u] + w;
					if (!can_reach[s][v])pq.emplace(dis[s][v], v);
				}
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = LLONG_MAX;
		for (int join : where[x]) {
			for (int ending : where[y]) {
				if (!can_reach[join][ending])continue;
				ans = min(ans, w[x] + w[y] + sta_to_wal[join][x] + sta_to_wal[ending][y] + dis[join][ending]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}