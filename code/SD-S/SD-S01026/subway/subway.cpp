//不是真考图论 
//time 15:54 不是俩题咋都是图论，我吓哭了 
//不会SPFA我直接哭了 
#include<bits/stdc++.h>
using namespace std;
const int M = 5E5 + 10;
const int N = 500 + 10;
int w[M], klen[N];
vector<pair<int, int> > k[N];
int dfs(int u, int come) {
	for(int v : k[u]) {
		if(v != come) {
			dfs(v, u);
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> klen[i];
		for(int j = 1; j <= klen[i]; j++) {
			int a, b; cin >> a >> b;
			k[i].push_back({a, b});
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		dfs(x, y);
		cout << w[x] + w[y] + dfs(x, 0);
		//这题给了 
	}
	return 0;
}

