#include<bits/stdc++.h>
#define int long long 

using namespace std;

int c, n, d, x[200005], t, p[200005];

int dfs(int k, int v) {
	//k为初始节点 
	p[k] = 1;
	int total = 0;
	for(int i = k; i <= v; i++) {
		if(i == v) total++;
		if(x[i] - x[k] <= d && p[i] != 1) {
			p[i] = 1;
			dfs(i, v);
		}
		dfs(k, v);		
	}
	return total;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin >> c >> t;
	while(t--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				if(dfs(u, v) == 2) ans++;
			}
		}
		cout << ans << endl; 
	}
	return 0;
}
