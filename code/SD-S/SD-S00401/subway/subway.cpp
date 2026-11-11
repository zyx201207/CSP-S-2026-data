#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5;

int c, n, m, d, q, w[N], f[505][505];

int k[N];
vector <int> a[505];
vector <int> t[505];
vector <pair <int, int> > g[N];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i ) cin >> w[i];
	for (int i = 1; i <= n; ++ i ) {
		cin >> k[i];
		for (int j = 0; j < k[i]; ++ j ) {
			int A, T;
			cin >> A >> T;
			a[i].push_back(A);
			t[i].push_back(T);
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++ i ) f[i][i] = 0;
	for (int i = 1; i <= n; ++ i ) {
		for (int j = 0; j < k[i]; ++ j ) {
			g[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; ++ i )
	    for (auto x : g[i])
	        for (auto y : g[i]) {
	        	int u = x.first, v = y.first;
	        	int W = x.second + y.second;//cout << "K" << i << ' ' << u << ' ' << v << ' ' << W << endl;
	        	f[u][v] = min(f[u][v], W);
			}
    
    for (int k = 1; k <= n; ++ k )
        for (int i = 1; i <= n; ++ i )
            for (int j = 1; j <= n; ++ j )
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        
    while (q -- ) {
    	int x, y;
    	cin >> x >> y;
    	int res = 1e18;
    	for (auto i : g[x])
    	    for (auto j : g[y]) {
    	        int u = i.first, v = j.first;
				int W = i.second + j.second;//cout << "K" << u << ' ' << v << ' ' << 
				res = min(res, w[x] + w[y] + W + f[u][v]);
			}
		
		cout << res << '\n';
	}
    
	return 0;
}
