#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, inf = 1e8;
int n,k,x,y;
vector <int> E[N];
bool vis[N];
int dis[100][100];
bool in[N];
int p[N],ans;
void dfs0 (int u, int fa){
	vis[u] = 1;
	for (auto v : E[u]){
		if (!vis[v] && v != fa && in[v]) dfs0 (v, u);
	}
}
void dfsdis (int s, int u, int dt){
	dis[s][u] = dt;
	for (auto v : E[u]){
		if (dis[s][v] != inf) return ;
		dfsdis (s, v, dt + 1);
	}
}
void checkmin(){
	for (int i = 1; i <= n; i++) vis[i] = 0;
	dfs0 (p[1], 0);
	int cnt = 0;
	for (int i = 2; i <= k; i++){
		if (!vis[p[i]]) dfs0 (p[i], 0), cnt++;
		if (cnt >= 2) return ;
	}
	int res2 = 0;
	for (int i = 1; i <= n; i++){
		int res = inf;
		for (int j = 1; j <= k; j++){
			res = min (res, dis[i][p[j]]);
		}
		res2 = max (res2, res);
	}
	ans = min (ans, res2);
}
void bao (int cnt){
	if (cnt > k){
		checkmin();
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (!in[i]){
			p[cnt] = i;
			in[i] = 1;
			bao (cnt + 1);
			in[i] = 0;
		}
	}
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		cin >> x >> y;
		E[x].push_back (y);
		E[y].push_back (x);
	}
	ans = inf;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++){
		dfsdis (i, i, 0);
	}
	bao (1);
	cout << ans << '\n';
} 
int main(){
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C0,T;
	cin >> C0 >> T;
	while (T--) solve(); 
	return 0;
}
