#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e3+5, inf = 1e18;
int c, T, n, d, a[N], dis[N][N], mn[N], cnt[N]; vector<int> g[N];
inline int slv(int s){
	for (int i = s; i <= n; i++) mn[i] = inf, cnt[i] = 0;
	for (int i = s; i <= n; i++) for (int j = s; j < i; j++) dis[i][j] = inf; // u / pre[u]
	priority_queue<pair<int,int> > q; q.push({0, s}); cnt[s] = 1, mn[s] = 0;
	while (!q.empty()){
		int p = q.top().first, u = q.top().second; q.pop(); if (mn[u] < p) continue;
		for (int v : g[u]) if (mn[v] > p+1) mn[v] = dis[v][u] = p+1, q.push({p+1, v}); else if (mn[v] == p+1) dis[v][u] = p+1;
	} int ans = 0;
	//cout << s << "\n";
	for (int i = s; i <= n; i++) if (mn[i] != inf){
//		for (int j = s; j < i; j++) cnt[i] += mn[i] == dis[i][j];//, cout << " -  - " << j << " " << (dis[i][j] == inf ? -1 : dis[i][j]) << "\n"; 
		for (int j = s; j < i; j++) if (mn[i] == dis[i][j]) cnt[i] += cnt[j];
		if (cnt[i] == 2) ans++; 
	}
	return ans;
}
signed main(){
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	cin >> c >> T; while (T--){
		cin >> n >> d; //cout << n << "\n";
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) if (a[j]-a[i] <= d) g[i].push_back(j);
		int ans = 0; for (int i = 1; i <= n; i++) ans += slv(i); cout << ans << "\n";
		for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}

