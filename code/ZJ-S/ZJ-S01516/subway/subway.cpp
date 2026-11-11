#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

const long long N = 510;
const long long M = 5e5 + 10;

long long c, n, m, d, q, w[M], k[N];
vector<long long> a[N], t[N];
vector<pair<long long, long long> > g[M];
long long tot;

long long dijkstra(long long S, long long T) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
	vector<long long> dis(tot + 1, INF);
	
	q.push({0, S});
	dis[S] = 0;
	
	while (!q.empty()) {
		long long d = q.top().first, u = q.top().second;
		q.pop();
		
		if (dis[u] != d) continue;
		
		for (long long j = 0; j < (long long)g[u].size(); j++) {
			long long v = g[u][j].first, w = g[u][j].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
	
	return dis[T];
}

void solve1_8() {
	tot = m;
	for (long long i = 1; i <= n; i++) {
		vector<pair<long long, long long> > tmp;
		for (long long j = 1; j <= k[i]; j++) tmp.push_back({a[i][j], t[i][j]});
		sort(tmp.begin(), tmp.end());
		
		tot++;
		g[tmp[0].first].push_back({tot, tmp[0].second});
		g[tot].push_back({tmp[0].first, tmp[0].second});		
		
		long long lst = tot;
		for (long long j = 1; j < k[i]; j++) {
			tot++;
			g[tmp[j].first].push_back({tot, tmp[j].second});
			g[tot].push_back({tmp[j].first, tmp[j].second});
			g[tot].push_back({lst, 0});
			g[lst].push_back({tot, 0});
			lst = tot;
		}
	}	

	while (q--) {
		long long S, T;
		cin >> S >> T;
		cout << dijkstra(S, T) + w[S] + w[T] << "\n";
	}
}

long long ans[1010][1010];

long long dijkstra2(long long S) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
	vector<long long> dis(tot + 1, INF);
	
	q.push({0, S});
	dis[S] = 0;
	
	while (!q.empty()) {
		long long d = q.top().first, u = q.top().second;
		q.pop();
		
		if (dis[u] != d) continue;
		
		for (long long j = 0; j < (long long)g[u].size(); j++) {
			long long v = g[u][j].first, w = g[u][j].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
	
	for (long long i = 1; i <= m; i++)
		ans[S][i] = dis[i];
}

void solve9_11() {
	tot = m;
	for (long long i = 1; i <= n; i++) {
		vector<pair<long long, long long> > tmp;
		for (long long j = 1; j <= k[i]; j++) tmp.push_back({a[i][j], t[i][j]});
		sort(tmp.begin(), tmp.end());
		
		tot++;
		g[tmp[0].first].push_back({tot, tmp[0].second});
		g[tot].push_back({tmp[0].first, tmp[0].second});		
		
		long long lst = tot;
		for (long long j = 1; j < k[i]; j++) {
			tot++;
			g[tmp[j].first].push_back({tot, tmp[j].second});
			g[tot].push_back({tmp[j].first, tmp[j].second});
			g[tot].push_back({lst, 0});
			g[lst].push_back({tot, 0});
			lst = tot;
		}
	}	

	for (long long i = 1; i <= m; i++) dijkstra2(i);

	while (q--) {
		long long S, T;
		cin >> S >> T;
		cout << ans[S][T] + w[S] + w[T] << "\n";
	}	
}

long long bfs(long long S, long long T) {
	queue<long long> q;
	vector<long long> dis(tot + 1, INF);
	
	q.push(S);
	dis[S] = 0;
	
	while (!q.empty()) {
		long long u = q.front(); q.pop();
		for (long long j = 0; j < (long long)g[u].size(); j++) {
			long long v = g[u][j].first, w = g[u][j].second;
			if (dis[v] == INF) {
				dis[v] = dis[u] + w;
				q.push(v);
			}
		}
	}
	
	return dis[T];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
		cin >> w[i];
		
	long long sum = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> k[i];
		sum += k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (long long j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	if (n <= 200 && sum <= 400 && d <= 20 && q <= 200) {
		solve1_8();
		return 0;
	}
	
	bool A = true;
	for (long long i = 1; i <= n; i++) {
		if (k[i] > 2) {
			A = false;
			break;
		}
	}
	
	if (n <= 500 && sum <= 1000 && d <= 20 && q <= 100000 && A) {
		solve9_11();
		return 0;
	}
	
	return 0;
}
