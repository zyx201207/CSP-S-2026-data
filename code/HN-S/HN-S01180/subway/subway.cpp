#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5, M = 5e5 + 5, inf = 2e18;
int op,n,m,d,q,k,x,v,y;
int w[M],dis[N][N];
struct node {
	int x,w;
};
vector<node> c[M],s[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> op >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> x >> v;
			c[x].push_back({i, v});
			s[i].push_back({x, v}); 
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			dis[i][j] = i == j? 0: inf;
	for (int u = 1; u <= n; u++) {
		for (auto i:s[u]) 
			for (auto j:c[i.x])	
				dis[u][j.x] = min(dis[u][j.x], i.w + j.w);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		cin >> x >> y;
		int ans = inf;
		for (auto i:c[x]) 	
			for (auto j:c[y])
				ans = min(ans, dis[i.x][j.x] + i.w + j.w);
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7  
1 3 
1 2 

*/

