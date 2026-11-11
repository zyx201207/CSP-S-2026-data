#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5;

int c, t, n, k, fa[N];

vector <int> g[N];

bool is[N];
int d[N];
int q[N], l, r;

void bfs() {
	for (int i = 1; i <= n; ++ i ) d[i] = 1e18;
	l = 1, r = 0;
	for (int i = 1; i <= n; ++ i )
	    if (is[i]) {
	    	d[i] = 0;
	    	q[ ++ r] = i;
		}
	
	while (l <= r) {
		int u = q[l ++ ];
		for (int v : g[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q[ ++ r] = v;
				fa[v] = u;
			}
		}
	}
	return;
}

int Get (int x, int y) {
	for (int i = 1; i <= n; ++ i ) is[i] = false;
	is[x] = is[y] = true;
	for (int now = 1; now <= k - 2; ++ now ) {
		bfs();
		int mx = 0;
		for (int i = 1; i <= n; ++ i ) mx = max(mx, d[i]);
		int u = 0;
		for (int i = 1; i <= n; ++ i ) 
	        if (d[i] == mx)
	            u = i;
	        
	    while (!is[fa[u]]) u = fa[u];
	    is[u] = true;
	}
	bfs();
	int mx = 0;
	for (int i = 1; i <= n; ++ i ) mx = max(mx, d[i]);
	return mx;
}

signed len[1005][1005];

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t -- ) {
		cin >> n >> k;
	//	n = 100, k = 100;
		for (int i = 1; i <= n; ++ i ) g[i].clear();
		for (int i = 1, u, v; i < n; ++ i ) {
			cin >> u >> v;
		//	u = i + 1, v = i;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (n > 100 && k == 2) {
			for (int i = 1; i <= n; ++ i ) {
				is[i] = true;
				bfs();
				for (int j = 1; j <= n; ++ j ) len[i][j] = d[j];
				is[i] = false;
			}
			signed res = 1e9;
			for (signed x = 1; x <= n; ++ x )
			    for (signed y = x + 1; y <= n; ++ y ) {
			    	signed mx = 0;
			    	for (signed i = 1; i <= n; ++ i ) mx = max(mx, min(len[x][i], len[y][i]));
			    	res = min(res, mx);
				}
			    
			cout << res << '\n';
			continue;
		}
	//	if (n > 200) continue;//cout << t << '\n';
 		int res = 1e18;
		for (int x = 1; x <= n; ++ x )
		    for (int y = x + 1; y <= n; ++ y ) {
		    	res = min(res, Get(x, y));
			}
		    
		cout << res << '\n';
	}
	
	return 0;
}
