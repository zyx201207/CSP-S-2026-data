#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

const long long N = 2010;
const long long M = 2000010;

long long n, d, x[M];
set<pair<long long, long long> > g[N];
long long dis[N][N], cnt[N][N];

void dijkstra(long long S) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
	
	for (long long i = 1; i <= n; i++) dis[S][i] = INF;
	
	q.push({0, S});
	dis[S][S] = 0;
	cnt[S][S] = 1;
	
	while (!q.empty()) {
		long long d = q.top().first, u = q.top().second;
		q.pop();
		
		if (dis[S][u] != d) continue;
		
		for (auto it : g[u]) {
			long long v = it.first, w = it.second;
 			if (dis[S][v] > dis[S][u] + w) {
				dis[S][v] = dis[S][u] + w;
				cnt[S][v] = cnt[S][u];
				q.push({dis[S][v], v});
			} else if (dis[S][v] == dis[S][u] + w) {
				cnt[S][v] = cnt[S][u] + 1;
			}
		}
	}
}

long long check(long long X, long long i) {
	return ((x[X] - x[1] > d || x[i] - x[X] > d));
}

void solve2() {
	long long diff = x[2] - x[1];
	if (d < diff) {
		cout << 0 << "\n";
		return;
	}
	
	if (d == diff) {
		cout << 0 << "\n";
		return;
	}
	
	// d > diff
	vector<long long> c;
	
	
	
	for (long long i = 4; i <= n; i++) {
		if (i % 2 == 1) {
			long long m1 = i / 2;
			long long m2 = i / 2 + 1;
			long long m3 = i / 2 + 2;
			if (check(m1, i) && check(m2, i) && !check(m1 - 1, i) && !check(m2 + 1, i)) {
				c.push_back(i);
				continue;
			}
			if (check(m2, i) && check(m3, i) && !check(m2 - 1, i) && !check(m3 + 1, i)) {
				c.push_back(i);
				continue;
			}
		} else {
			long long m1 = i / 2;
			long long m2 = i / 2 + 1;
			if (x[m1] - x[1] > d || x[i] - x[m1] > d) continue;
			if (x[m2] - x[1] > d || x[i] - x[m2] > d) continue;
			// m1 - 1 no
			if ((x[m1 - 1] - x[1] <= d && x[i] - x[m1 - 1] <= d)) continue;
			// m2 + 1 no
			if ((x[m2 + 1] - x[1] <= d && x[i] - x[m2 + 1] <= d)) continue;
			c.push_back(i);
		}
	}
	
	long long ans = 0;
	for (long long x : c) ans += n - x + 1;
	cout << ans << "\n";
}

void solve() {
	cin >> n >> d;
	for (long long i = 1; i <= n; i++)
		cin >> x[i];
	
	if (n == 1) {
		cout << 0 << "\n";
		return;
	}
	
	bool A = true;
	long long diff = x[2] - x[1];
	for (long long i = 3; i <= n; i++)
		if (x[i] - x[i - 1] != diff) {
			A = false;
			break;
		}
		
	if (A) {
		solve2();
//		cout << "A\n";
		return;
	}
		
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			if (i == j) continue;
			if (std::llabs(x[i] - x[j]) <= d) {
				g[i].insert({j, 1});
				g[j].insert({i, 1});
			}
		}
	}

	for (long long i = 1; i <= n; i++) {
		dijkstra(i);
	}	
	
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 1; j <= n; j++)
			if (cnt[i][j] == 2) ans++;
	}
	
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long C, T;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
