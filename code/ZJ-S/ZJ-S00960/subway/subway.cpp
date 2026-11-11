#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10;
int c, n, m, d, q;
int ans;
struct node{
	int t, p;
};
vector<node>g[N];
vector<int>l[N][N];
int k[N], w[N];
int vis[500][2][500];
void dfs(int x, int y, int now, int f, int p){
	if(vis[x][f][p]) return;
	vis[x][f][p] = 1;
	if(x == y && f == 0){
		ans = min(ans, now);
		return;
	}
	if(f == 0){
		for(auto u : g[x])
			dfs(x, y, now + u.t, 1, u.p);
	}
	else{
		for(auto u : g[x])
			dfs(x, y, now + u.t, 0, 0);
		
		for(auto u : l[x][p])
			dfs(u, y, now, 1, p);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		int now;
		for(int j = 1; j <= k[i]; j++){
			int x, y;
			cin >> x >> y;
			g[x].push_back({y, i});
			if(j != 1) l[now][i].push_back(x);
			now = x;
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ans = 1e18;
		memset(vis, 0, sizeof vis);
		dfs(x, y, 0, 0, 0);
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}