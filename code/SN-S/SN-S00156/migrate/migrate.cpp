#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6+6;
const int INF = 1e18+18;

int n, d;
int a[N];
vector<int> g[N];
int ans;

int dis[N], vis[N];
void bfs(int s){
	memset(dis, 0x7fLL, sizeof dis);
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = 1;
		for(int v : g[u]){
			if(vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u]+1;
			q.push(v);
		}
	}
}

int res[N];
void dfs(int u){
	for(int v : g[u]){
		if(dis[v] == dis[u]+1) res[v]++;
		dfs(v);
	}
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int C, T; cin >> C >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		int l, r;
		a[0] = -INF;
		for(int r = 1; r <= n; r++){
			cin >> a[r];
			l = r-1;
			while(l >= 1 && a[r]-a[l] <= d){
				g[l].push_back(r);
				l--;
			}
		}
		ans = 0;
		for(int u = 1; u <= n-1; u++){
			bfs(u);
			memset(res, 0, sizeof res);
			dfs(u);
			for(int j = u; j <= n; j++)
				ans += res[j]-1;
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

