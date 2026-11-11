#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int inf = 1e18;
int c, n, m, d, q;
int w[M], a[N][N], t[N][N];
int f[N][N];
vector<pll> g[M];

//n个点，m条边，每个点经过k条边
//从地铁口走到站厅要wi时间 从站厅走到第j条线路要tji时间
//求边x到边y的最短路

void solve() {
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin>>k;
		for(int j = 1; j <= k; j++) {
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i, t[i][j]});
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = inf;
		}
		f[i][i] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(auto nu : g[i]) {
			int u = nu.first, wu = nu.second;
			for(auto nv : g[i]) {
				int v = nv.first, wv = nv.second;
				if(u == v) continue;
				f[u][v] = f[v][u] = min(f[u][v], wu + wv);
			}
		}

	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	while(q--) {
		int x, y, ans = inf;
		cin>>x>>y;
		for(auto nu : g[x]) {
			int u = nu.first, wu = nu.second;
			for(auto nv : g[y]) {
				int v = nv.first, wv = nv.second;
				if(u == v) ans = min(ans, wu + wv);
				else ans = min(ans, wu + wv + f[u][v]);
			}
		}
		cout<<w[x] + w[y] + ans<<"\n";
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}


//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

