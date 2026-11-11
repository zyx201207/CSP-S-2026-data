#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LOG = 15;

int c,T;
int n,k;
vector<int> g[N];
bool vis[N];
int dist[N];
int depth[N];
int up[N][LOG + 1];

void dfs(int u,int fa){
	vis[u] = false;
	
	for(int v : g[u]){
		if(!vis[v]) continue;
		if(v == fa) continue;
		
		dfs(v,u);
	}
}

void get(int u,int fa){
	up[u][0] = fa;
	
	for(int i=1;i<LOG;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}	
	
	for(int v : g[u]){
		if(v == fa) continue;
		
		depth[v] = depth[u] + 1;
		dist[v] = dist[u] + 1;
		
		get(v,u);
	}
}

int lca(int u,int v){
	if(depth[u] < depth[v]) swap(u,v);
	
	int diff = depth[u] - depth[v];
	
	for(int i=LOG-1;i>=0;i--){
		if((diff >> i) & 1){
			u = up[u][i];
		}
	}
	
	if(u == v) return u;
	
	for(int i=LOG-1;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

void solve(){
	cin >> n >> k;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	
	for(int i=1;i<=n;i++){
		vis[i] = false;
		depth[i] = 0;
		dist[i] = 0;
		
		for(int j=0;j<LOG;j++){
			up[i][j] = 0;
		}
	}
	
	get(1,0);
	
	int ans = INT_MAX;
	
	for(int i=0;i<(1<<n);i++){
		vector<int> s;
		
		int cnt = 0;
		for(int j=LOG;j>=0;j--){
			if((i >> j) & 1) cnt++;
		}
		
		if(cnt != k) continue;
		
		for(int j=LOG;j>=0;j--){
			if((i >> j) & 1){
				s.push_back(j);
				vis[j] = true;
			}
		}
		
		int tot = 0;
		for(int j=LOG;j>=0;j--){
			if(vis[j]){
				dfs(j,0);
				tot++;
			}
		}
		
		if(tot != 2) continue;
		
		int d = INT_MIN;
		
		for(int j=LOG;j>=0;j--){
			if((i >> j) & 1) continue;
			
			int o = INT_MAX;
			for(int p : s){
				int l = lca(j,p);
				
				o = min(o,dist[j] + dist[p] - 2 * dist[l]);	
			}
			
			d = max(d,o);
		}
		
		ans = min(ans,d);
	}
	
	cout << ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> T;
	while(T--){
		solve();
	}
	
	return 0;
}