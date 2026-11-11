#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x, id;
};

int c, t, col;
int n, m;
long long d;
long long x[5010];
int vis[5010];
vector<edge> g[5010];

bool dfs(int x, int last){
	vis[x] = col;
	bool ret = 0;
	for (auto u : g[x]){
		if (u.id == last) continue;
		if (vis[u.x] == col && u.x == col) return true;
		ret |= dfs(u.x, u.id);
	}
	return ret;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		m = 0;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				if (abs(x[i]-x[j]) <= d){
					++m;
					g[i].push_back({j, m});
					g[j].push_back({i, m});
				}
			}
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (vis[i] == 0){
				col = i;
				ans += dfs(i, 0);
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
