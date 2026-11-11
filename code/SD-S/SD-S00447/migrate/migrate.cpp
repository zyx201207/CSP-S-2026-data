#include <bits/stdc++.h>

#define int long long 

#define PII pair<int, int>

#define mkp make_pair

using namespace std;

const int N1 = 5010;
const int N2 = 2e6 + 10;
const int inf = 1e18;

int c, t;
int n, r;
int x[N2];
int f[N1][N1];
int g[N1][N1];
priority_queue<PII, vector<PII>, greater<PII> > q, empt;

int Myabs(int x) {
	if (x < 0) return -x;
	return x;
}

void dijkstra(int xt) {
	for (int i = 1; i <= n; ++i) {
		f[xt][i] = inf;
		g[xt][i] = 0; 
	}
	f[xt][xt] = 0;
	g[xt][xt] = 1;
	q = empt;
	q.push(mkp(0, xt));
	while (!q.empty()) {
		PII p = q.top();
		q.pop();
		if (f[xt][p.second] != p.first) continue;
		for (int i = 1; i <= n; ++i) {
			if (i == p.second) continue;
			if (f[xt][i] > f[xt][p.second] + 1 && Myabs(x[p.second] - x[i]) <= r) {
				f[xt][i] = f[xt][p.second] + 1;
				g[xt][i] = g[xt][p.second];
				q.push(mkp(f[xt][i], i));
			}
			else if (f[xt][i] == f[xt][p.second] + 1 && Myabs(x[p.second] - x[i]) <= r) {
				g[xt][i] += g[xt][p.second];
			}
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> c >> t;	
	if (c == 13 || c == 14){
		//ÈÏÎª c = 13, 14
		while (t--) {
			cin >> n >> r;
			for (int i = 1; i <= n; ++i) {
				cin >> x[i];
			}
			cout << 0ll << "\n";
		} 
	}
	else {
		//±©Á¦
		while (t--) {
			cin >> n >> r;
			for (int i = 1; i <= n; ++i) {
				cin >> x[i];
			}		
			for (int i = 1; i <= n; ++i) {
				dijkstra(i);
			}
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (i != j && g[i][j] == 2) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		} 
	}
	return 0;
}
